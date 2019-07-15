#include <iostream>
#include <fstream>

using namespace std;

#include "AlphaBeta.h"
#include "BitSet.h"
#include "State.h"
#include "Piece.h"

class TestScenario {
public:
    const unsigned long long black_pieces;
    const unsigned long long white_pieces;
    const uint8_t depth;
    const bool side;

    const uint8_t x_result;
    const uint8_t y_result;

    constexpr TestScenario(unsigned long long black_pieces,
              unsigned long long white_pieces,
              uint8_t depth,
              bool side,
              uint8_t x_result,
              uint8_t y_result)
              : black_pieces(black_pieces),
              white_pieces(white_pieces),
              depth(depth),
              side(side),
              x_result(x_result),
              y_result(y_result)
              {
    }
};

void test() {
    constexpr TestScenario ts0 = TestScenario(
            4630177389336434218LL,
            2238366195449473105LL,
            8,
            false,
            7,
            7);
    const AlphaBeta<8, false> alphaBeta0;
    Action a0 = alphaBeta0.alpha_beta_search(Helpers2::getBoard(ts0.black_pieces, ts0.white_pieces));
    if(a0.xIndex != ts0.x_result || a0.yIndex != ts0.y_result){
        cout << "Test failed : " << ts0.black_pieces << " : " << ts0.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts1 = TestScenario(
            731310150652160071LL,
            8365463008177624592LL,
            11,
            false,
            5,
            7);
    const AlphaBeta<11, false> alphaBeta1;
    Action a1 = alphaBeta1.alpha_beta_search(Helpers2::getBoard(ts1.black_pieces, ts1.white_pieces));
    if(a1.xIndex != ts1.x_result || a1.yIndex != ts1.y_result){
        cout << "Test failed : " << ts1.black_pieces << " : " << ts1.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts2 = TestScenario(
            1450207879760609808LL,
            2471509813356738729LL,
            10,
            true,
            7,
            6);
    const AlphaBeta<10, true> alphaBeta2;
    Action a2 = alphaBeta2.alpha_beta_search(Helpers2::getBoard(ts2.black_pieces, ts2.white_pieces));
    if(a2.xIndex != ts2.x_result || a2.yIndex != ts2.y_result){
        cout << "Test failed : " << ts2.black_pieces << " : " << ts2.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts3 = TestScenario(
            599049143391888961LL,
            7461968850314842552LL,
            11,
            true,
            6,
            5);
    const AlphaBeta<11, true> alphaBeta3;
    Action a3 = alphaBeta3.alpha_beta_search(Helpers2::getBoard(ts3.black_pieces, ts3.white_pieces));
    if(a3.xIndex != ts3.x_result || a3.yIndex != ts3.y_result){
        cout << "Test failed : " << ts3.black_pieces << " : " << ts3.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts4 = TestScenario(
            2892543247228883008LL,
            5787722649424724254LL,
            4,
            false,
            7,
            2);
    const AlphaBeta<4, false> alphaBeta4;
    Action a4 = alphaBeta4.alpha_beta_search(Helpers2::getBoard(ts4.black_pieces, ts4.white_pieces));
    if(a4.xIndex != ts4.x_result || a4.yIndex != ts4.y_result){
        cout << "Test failed : " << ts4.black_pieces << " : " << ts4.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts5 = TestScenario(
            14726352243306580LL,
            921131535368849193LL,
            10,
            false,
            3,
            7);
    const AlphaBeta<10, false> alphaBeta5;
    Action a5 = alphaBeta5.alpha_beta_search(Helpers2::getBoard(ts5.black_pieces, ts5.white_pieces));
    if(a5.xIndex != ts5.x_result || a5.yIndex != ts5.y_result){
        cout << "Test failed : " << ts5.black_pieces << " : " << ts5.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts6 = TestScenario(
            1156434198496842625LL,
            7543674752705121374LL,
            7,
            true,
            0,
            5);
    const AlphaBeta<7, true> alphaBeta6;
    Action a6 = alphaBeta6.alpha_beta_search(Helpers2::getBoard(ts6.black_pieces, ts6.white_pieces));
    if(a6.xIndex != ts6.x_result || a6.yIndex != ts6.y_result){
        cout << "Test failed : " << ts6.black_pieces << " : " << ts6.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts7 = TestScenario(
            297382717385413158LL,
            8917182590528801873LL,
            9,
            true,
            0,
            3);
    const AlphaBeta<9, true> alphaBeta7;
    Action a7 = alphaBeta7.alpha_beta_search(Helpers2::getBoard(ts7.black_pieces, ts7.white_pieces));
    if(a7.xIndex != ts7.x_result || a7.yIndex != ts7.y_result){
        cout << "Test failed : " << ts7.black_pieces << " : " << ts7.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts8 = TestScenario(
            8093588016884574343LL,
            108368503837034240LL,
            8,
            false,
            7,
            7);
    const AlphaBeta<8, false> alphaBeta8;
    Action a8 = alphaBeta8.alpha_beta_search(Helpers2::getBoard(ts8.black_pieces, ts8.white_pieces));
    if(a8.xIndex != ts8.x_result || a8.yIndex != ts8.y_result){
        cout << "Test failed : " << ts8.black_pieces << " : " << ts8.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts9 = TestScenario(
            9065764982544673256LL,
            11088302677099009LL,
            3,
            true,
            5,
            7);
    const AlphaBeta<3, true> alphaBeta9;
    Action a9 = alphaBeta9.alpha_beta_search(Helpers2::getBoard(ts9.black_pieces, ts9.white_pieces));
    if(a9.xIndex != ts9.x_result || a9.yIndex != ts9.y_result){
        cout << "Test failed : " << ts9.black_pieces << " : " << ts9.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts10 = TestScenario(
            806234650557417808LL,
            56441893118656645LL,
            4,
            false,
            7,
            6);
    const AlphaBeta<4, false> alphaBeta10;
    Action a10 = alphaBeta10.alpha_beta_search(Helpers2::getBoard(ts10.black_pieces, ts10.white_pieces));
    if(a10.xIndex != ts10.x_result || a10.yIndex != ts10.y_result){
        cout << "Test failed : " << ts10.black_pieces << " : " << ts10.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts11 = TestScenario(
            550566019358261600LL,
            2311180095907545622LL,
            6,
            true,
            0,
            7);
    const AlphaBeta<6, true> alphaBeta11;
    Action a11 = alphaBeta11.alpha_beta_search(Helpers2::getBoard(ts11.black_pieces, ts11.white_pieces));
    if(a11.xIndex != ts11.x_result || a11.yIndex != ts11.y_result){
        cout << "Test failed : " << ts11.black_pieces << " : " << ts11.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts12 = TestScenario(
            4727772477582943301LL,
            4351325144510909082LL,
            4,
            false,
            7,
            7);
    const AlphaBeta<4, false> alphaBeta12;
    Action a12 = alphaBeta12.alpha_beta_search(Helpers2::getBoard(ts12.black_pieces, ts12.white_pieces));
    if(a12.xIndex != ts12.x_result || a12.yIndex != ts12.y_result){
        cout << "Test failed : " << ts12.black_pieces << " : " << ts12.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts13 = TestScenario(
            632905566235198500LL,
            1382714660958828994LL,
            6,
            true,
            7,
            5);
    const AlphaBeta<6, true> alphaBeta13;
    Action a13 = alphaBeta13.alpha_beta_search(Helpers2::getBoard(ts13.black_pieces, ts13.white_pieces));
    if(a13.xIndex != ts13.x_result || a13.yIndex != ts13.y_result){
        cout << "Test failed : " << ts13.black_pieces << " : " << ts13.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts14 = TestScenario(
            4963957738182480281LL,
            216245969381026822LL,
            5,
            false,
            7,
            7);
    const AlphaBeta<5, false> alphaBeta14;
    Action a14 = alphaBeta14.alpha_beta_search(Helpers2::getBoard(ts14.black_pieces, ts14.white_pieces));
    if(a14.xIndex != ts14.x_result || a14.yIndex != ts14.y_result){
        cout << "Test failed : " << ts14.black_pieces << " : " << ts14.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts15 = TestScenario(
            1243666410759127634LL,
            7353272688499308585LL,
            9,
            false,
            3,
            0);
    const AlphaBeta<9, false> alphaBeta15;
    Action a15 = alphaBeta15.alpha_beta_search(Helpers2::getBoard(ts15.black_pieces, ts15.white_pieces));
    if(a15.xIndex != ts15.x_result || a15.yIndex != ts15.y_result){
        cout << "Test failed : " << ts15.black_pieces << " : " << ts15.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts16 = TestScenario(
            6417646995829739584LL,
            2757874269113353916LL,
            6,
            true,
            7,
            7);
    const AlphaBeta<6, true> alphaBeta16;
    Action a16 = alphaBeta16.alpha_beta_search(Helpers2::getBoard(ts16.black_pieces, ts16.white_pieces));
    if(a16.xIndex != ts16.x_result || a16.yIndex != ts16.y_result){
        cout << "Test failed : " << ts16.black_pieces << " : " << ts16.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts17 = TestScenario(
            2526607497991115444LL,
            4946265776819931137LL,
            3,
            true,
            7,
            7);
    const AlphaBeta<3, true> alphaBeta17;
    Action a17 = alphaBeta17.alpha_beta_search(Helpers2::getBoard(ts17.black_pieces, ts17.white_pieces));
    if(a17.xIndex != ts17.x_result || a17.yIndex != ts17.y_result){
        cout << "Test failed : " << ts17.black_pieces << " : " << ts17.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts18 = TestScenario(
            2955645929098729029LL,
            1351713804616468762LL,
            10,
            true,
            7,
            2);
    const AlphaBeta<10, true> alphaBeta18;
    Action a18 = alphaBeta18.alpha_beta_search(Helpers2::getBoard(ts18.black_pieces, ts18.white_pieces));
    if(a18.xIndex != ts18.x_result || a18.yIndex != ts18.y_result){
        cout << "Test failed : " << ts18.black_pieces << " : " << ts18.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts19 = TestScenario(
            5824285135037433377LL,
            435084464914178372LL,
            3,
            true,
            2,
            0);
    const AlphaBeta<3, true> alphaBeta19;
    Action a19 = alphaBeta19.alpha_beta_search(Helpers2::getBoard(ts19.black_pieces, ts19.white_pieces));
    if(a19.xIndex != ts19.x_result || a19.yIndex != ts19.y_result){
        cout << "Test failed : " << ts19.black_pieces << " : " << ts19.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts20 = TestScenario(
            7139442036132159496LL,
            1207131835126515223LL,
            5,
            true,
            7,
            7);
    const AlphaBeta<5, true> alphaBeta20;
    Action a20 = alphaBeta20.alpha_beta_search(Helpers2::getBoard(ts20.black_pieces, ts20.white_pieces));
    if(a20.xIndex != ts20.x_result || a20.yIndex != ts20.y_result){
        cout << "Test failed : " << ts20.black_pieces << " : " << ts20.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts21 = TestScenario(
            6062514923356368322LL,
            2314029990109417501LL,
            6,
            true,
            7,
            0);
    const AlphaBeta<6, true> alphaBeta21;
    Action a21 = alphaBeta21.alpha_beta_search(Helpers2::getBoard(ts21.black_pieces, ts21.white_pieces));
    if(a21.xIndex != ts21.x_result || a21.yIndex != ts21.y_result){
        cout << "Test failed : " << ts21.black_pieces << " : " << ts21.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts22 = TestScenario(
            511169630213571509LL,
            641241285862237194LL,
            9,
            true,
            6,
            0);
    const AlphaBeta<9, true> alphaBeta22;
    Action a22 = alphaBeta22.alpha_beta_search(Helpers2::getBoard(ts22.black_pieces, ts22.white_pieces));
    if(a22.xIndex != ts22.x_result || a22.yIndex != ts22.y_result){
        cout << "Test failed : " << ts22.black_pieces << " : " << ts22.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts23 = TestScenario(
            4108296072093335890LL,
            170118775783038477LL,
            4,
            true,
            4,
            0);
    const AlphaBeta<4, true> alphaBeta23;
    Action a23 = alphaBeta23.alpha_beta_search(Helpers2::getBoard(ts23.black_pieces, ts23.white_pieces));
    if(a23.xIndex != ts23.x_result || a23.yIndex != ts23.y_result){
        cout << "Test failed : " << ts23.black_pieces << " : " << ts23.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts24 = TestScenario(
            4756012496679733158LL,
            2044415153739524105LL,
            9,
            false,
            7,
            0);
    const AlphaBeta<9, false> alphaBeta24;
    Action a24 = alphaBeta24.alpha_beta_search(Helpers2::getBoard(ts24.black_pieces, ts24.white_pieces));
    if(a24.xIndex != ts24.x_result || a24.yIndex != ts24.y_result){
        cout << "Test failed : " << ts24.black_pieces << " : " << ts24.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts25 = TestScenario(
            3839178580600423936LL,
            36114597882984895LL,
            3,
            false,
            3,
            5);
    const AlphaBeta<3, false> alphaBeta25;
    Action a25 = alphaBeta25.alpha_beta_search(Helpers2::getBoard(ts25.black_pieces, ts25.white_pieces));
    if(a25.xIndex != ts25.x_result || a25.yIndex != ts25.y_result){
        cout << "Test failed : " << ts25.black_pieces << " : " << ts25.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts26 = TestScenario(
            2595883181706061952LL,
            5359425896947357454LL,
            11,
            true,
            7,
            4);
    const AlphaBeta<11, true> alphaBeta26;
    Action a26 = alphaBeta26.alpha_beta_search(Helpers2::getBoard(ts26.black_pieces, ts26.white_pieces));
    if(a26.xIndex != ts26.x_result || a26.yIndex != ts26.y_result){
        cout << "Test failed : " << ts26.black_pieces << " : " << ts26.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts27 = TestScenario(
            147662767229551424LL,
            4400615248778890425LL,
            4,
            true,
            5,
            6);
    const AlphaBeta<4, true> alphaBeta27;
    Action a27 = alphaBeta27.alpha_beta_search(Helpers2::getBoard(ts27.black_pieces, ts27.white_pieces));
    if(a27.xIndex != ts27.x_result || a27.yIndex != ts27.y_result){
        cout << "Test failed : " << ts27.black_pieces << " : " << ts27.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts28 = TestScenario(
            162598013582623748LL,
            2312107646398306881LL,
            7,
            true,
            7,
            3);
    const AlphaBeta<7, true> alphaBeta28;
    Action a28 = alphaBeta28.alpha_beta_search(Helpers2::getBoard(ts28.black_pieces, ts28.white_pieces));
    if(a28.xIndex != ts28.x_result || a28.yIndex != ts28.y_result){
        cout << "Test failed : " << ts28.black_pieces << " : " << ts28.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts29 = TestScenario(
            2996055947864474240LL,
            6064251436147962236LL,
            6,
            true,
            7,
            7);
    const AlphaBeta<6, true> alphaBeta29;
    Action a29 = alphaBeta29.alpha_beta_search(Helpers2::getBoard(ts29.black_pieces, ts29.white_pieces));
    if(a29.xIndex != ts29.x_result || a29.yIndex != ts29.y_result){
        cout << "Test failed : " << ts29.black_pieces << " : " << ts29.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts30 = TestScenario(
            3278655760620915476LL,
            175152958760166408LL,
            11,
            false,
            7,
            4);
    const AlphaBeta<11, false> alphaBeta30;
    Action a30 = alphaBeta30.alpha_beta_search(Helpers2::getBoard(ts30.black_pieces, ts30.white_pieces));
    if(a30.xIndex != ts30.x_result || a30.yIndex != ts30.y_result){
        cout << "Test failed : " << ts30.black_pieces << " : " << ts30.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts31 = TestScenario(
            149263125183623432LL,
            1477185866182231686LL,
            7,
            true,
            0,
            0);
    const AlphaBeta<7, true> alphaBeta31;
    Action a31 = alphaBeta31.alpha_beta_search(Helpers2::getBoard(ts31.black_pieces, ts31.white_pieces));
    if(a31.xIndex != ts31.x_result || a31.yIndex != ts31.y_result){
        cout << "Test failed : " << ts31.black_pieces << " : " << ts31.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts32 = TestScenario(
            144124397057216641LL,
            7498564889104787838LL,
            11,
            false,
            6,
            3);
    const AlphaBeta<11, false> alphaBeta32;
    Action a32 = alphaBeta32.alpha_beta_search(Helpers2::getBoard(ts32.black_pieces, ts32.white_pieces));
    if(a32.xIndex != ts32.x_result || a32.yIndex != ts32.y_result){
        cout << "Test failed : " << ts32.black_pieces << " : " << ts32.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts33 = TestScenario(
            731778117519820840LL,
            1152924277579786181LL,
            8,
            true,
            7,
            5);
    const AlphaBeta<8, true> alphaBeta33;
    Action a33 = alphaBeta33.alpha_beta_search(Helpers2::getBoard(ts33.black_pieces, ts33.white_pieces));
    if(a33.xIndex != ts33.x_result || a33.yIndex != ts33.y_result){
        cout << "Test failed : " << ts33.black_pieces << " : " << ts33.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts34 = TestScenario(
            588851707189035532LL,
            8412770407945423217LL,
            5,
            true,
            0,
            7);
    const AlphaBeta<5, true> alphaBeta34;
    Action a34 = alphaBeta34.alpha_beta_search(Helpers2::getBoard(ts34.black_pieces, ts34.white_pieces));
    if(a34.xIndex != ts34.x_result || a34.yIndex != ts34.y_result){
        cout << "Test failed : " << ts34.black_pieces << " : " << ts34.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts35 = TestScenario(
            2454058847800410259LL,
            1513526249110289668LL,
            5,
            false,
            6,
            4);
    const AlphaBeta<5, false> alphaBeta35;
    Action a35 = alphaBeta35.alpha_beta_search(Helpers2::getBoard(ts35.black_pieces, ts35.white_pieces));
    if(a35.xIndex != ts35.x_result || a35.yIndex != ts35.y_result){
        cout << "Test failed : " << ts35.black_pieces << " : " << ts35.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts36 = TestScenario(
            18017260166517380LL,
            4048939889186606416LL,
            7,
            true,
            0,
            0);
    const AlphaBeta<7, true> alphaBeta36;
    Action a36 = alphaBeta36.alpha_beta_search(Helpers2::getBoard(ts36.black_pieces, ts36.white_pieces));
    if(a36.xIndex != ts36.x_result || a36.yIndex != ts36.y_result){
        cout << "Test failed : " << ts36.black_pieces << " : " << ts36.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts37 = TestScenario(
            3509233309507457503LL,
            652037487934572576LL,
            10,
            false,
            7,
            7);
    const AlphaBeta<10, false> alphaBeta37;
    Action a37 = alphaBeta37.alpha_beta_search(Helpers2::getBoard(ts37.black_pieces, ts37.white_pieces));
    if(a37.xIndex != ts37.x_result || a37.yIndex != ts37.y_result){
        cout << "Test failed : " << ts37.black_pieces << " : " << ts37.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts38 = TestScenario(
            5912382436940568888LL,
            2887034988713477824LL,
            4,
            true,
            0,
            2);
    const AlphaBeta<4, true> alphaBeta38;
    Action a38 = alphaBeta38.alpha_beta_search(Helpers2::getBoard(ts38.black_pieces, ts38.white_pieces));
    if(a38.xIndex != ts38.x_result || a38.yIndex != ts38.y_result){
        cout << "Test failed : " << ts38.black_pieces << " : " << ts38.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts39 = TestScenario(
            3491714701906201729LL,
            831725786205069648LL,
            3,
            true,
            4,
            7);
    const AlphaBeta<3, true> alphaBeta39;
    Action a39 = alphaBeta39.alpha_beta_search(Helpers2::getBoard(ts39.black_pieces, ts39.white_pieces));
    if(a39.xIndex != ts39.x_result || a39.yIndex != ts39.y_result){
        cout << "Test failed : " << ts39.black_pieces << " : " << ts39.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts40 = TestScenario(
            91790758869949717LL,
            2027006897028072138LL,
            3,
            true,
            7,
            5);
    const AlphaBeta<3, true> alphaBeta40;
    Action a40 = alphaBeta40.alpha_beta_search(Helpers2::getBoard(ts40.black_pieces, ts40.white_pieces));
    if(a40.xIndex != ts40.x_result || a40.yIndex != ts40.y_result){
        cout << "Test failed : " << ts40.black_pieces << " : " << ts40.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts41 = TestScenario(
            3049922391611951364LL,
            361443763982532674LL,
            7,
            true,
            4,
            3);
    const AlphaBeta<7, true> alphaBeta41;
    Action a41 = alphaBeta41.alpha_beta_search(Helpers2::getBoard(ts41.black_pieces, ts41.white_pieces));
    if(a41.xIndex != ts41.x_result || a41.yIndex != ts41.y_result){
        cout << "Test failed : " << ts41.black_pieces << " : " << ts41.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts42 = TestScenario(
            4189010820203716124LL,
            379855265667498050LL,
            10,
            false,
            0,
            5);
    const AlphaBeta<10, false> alphaBeta42;
    Action a42 = alphaBeta42.alpha_beta_search(Helpers2::getBoard(ts42.black_pieces, ts42.white_pieces));
    if(a42.xIndex != ts42.x_result || a42.yIndex != ts42.y_result){
        cout << "Test failed : " << ts42.black_pieces << " : " << ts42.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts43 = TestScenario(
            5878912769136337512LL,
            434710626222791815LL,
            7,
            false,
            7,
            3);
    const AlphaBeta<7, false> alphaBeta43;
    Action a43 = alphaBeta43.alpha_beta_search(Helpers2::getBoard(ts43.black_pieces, ts43.white_pieces));
    if(a43.xIndex != ts43.x_result || a43.yIndex != ts43.y_result){
        cout << "Test failed : " << ts43.black_pieces << " : " << ts43.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts44 = TestScenario(
            859343525392254114LL,
            7205861194789691665LL,
            8,
            true,
            3,
            3);
    const AlphaBeta<8, true> alphaBeta44;
    Action a44 = alphaBeta44.alpha_beta_search(Helpers2::getBoard(ts44.black_pieces, ts44.white_pieces));
    if(a44.xIndex != ts44.x_result || a44.yIndex != ts44.y_result){
        cout << "Test failed : " << ts44.black_pieces << " : " << ts44.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts45 = TestScenario(
            919883781715106952LL,
            2381070022897976069LL,
            5,
            true,
            4,
            0);
    const AlphaBeta<5, true> alphaBeta45;
    Action a45 = alphaBeta45.alpha_beta_search(Helpers2::getBoard(ts45.black_pieces, ts45.white_pieces));
    if(a45.xIndex != ts45.x_result || a45.yIndex != ts45.y_result){
        cout << "Test failed : " << ts45.black_pieces << " : " << ts45.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts46 = TestScenario(
            4760320495377729301LL,
            3009267680816175264LL,
            7,
            true,
            5,
            6);
    const AlphaBeta<7, true> alphaBeta46;
    Action a46 = alphaBeta46.alpha_beta_search(Helpers2::getBoard(ts46.black_pieces, ts46.white_pieces));
    if(a46.xIndex != ts46.x_result || a46.yIndex != ts46.y_result){
        cout << "Test failed : " << ts46.black_pieces << " : " << ts46.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts47 = TestScenario(
            7808546931350176128LL,
            1414766931904365668LL,
            9,
            false,
            7,
            7);
    const AlphaBeta<9, false> alphaBeta47;
    Action a47 = alphaBeta47.alpha_beta_search(Helpers2::getBoard(ts47.black_pieces, ts47.white_pieces));
    if(a47.xIndex != ts47.x_result || a47.yIndex != ts47.y_result){
        cout << "Test failed : " << ts47.black_pieces << " : " << ts47.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts48 = TestScenario(
            1733932351981171011LL,
            117168976274917508LL,
            11,
            false,
            1,
            7);
    const AlphaBeta<11, false> alphaBeta48;
    Action a48 = alphaBeta48.alpha_beta_search(Helpers2::getBoard(ts48.black_pieces, ts48.white_pieces));
    if(a48.xIndex != ts48.x_result || a48.yIndex != ts48.y_result){
        cout << "Test failed : " << ts48.black_pieces << " : " << ts48.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts49 = TestScenario(
            4621265116623612098LL,
            1678879884508435980LL,
            8,
            true,
            0,
            4);
    const AlphaBeta<8, true> alphaBeta49;
    Action a49 = alphaBeta49.alpha_beta_search(Helpers2::getBoard(ts49.black_pieces, ts49.white_pieces));
    if(a49.xIndex != ts49.x_result || a49.yIndex != ts49.y_result){
        cout << "Test failed : " << ts49.black_pieces << " : " << ts49.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts50 = TestScenario(
            5194973109211446337LL,
            288957393914839100LL,
            10,
            false,
            0,
            7);
    const AlphaBeta<10, false> alphaBeta50;
    Action a50 = alphaBeta50.alpha_beta_search(Helpers2::getBoard(ts50.black_pieces, ts50.white_pieces));
    if(a50.xIndex != ts50.x_result || a50.yIndex != ts50.y_result){
        cout << "Test failed : " << ts50.black_pieces << " : " << ts50.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts51 = TestScenario(
            36182797367640960LL,
            2398008780694219890LL,
            7,
            true,
            4,
            7);
    const AlphaBeta<7, true> alphaBeta51;
    Action a51 = alphaBeta51.alpha_beta_search(Helpers2::getBoard(ts51.black_pieces, ts51.white_pieces));
    if(a51.xIndex != ts51.x_result || a51.yIndex != ts51.y_result){
        cout << "Test failed : " << ts51.black_pieces << " : " << ts51.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts52 = TestScenario(
            2172063516343435269LL,
            77479359564237872LL,
            5,
            true,
            0,
            3);
    const AlphaBeta<5, true> alphaBeta52;
    Action a52 = alphaBeta52.alpha_beta_search(Helpers2::getBoard(ts52.black_pieces, ts52.white_pieces));
    if(a52.xIndex != ts52.x_result || a52.yIndex != ts52.y_result){
        cout << "Test failed : " << ts52.black_pieces << " : " << ts52.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts53 = TestScenario(
            199394455884685347LL,
            8944452086306608460LL,
            8,
            false,
            7,
            0);
    const AlphaBeta<8, false> alphaBeta53;
    Action a53 = alphaBeta53.alpha_beta_search(Helpers2::getBoard(ts53.black_pieces, ts53.white_pieces));
    if(a53.xIndex != ts53.x_result || a53.yIndex != ts53.y_result){
        cout << "Test failed : " << ts53.black_pieces << " : " << ts53.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts54 = TestScenario(
            2306505052971353174LL,
            5726362758651641896LL,
            4,
            true,
            1,
            7);
    const AlphaBeta<4, true> alphaBeta54;
    Action a54 = alphaBeta54.alpha_beta_search(Helpers2::getBoard(ts54.black_pieces, ts54.white_pieces));
    if(a54.xIndex != ts54.x_result || a54.yIndex != ts54.y_result){
        cout << "Test failed : " << ts54.black_pieces << " : " << ts54.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts55 = TestScenario(
            1959717042848552976LL,
            4651281852501337481LL,
            11,
            false,
            2,
            0);
    const AlphaBeta<11, false> alphaBeta55;
    Action a55 = alphaBeta55.alpha_beta_search(Helpers2::getBoard(ts55.black_pieces, ts55.white_pieces));
    if(a55.xIndex != ts55.x_result || a55.yIndex != ts55.y_result){
        cout << "Test failed : " << ts55.black_pieces << " : " << ts55.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts56 = TestScenario(
            581079840447496786LL,
            3585169544562112777LL,
            7,
            true,
            7,
            7);
    const AlphaBeta<7, true> alphaBeta56;
    Action a56 = alphaBeta56.alpha_beta_search(Helpers2::getBoard(ts56.black_pieces, ts56.white_pieces));
    if(a56.xIndex != ts56.x_result || a56.yIndex != ts56.y_result){
        cout << "Test failed : " << ts56.black_pieces << " : " << ts56.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts57 = TestScenario(
            2342129890851701783LL,
            29292097742940768LL,
            3,
            false,
            7,
            7);
    const AlphaBeta<3, false> alphaBeta57;
    Action a57 = alphaBeta57.alpha_beta_search(Helpers2::getBoard(ts57.black_pieces, ts57.white_pieces));
    if(a57.xIndex != ts57.x_result || a57.yIndex != ts57.y_result){
        cout << "Test failed : " << ts57.black_pieces << " : " << ts57.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts58 = TestScenario(
            5188432940561355240LL,
            3579483411951558661LL,
            3,
            false,
            2,
            0);
    const AlphaBeta<3, false> alphaBeta58;
    Action a58 = alphaBeta58.alpha_beta_search(Helpers2::getBoard(ts58.black_pieces, ts58.white_pieces));
    if(a58.xIndex != ts58.x_result || a58.yIndex != ts58.y_result){
        cout << "Test failed : " << ts58.black_pieces << " : " << ts58.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts59 = TestScenario(
            5262504304123589321LL,
            330456108797724980LL,
            6,
            true,
            1,
            7);
    const AlphaBeta<6, true> alphaBeta59;
    Action a59 = alphaBeta59.alpha_beta_search(Helpers2::getBoard(ts59.black_pieces, ts59.white_pieces));
    if(a59.xIndex != ts59.x_result || a59.yIndex != ts59.y_result){
        cout << "Test failed : " << ts59.black_pieces << " : " << ts59.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts60 = TestScenario(
            78969330313736704LL,
            4378362835073533300LL,
            7,
            true,
            7,
            1);
    const AlphaBeta<7, true> alphaBeta60;
    Action a60 = alphaBeta60.alpha_beta_search(Helpers2::getBoard(ts60.black_pieces, ts60.white_pieces));
    if(a60.xIndex != ts60.x_result || a60.yIndex != ts60.y_result){
        cout << "Test failed : " << ts60.black_pieces << " : " << ts60.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts61 = TestScenario(
            2200336218886293044LL,
            2320620725310011403LL,
            8,
            false,
            7,
            0);
    const AlphaBeta<8, false> alphaBeta61;
    Action a61 = alphaBeta61.alpha_beta_search(Helpers2::getBoard(ts61.black_pieces, ts61.white_pieces));
    if(a61.xIndex != ts61.x_result || a61.yIndex != ts61.y_result){
        cout << "Test failed : " << ts61.black_pieces << " : " << ts61.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts62 = TestScenario(
            184710326417537169LL,
            6731831023900312168LL,
            6,
            true,
            7,
            5);
    const AlphaBeta<6, true> alphaBeta62;
    Action a62 = alphaBeta62.alpha_beta_search(Helpers2::getBoard(ts62.black_pieces, ts62.white_pieces));
    if(a62.xIndex != ts62.x_result || a62.yIndex != ts62.y_result){
        cout << "Test failed : " << ts62.black_pieces << " : " << ts62.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts63 = TestScenario(
            4615375597253299791LL,
            1824173387935969680LL,
            4,
            false,
            2,
            0);
    const AlphaBeta<4, false> alphaBeta63;
    Action a63 = alphaBeta63.alpha_beta_search(Helpers2::getBoard(ts63.black_pieces, ts63.white_pieces));
    if(a63.xIndex != ts63.x_result || a63.yIndex != ts63.y_result){
        cout << "Test failed : " << ts63.black_pieces << " : " << ts63.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts64 = TestScenario(
            1621688007244467280LL,
            2902711836426936995LL,
            9,
            true,
            7,
            7);
    const AlphaBeta<9, true> alphaBeta64;
    Action a64 = alphaBeta64.alpha_beta_search(Helpers2::getBoard(ts64.black_pieces, ts64.white_pieces));
    if(a64.xIndex != ts64.x_result || a64.yIndex != ts64.y_result){
        cout << "Test failed : " << ts64.black_pieces << " : " << ts64.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts65 = TestScenario(
            6370693706824697606LL,
            2563146603621812472LL,
            3,
            false,
            7,
            7);
    const AlphaBeta<3, false> alphaBeta65;
    Action a65 = alphaBeta65.alpha_beta_search(Helpers2::getBoard(ts65.black_pieces, ts65.white_pieces));
    if(a65.xIndex != ts65.x_result || a65.yIndex != ts65.y_result){
        cout << "Test failed : " << ts65.black_pieces << " : " << ts65.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts66 = TestScenario(
            7011013979770200217LL,
            1490984652877087490LL,
            4,
            true,
            5,
            7);
    const AlphaBeta<4, true> alphaBeta66;
    Action a66 = alphaBeta66.alpha_beta_search(Helpers2::getBoard(ts66.black_pieces, ts66.white_pieces));
    if(a66.xIndex != ts66.x_result || a66.yIndex != ts66.y_result){
        cout << "Test failed : " << ts66.black_pieces << " : " << ts66.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts67 = TestScenario(
            5211398995137569217LL,
            3828064322341902896LL,
            5,
            false,
            7,
            1);
    const AlphaBeta<5, false> alphaBeta67;
    Action a67 = alphaBeta67.alpha_beta_search(Helpers2::getBoard(ts67.black_pieces, ts67.white_pieces));
    if(a67.xIndex != ts67.x_result || a67.yIndex != ts67.y_result){
        cout << "Test failed : " << ts67.black_pieces << " : " << ts67.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts68 = TestScenario(
            1730668694780280886LL,
            208020368705408393LL,
            5,
            false,
            0,
            6);
    const AlphaBeta<5, false> alphaBeta68;
    Action a68 = alphaBeta68.alpha_beta_search(Helpers2::getBoard(ts68.black_pieces, ts68.white_pieces));
    if(a68.xIndex != ts68.x_result || a68.yIndex != ts68.y_result){
        cout << "Test failed : " << ts68.black_pieces << " : " << ts68.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts69 = TestScenario(
            1301638149988026028LL,
            5485707940302460945LL,
            8,
            false,
            7,
            0);
    const AlphaBeta<8, false> alphaBeta69;
    Action a69 = alphaBeta69.alpha_beta_search(Helpers2::getBoard(ts69.black_pieces, ts69.white_pieces));
    if(a69.xIndex != ts69.x_result || a69.yIndex != ts69.y_result){
        cout << "Test failed : " << ts69.black_pieces << " : " << ts69.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts70 = TestScenario(
            1361830449859683329LL,
            2889565354186342508LL,
            9,
            true,
            7,
            0);
    const AlphaBeta<9, true> alphaBeta70;
    Action a70 = alphaBeta70.alpha_beta_search(Helpers2::getBoard(ts70.black_pieces, ts70.white_pieces));
    if(a70.xIndex != ts70.x_result || a70.yIndex != ts70.y_result){
        cout << "Test failed : " << ts70.black_pieces << " : " << ts70.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts71 = TestScenario(
            1080988587768434720LL,
            26890322093146587LL,
            3,
            true,
            0,
            2);
    const AlphaBeta<3, true> alphaBeta71;
    Action a71 = alphaBeta71.alpha_beta_search(Helpers2::getBoard(ts71.black_pieces, ts71.white_pieces));
    if(a71.xIndex != ts71.x_result || a71.yIndex != ts71.y_result){
        cout << "Test failed : " << ts71.black_pieces << " : " << ts71.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts72 = TestScenario(
            4708840007421961920LL,
            2170735725103171863LL,
            6,
            false,
            7,
            5);
    const AlphaBeta<6, false> alphaBeta72;
    Action a72 = alphaBeta72.alpha_beta_search(Helpers2::getBoard(ts72.black_pieces, ts72.white_pieces));
    if(a72.xIndex != ts72.x_result || a72.yIndex != ts72.y_result){
        cout << "Test failed : " << ts72.black_pieces << " : " << ts72.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts73 = TestScenario(
            1599130553536354824LL,
            650812105905931271LL,
            4,
            true,
            4,
            1);
    const AlphaBeta<4, true> alphaBeta73;
    Action a73 = alphaBeta73.alpha_beta_search(Helpers2::getBoard(ts73.black_pieces, ts73.white_pieces));
    if(a73.xIndex != ts73.x_result || a73.yIndex != ts73.y_result){
        cout << "Test failed : " << ts73.black_pieces << " : " << ts73.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts74 = TestScenario(
            1866780574356472098LL,
            2306225643580347464LL,
            9,
            true,
            7,
            6);
    const AlphaBeta<9, true> alphaBeta74;
    Action a74 = alphaBeta74.alpha_beta_search(Helpers2::getBoard(ts74.black_pieces, ts74.white_pieces));
    if(a74.xIndex != ts74.x_result || a74.yIndex != ts74.y_result){
        cout << "Test failed : " << ts74.black_pieces << " : " << ts74.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts75 = TestScenario(
            3605132601693780114LL,
            5572446116916528713LL,
            4,
            false,
            4,
            0);
    const AlphaBeta<4, false> alphaBeta75;
    Action a75 = alphaBeta75.alpha_beta_search(Helpers2::getBoard(ts75.black_pieces, ts75.white_pieces));
    if(a75.xIndex != ts75.x_result || a75.yIndex != ts75.y_result){
        cout << "Test failed : " << ts75.black_pieces << " : " << ts75.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts76 = TestScenario(
            883007072426545216LL,
            6028253610953450152LL,
            8,
            true,
            7,
            5);
    const AlphaBeta<8, true> alphaBeta76;
    Action a76 = alphaBeta76.alpha_beta_search(Helpers2::getBoard(ts76.black_pieces, ts76.white_pieces));
    if(a76.xIndex != ts76.x_result || a76.yIndex != ts76.y_result){
        cout << "Test failed : " << ts76.black_pieces << " : " << ts76.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts77 = TestScenario(
            8144909816465556578LL,
            45389131316490756LL,
            7,
            true,
            1,
            3);
    const AlphaBeta<7, true> alphaBeta77;
    Action a77 = alphaBeta77.alpha_beta_search(Helpers2::getBoard(ts77.black_pieces, ts77.white_pieces));
    if(a77.xIndex != ts77.x_result || a77.yIndex != ts77.y_result){
        cout << "Test failed : " << ts77.black_pieces << " : " << ts77.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts78 = TestScenario(
            797420000963991684LL,
            2325003727667462698LL,
            10,
            true,
            4,
            0);
    const AlphaBeta<10, true> alphaBeta78;
    Action a78 = alphaBeta78.alpha_beta_search(Helpers2::getBoard(ts78.black_pieces, ts78.white_pieces));
    if(a78.xIndex != ts78.x_result || a78.yIndex != ts78.y_result){
        cout << "Test failed : " << ts78.black_pieces << " : " << ts78.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts79 = TestScenario(
            5221933116169786162LL,
            433564044050336780LL,
            5,
            false,
            0,
            0);
    const AlphaBeta<5, false> alphaBeta79;
    Action a79 = alphaBeta79.alpha_beta_search(Helpers2::getBoard(ts79.black_pieces, ts79.white_pieces));
    if(a79.xIndex != ts79.x_result || a79.yIndex != ts79.y_result){
        cout << "Test failed : " << ts79.black_pieces << " : " << ts79.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts80 = TestScenario(
            5790328411981351017LL,
            2450128312695836944LL,
            7,
            true,
            6,
            2);
    const AlphaBeta<7, true> alphaBeta80;
    Action a80 = alphaBeta80.alpha_beta_search(Helpers2::getBoard(ts80.black_pieces, ts80.white_pieces));
    if(a80.xIndex != ts80.x_result || a80.yIndex != ts80.y_result){
        cout << "Test failed : " << ts80.black_pieces << " : " << ts80.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts81 = TestScenario(
            4864759029269795469LL,
            581000002950881328LL,
            8,
            true,
            1,
            7);
    const AlphaBeta<8, true> alphaBeta81;
    Action a81 = alphaBeta81.alpha_beta_search(Helpers2::getBoard(ts81.black_pieces, ts81.white_pieces));
    if(a81.xIndex != ts81.x_result || a81.yIndex != ts81.y_result){
        cout << "Test failed : " << ts81.black_pieces << " : " << ts81.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts82 = TestScenario(
            5354783265312103856LL,
            2378424147702972493LL,
            8,
            false,
            2,
            0);
    const AlphaBeta<8, false> alphaBeta82;
    Action a82 = alphaBeta82.alpha_beta_search(Helpers2::getBoard(ts82.black_pieces, ts82.white_pieces));
    if(a82.xIndex != ts82.x_result || a82.yIndex != ts82.y_result){
        cout << "Test failed : " << ts82.black_pieces << " : " << ts82.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts83 = TestScenario(
            4650055139001322693LL,
            2258460932497256472LL,
            10,
            false,
            0,
            5);
    const AlphaBeta<10, false> alphaBeta83;
    Action a83 = alphaBeta83.alpha_beta_search(Helpers2::getBoard(ts83.black_pieces, ts83.white_pieces));
    if(a83.xIndex != ts83.x_result || a83.yIndex != ts83.y_result){
        cout << "Test failed : " << ts83.black_pieces << " : " << ts83.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts84 = TestScenario(
            4933663853490883916LL,
            218444940612767873LL,
            4,
            true,
            4,
            3);
    const AlphaBeta<4, true> alphaBeta84;
    Action a84 = alphaBeta84.alpha_beta_search(Helpers2::getBoard(ts84.black_pieces, ts84.white_pieces));
    if(a84.xIndex != ts84.x_result || a84.yIndex != ts84.y_result){
        cout << "Test failed : " << ts84.black_pieces << " : " << ts84.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts85 = TestScenario(
            1442283464729597464LL,
            4702241813276000357LL,
            10,
            true,
            0,
            1);
    const AlphaBeta<10, true> alphaBeta85;
    Action a85 = alphaBeta85.alpha_beta_search(Helpers2::getBoard(ts85.black_pieces, ts85.white_pieces));
    if(a85.xIndex != ts85.x_result || a85.yIndex != ts85.y_result){
        cout << "Test failed : " << ts85.black_pieces << " : " << ts85.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts86 = TestScenario(
            5284803119450729LL,
            8604443833377948934LL,
            4,
            false,
            0,
            4);
    const AlphaBeta<4, false> alphaBeta86;
    Action a86 = alphaBeta86.alpha_beta_search(Helpers2::getBoard(ts86.black_pieces, ts86.white_pieces));
    if(a86.xIndex != ts86.x_result || a86.yIndex != ts86.y_result){
        cout << "Test failed : " << ts86.black_pieces << " : " << ts86.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts87 = TestScenario(
            90212902947819105LL,
            7079174306139234460LL,
            10,
            false,
            0,
            1);
    const AlphaBeta<10, false> alphaBeta87;
    Action a87 = alphaBeta87.alpha_beta_search(Helpers2::getBoard(ts87.black_pieces, ts87.white_pieces));
    if(a87.xIndex != ts87.x_result || a87.yIndex != ts87.y_result){
        cout << "Test failed : " << ts87.black_pieces << " : " << ts87.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts88 = TestScenario(
            6936389785964416644LL,
            937885738393997418LL,
            7,
            true,
            7,
            1);
    const AlphaBeta<7, true> alphaBeta88;
    Action a88 = alphaBeta88.alpha_beta_search(Helpers2::getBoard(ts88.black_pieces, ts88.white_pieces));
    if(a88.xIndex != ts88.x_result || a88.yIndex != ts88.y_result){
        cout << "Test failed : " << ts88.black_pieces << " : " << ts88.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts89 = TestScenario(
            1747434800736126020LL,
            7319494271863665306LL,
            7,
            false,
            0,
            5);
    const AlphaBeta<7, false> alphaBeta89;
    Action a89 = alphaBeta89.alpha_beta_search(Helpers2::getBoard(ts89.black_pieces, ts89.white_pieces));
    if(a89.xIndex != ts89.x_result || a89.yIndex != ts89.y_result){
        cout << "Test failed : " << ts89.black_pieces << " : " << ts89.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts90 = TestScenario(
            602427680795946220LL,
            1188997786801603073LL,
            11,
            false,
            7,
            7);
    const AlphaBeta<11, false> alphaBeta90;
    Action a90 = alphaBeta90.alpha_beta_search(Helpers2::getBoard(ts90.black_pieces, ts90.white_pieces));
    if(a90.xIndex != ts90.x_result || a90.yIndex != ts90.y_result){
        cout << "Test failed : " << ts90.black_pieces << " : " << ts90.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts91 = TestScenario(
            2331493041399240524LL,
            613775034763198593LL,
            8,
            true,
            7,
            7);
    const AlphaBeta<8, true> alphaBeta91;
    Action a91 = alphaBeta91.alpha_beta_search(Helpers2::getBoard(ts91.black_pieces, ts91.white_pieces));
    if(a91.xIndex != ts91.x_result || a91.yIndex != ts91.y_result){
        cout << "Test failed : " << ts91.black_pieces << " : " << ts91.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts92 = TestScenario(
            5947006058946462312LL,
            298707013792311697LL,
            10,
            true,
            7,
            3);
    const AlphaBeta<10, true> alphaBeta92;
    Action a92 = alphaBeta92.alpha_beta_search(Helpers2::getBoard(ts92.black_pieces, ts92.white_pieces));
    if(a92.xIndex != ts92.x_result || a92.yIndex != ts92.y_result){
        cout << "Test failed : " << ts92.black_pieces << " : " << ts92.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts93 = TestScenario(
            2183386018999444519LL,
            2315701168622977288LL,
            10,
            false,
            7,
            0);
    const AlphaBeta<10, false> alphaBeta93;
    Action a93 = alphaBeta93.alpha_beta_search(Helpers2::getBoard(ts93.black_pieces, ts93.white_pieces));
    if(a93.xIndex != ts93.x_result || a93.yIndex != ts93.y_result){
        cout << "Test failed : " << ts93.black_pieces << " : " << ts93.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts94 = TestScenario(
            1801864573990619280LL,
            5048018017289084935LL,
            9,
            true,
            2,
            7);
    const AlphaBeta<9, true> alphaBeta94;
    Action a94 = alphaBeta94.alpha_beta_search(Helpers2::getBoard(ts94.black_pieces, ts94.white_pieces));
    if(a94.xIndex != ts94.x_result || a94.yIndex != ts94.y_result){
        cout << "Test failed : " << ts94.black_pieces << " : " << ts94.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts95 = TestScenario(
            2506015719058070352LL,
            5852429988150345766LL,
            6,
            false,
            7,
            7);
    const AlphaBeta<6, false> alphaBeta95;
    Action a95 = alphaBeta95.alpha_beta_search(Helpers2::getBoard(ts95.black_pieces, ts95.white_pieces));
    if(a95.xIndex != ts95.x_result || a95.yIndex != ts95.y_result){
        cout << "Test failed : " << ts95.black_pieces << " : " << ts95.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts96 = TestScenario(
            5281105204698431748LL,
            3638922522791650346LL,
            7,
            false,
            7,
            7);
    const AlphaBeta<7, false> alphaBeta96;
    Action a96 = alphaBeta96.alpha_beta_search(Helpers2::getBoard(ts96.black_pieces, ts96.white_pieces));
    if(a96.xIndex != ts96.x_result || a96.yIndex != ts96.y_result){
        cout << "Test failed : " << ts96.black_pieces << " : " << ts96.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts97 = TestScenario(
            3502696057375842318LL,
            315428214353927232LL,
            7,
            true,
            0,
            7);
    const AlphaBeta<7, true> alphaBeta97;
    Action a97 = alphaBeta97.alpha_beta_search(Helpers2::getBoard(ts97.black_pieces, ts97.white_pieces));
    if(a97.xIndex != ts97.x_result || a97.yIndex != ts97.y_result){
        cout << "Test failed : " << ts97.black_pieces << " : " << ts97.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts98 = TestScenario(
            5337175665422485LL,
            7746473440522571330LL,
            8,
            false,
            6,
            5);
    const AlphaBeta<8, false> alphaBeta98;
    Action a98 = alphaBeta98.alpha_beta_search(Helpers2::getBoard(ts98.black_pieces, ts98.white_pieces));
    if(a98.xIndex != ts98.x_result || a98.yIndex != ts98.y_result){
        cout << "Test failed : " << ts98.black_pieces << " : " << ts98.white_pieces << endl;
        return;
    }
    constexpr TestScenario ts99 = TestScenario(
            90925726225694989LL,
            2162984050271805458LL,
            8,
            false,
            7,
            7);
    const AlphaBeta<8, false> alphaBeta99;
    Action a99 = alphaBeta99.alpha_beta_search(Helpers2::getBoard(ts99.black_pieces, ts99.white_pieces));
    if(a99.xIndex != ts99.x_result || a99.yIndex != ts99.y_result){
        cout << "Test failed : " << ts99.black_pieces << " : " << ts99.white_pieces << endl;
        return;
    }

    cout << "All tests have passed" << endl;
}

