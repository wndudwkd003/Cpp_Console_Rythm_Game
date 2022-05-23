#include "GameManager.h"

int main()
{
    system("mode con: cols=136 lines=40");
    cout << endl << endl << endl << endl;
    cout << "                         ◆〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓◆" << endl;
    cout << "                                                                                                                  " << endl;
    cout << "                                                                                                                               " << endl;             
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                            Bi                                                 " << endl;         
    cout << "                                                                            BB                                                 " << endl;         
    cout << "                                                                            BBB                                                " << endl;         
    cout << "                                                                            BBQB                                               " << endl;         
    cout << "                           QBB          .PBBBBBBBr     :BBBQBQBB1     .QBQ  BBBBP   :BBZ     :gBBBBQBBBr                       " << endl;         
    cout << "                           BBB         BBBBS::7BBBQ7   UK21UuIRBBBB   .BQB  BBBBBv  :BQB   IBBBBP1ssLu.                        " << endl;         
    cout << "                           BBB        BBB.       BBBJ           LBBB  .BBQ  BBBBBQ. .BBd  BBBB                                 " << endl;         
    cout << "                           BQB       gBBi         BBB            PQBD  BQQ  BBB QBB  BBZ  BBB     YQdSKS                       " << endl;         
    cout << "                           BBB       DBBi         BBB            XBBM  BBR  BQB  BBB:BBb  BBB    rBBBBBB                       " << endl;         
    cout << "                           BBB        BBB.       BBB2           rBBB   BBQ  BBQ  .BBQBBE  BBBQ       BBB                       " << endl;         
    cout << "                           BBB77YY1X   BBBBY:.rgBBBs    LsJvYsgBBBB   .BBB  BBB   rBBBBd   5BBBQ7.. :BBB  :7L  .Lv   vL.       " << endl;         
    cout << "                           BBBBBBBQg    .gBBBBQBQL     QBBBBQBBB1     .BBB  QBB    XBBBZ     rMBBBBBBBBB  BBB  EBBi :BBg       " << endl;         
    cout << "                                                                                    RQBE             BBB                       " << endl;         
    cout << "                                                                                     BBM             BBB                       " << endl;         
    cout << "                                                                                      BB             :BB                       " << endl;         
    cout << "                                                                                      :B              .B                       " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                               " << endl;         
    cout << "                                                                                                                  " << endl;
    cout << "                         ◆〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓◆" << endl;

    CONSOLE_CURSOR_INFO ConsoleCursor;
    ConsoleCursor.bVisible = false;
    ConsoleCursor.dwSize = 1;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConsoleCursor);  // 커서 숨김
    
    GameManager gm;
    SoundManager sm;

    sm.bg_volume = gm.bg_sound * 0.2f;
    sm.ef_volume = gm.eff_sound * 0.2f;

    selec(&gm, &sm);

	return 0;
}