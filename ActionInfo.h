
#ifndef OTHELLO_ACTIONINFO_H
#define OTHELLO_ACTIONINFO_H


class ActionInfo {
public:
    const bool hasUpRightSurround;
    const bool hasUpLeftSurround;
    const bool hasDownRightSurround;
    const bool hasDownLeftSurround;
    const bool hasUpSurround;
    const bool hasDownSurround;
    const bool hasLeftSurround;
    const bool hasRightSurround;

    inline ActionInfo(
            const bool hasUpRightSurround,
            const bool hasUpLeftSurround,
            const bool hasDownRightSurround,
            const bool hasDownLeftSurround,
            const bool hasUpSurround,
            const bool hasDownSurround,
            const bool hasLeftSurround,
            const bool hasRightSurround
    ) :
            hasUpRightSurround(hasUpRightSurround),
            hasUpLeftSurround(hasUpLeftSurround),
            hasDownRightSurround(hasDownRightSurround),
            hasDownLeftSurround(hasDownLeftSurround),
            hasUpSurround(hasUpSurround),
            hasDownSurround(hasDownSurround),
            hasLeftSurround(hasLeftSurround),
            hasRightSurround(hasRightSurround) {
    }
    
    inline bool hasAnySurround() const {
        return hasUpRightSurround ||
               hasUpLeftSurround ||
               hasDownRightSurround ||
               hasDownLeftSurround ||
               hasUpSurround ||
               hasDownSurround ||
               hasLeftSurround ||
               hasRightSurround;
    }

};

#endif //OTHELLO_ACTIONINFO_H
