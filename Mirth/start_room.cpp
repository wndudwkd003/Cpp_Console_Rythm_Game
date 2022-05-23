#include "GameManager.h"

int p_start_room(GameManager* gm, SoundManager* sm) // 시작 화면
{
    system("mode con: cols=136 lines=40");

    bool playing = false;
    sm->channel[0]->isPlaying(&playing);
    if (!playing) sm->system->playSound(sm->sound[0], 0, false, &sm->channel[0]);

    int key_input = 0;
    short u_select_num = 27;    // 27: "Game Start" 기본값

    

    while (true)
    {
        sm->channel[0]->setVolume(sm->bg_volume);
        sm->channel[3]->setVolume(sm->ef_volume);
        sm->channel[4]->setVolume(sm->ef_volume);
        sm->system->update();
        
        Sleep(100);
        system("cls");
        cout << "                                                                                                                                  " << endl;
        cout << "                                                                                                                                  " << endl;
        cout << "                         ◆〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓◆" << endl;
        cout << "                                                                                                                             " << endl;
        cout << "                                                                                                                             " << endl;
        cout << "                                             7B                                                                              " << endl;
        cout << "                                             :B1                                                                             " << endl;
        cout << "                                             .BQ.                                                                            " << endl;
        cout << "                                             .BBB      77L  :sr  UL1IX5Y.   :PIYvuIPE. 21.    12.                            " << endl;
        cout << "                                             .BBBB    BBBQi BBB  BBBBBBBBB  BQBBBBBQQ  QB7    BB7                            " << endl;
        cout << "                                             .QBBBg  MBBBB. bBB  BB.    KBB    BBL     BQ.    BB:                            " << endl;
        cout << "                                             .BQ.BBiiBB.BB. bQB  QB:    SQB    BBj     BBMbZEPBB:                            " << endl;
        cout << "                                             .BB  BBQB. QB. qBQ  BBi bBBQB.    BBI     BBBBBBBBB:                            " << endl;
        cout << "                                             .BQ  UBBS  BQ. dBB  BBi  BBB      BBI     BB.    BB:                            " << endl;
        cout << "                                             :BB.  BB   BB. BBB  BQY   BBY     BBg     BB7    BB:                            " << endl;
        cout << "                                              I2        BB. ijv  J1.   iBBi    YU:     UU.    BB:                            " << endl;
        cout << "                                                        BB:             PBB                   BB:                            " << endl;
        cout << "                                                        BBi              BB                   QQr                            " << endl;
        cout << "                                                         B7              .B                    Bv                            " << endl;
        cout << "                                                                                                                             " << endl;
        cout << "                                                                                                                             " << endl;
        cout << "                         ◆〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓〓◆" << endl;

        for (int i = 0; i <= 10; i += 2)
        {
            if (i == 0)
            {
                gotoxy(58, i + 25);
                cout << "■〓〓〓〓〓〓〓〓〓〓〓〓〓■" << endl;
            }
            else if (i == 2)
            {
                gotoxy(68, i + 25); // 27
                cout << "Game Start" << endl;
            }
            else if (i == 4)
            {
                gotoxy(71, i + 25); // 29
                cout << "Help" << endl;
            }
            else if (i == 6)
            {
                gotoxy(69, i + 25); // 31
                cout << "Setting" << endl;
            }
            else if (i == 8)
            {
                gotoxy(71, i + 25); // 33
                cout << "Exit" << endl;
            }
            else if (i == 10)
            {
                gotoxy(58, i + 25);
                cout << "■〓〓〓〓〓〓〓〓〓〓〓〓〓■" << endl;
            }
        }

        gotoxy(63, u_select_num);
        cout << "▶";

        key_input = _getch();
        if (key_input == SPECIAL_VALUE)
        {
            key_input = _getch();
            if (key_input == UP && u_select_num > 27)
            {
                u_select_num -= 2;
                sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
            }
            else if (key_input == DOWN && u_select_num < 33)
            {
                u_select_num += 2;
                sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
            }
            
        }
        else if (key_input == ENTER)
        {
            sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4] );
            
            break;  // 엔터 누르고 선택된 번호 return
        }
    }
    return u_select_num;
}