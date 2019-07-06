#pragma once

#include <future>
#include <list>
#include <optional>
#include <vector>

template <class WorkResult, class WorkInput>
struct WorkUnit {
    std::function<WorkResult(WorkInput)> fn;
    WorkInput input;

    std::promise<WorkResult> promise;
};

template <class WorkResult, class WorkInput>
class WorkQueue {
    using WU = WorkUnit<WorkResult, WorkInput>;

    std::mutex _mutex;
    std::list<WU> _work;
    bool _done = false;

public:
    void push(WU w) {
        std::lock_guard<std::mutex> l(_mutex);
        _work.push_back(std::move(w));
    }

    std::optional<WU> pop() {
        std::lock_guard<std::mutex> l(_mutex);
        if (_work.empty()) {
            return {};
        }
        WU i(std::move(_work.front()));
        _work.pop_front();
        return {std::move(i)};
    }

    void setDone() {
        _done = true;
    }

    bool done() {
        std::lock_guard<std::mutex> l(_mutex);
        return _work.empty() && _done;
    }
};

namespace {

template <class WQ>
void threadFn(WQ* wq) {
    while (true) {
        auto workUnit = wq->pop();
        if (!workUnit) {
            if (wq->done()) {
                return;
            }

            std::this_thread::sleep_for(std::chrono::milliseconds(5));
            continue;
        }

        workUnit->promise.set_value(workUnit->fn(workUnit->input));
    }
}
}

template <class WorkResult, class WorkInput>
class ThreadPool {
    using WQ = WorkQueue<WorkResult, WorkInput>;
    
    WQ _queue;

    std::vector<std::thread> _threads;

public:
    ThreadPool(int n) {
        for (int i = 0; i < n; ++i) {
            _threads.push_back(std::thread(threadFn<WQ>, &_queue));
        }
    }

    std::future<WorkResult> scheduleWork(std::function<WorkResult(WorkInput)> fn, WorkInput input) {
        std::promise<WorkResult> promise;
        std::future<WorkResult> future = promise.get_future();
        _queue.push(WorkUnit<WorkResult, WorkInput>{std::move(fn), input, std::move(promise)});
        return future;
    }

    void join() {
        _queue.setDone();
        for (auto&& t : _threads) {
            t.join();
        }
    }
};
