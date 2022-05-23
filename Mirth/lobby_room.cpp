#include "GameManager.h"
int p_lobby_room(GameManager* gm, SoundManager* sm)    // 곡 선택
{
	system("mode con: cols=180 lines=60");
	int select = 35;	// 기본값
	int key_input = 0;

	sm->channel[0]->stop();
	sm->system->playSound(sm->sound[1], 0, false, &sm->channel[0]);

	
	while (true)
	{
		sm->channel[0]->setVolume(sm->bg_volume);
		sm->channel[3]->setVolume(sm->ef_volume);
		sm->channel[4]->setVolume(sm->ef_volume);
		sm->system->update();
		Sleep(100);
		system("cls");

		

		// 테두리 

		for (int i = 2; i < 176; i++)
		{
			gotoxy(i, 1);
			cout << "□";
		}
		for (int i = 2; i < 58; i++)
		{
			gotoxy(2, i);
			cout << "□";
		}
		for (int i = 2; i < 58; i++)
		{
			gotoxy(176, i);
			cout << "□";
		}
		for (int i = 2; i < 176; i++)
		{
			gotoxy(i, 58);
			cout << "□";
		}

		// 맵 이름
		gotoxy(26, 42);
		cout << "[     Million     ]			            [     Burn The House Down    ]			    [      Everything Black     ]";

		// 게임 최대 스코어 표시
		gotoxy(32, 47);
		cout << gm->score[0][0];
		gotoxy(88, 47);
		cout << gm->score[1][0];
		gotoxy(144, 47);
		cout << gm->score[2][0];

		// 맵 초상화
		gotoxy(0, 4);

		cout << "	      ▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;    
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                 BBBd                   ▧" << endl;
		cout << "	      ▧                 BBBQ                   ▧" << endl;
		cout << "	      ▧                 BBBD                   ▧" << endl;
		cout << "	      ▧                 BBBd                   ▧" << endl;
		cout << "	      ▧                 BBQE                   ▧" << endl;
		cout << "	      ▧                 BBBP                   ▧" << endl;
		cout << "	      ▧                 BBB5                   ▧" << endl;
		cout << "	      ▧                 BBBBgQQQBBQ            ▧" << endl;
		cout << "	      ▧                 BBQBBBBBBB:            ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧                                        ▧" << endl;
		cout << "	      ▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧" << endl;

		gotoxy(0, 4);
		cout << "								    ▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧  i i:.....::..   .   ....  ....:::::.  ▧" << endl;
		cout << "								    ▧  . ..                       .  ..   .  ▧" << endl;
		cout << "								    ▧  . ... ..:.   ..  .. .......  .. ....  ▧" << endl;
		cout << "								    ▧  : :::. . .   ...........   . .......  ▧" << endl;
		cout << "								    ▧  : :.:... ..  ... .. ......... . ....  ▧" << endl;
		cout << "								    ▧  . .. ... ...   ........... ...   ...  ▧" << endl;
		cout << "								    ▧  . ...  ....  ...   .... ..  ........  ▧" << endl;
		cout << "								    ▧     ..  ...  ..     . ..   ..........  ▧" << endl;
		cout << "								    ▧  . .         .         .   ........    ▧" << endl;
		cout << "								    ▧             ...    :  ..   .      .:.  ▧" << endl;
		cout << "								    ▧  . .     .             .   .      .:.  ▧" << endl;
		cout << "								    ▧                                   .::  ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧                                   :::  ▧" << endl;
		cout << "								    ▧                             .:    :i:  ▧" << endl;
		cout << "								    ▧  PJP7:..                    .......:i  ▧" << endl;
		cout << "								    ▧  BqBQRPv7r. ...i 2BYQR  ..  .7.  ur..  ▧" << endl;
		cout << "								    ▧  BBBBBQbBguIbggKIBBEBdirr: :MBjrbBBJ.  ▧" << endl;
		cout << "								    ▧  BQBQBBBBBQBBBBBBBQBQBBBBgdBBBDBBBRBZ  ▧" << endl;
		cout << "								    ▧  QQQQQQQBQBQBQBQBQBQBQBQBBBBBBBQBMQQB  ▧" << endl;
		cout << "								    ▧  BBBBBBBQBBBQBBBBBBBQBBBBBBBBBBBBBBBB  ▧" << endl;
		cout << "								    ▧  SSSKSXSX5KSXSX5XXXXXXKSX5XXXSKXKSK5K  ▧" << endl;
		cout << "								    ▧                                        ▧" << endl;
		cout << "								    ▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧" << endl;

		gotoxy(0, 4);
		cout << "															  ▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧" << endl;
		cout << "															  ▧                                        ▧" << endl;
		cout << "															  ▧  :  JJ1suJJJuJjLuLusJLssUsriJsJYsLsY7  ▧" << endl;
		cout << "															  ▧  i  u1ujJuJJsJsjss7jLusU7:ijYsvsvYvs7  ▧" << endl;
		cout << "															  ▧  r :usjssLYsYvsvsv7LYLUr:rJLYvvvL7Lv7  ▧" << endl;
		cout << "															  ▧  srJYJLsLv7svLvvvYYLvj  7JvLvL7v7v7Li  ▧" << endl;
		cout << "															  ▧  s7vsv7vv77vv7vv7rL7vv:rJ7v77777v7vvi  ▧" << endl;
		cout << "															  ▧  LrLvv7v7vvv7v777v7777Yri7rrrrrrr7r7i  ▧" << endl;
		cout << "															  ▧  7r777v77r7r7r7r7r7r7rrrri7:7rrrrrrri  ▧" << endl;
		cout << "															  ▧  7i7r7iirrrrirrrrrrrrriririrrriiirir:  ▧" << endl;
		cout << "															  ▧  rirrrrrririiiiiiiriririi:i::ii:iiri:  ▧" << endl;
		cout << "															  ▧  r:rir::iiiiiiiiiiii:i:i:ii::i:i:i:::  ▧" << endl;
		cout << "															  ▧  i:iii:.ii::i:i::::::::::::::::::::::  ▧" << endl;
		cout << "															  ▧  i.i:i:i:i::::::::::...:::::::::::::.  ▧" << endl;
		cout << "															  ▧  i::i:i::::::::::...:::::::.:::.::::.  ▧" << endl;
		cout << "															  ▧  :.i::::::::::.::::::::...::.:::.:.:.  ▧" << endl;
		cout << "															  ▧  :.::::::...::..:::::::...::.........  ▧" << endl;
		cout << "															  ▧  i.:::::::.::...:...:..  ............  ▧" << endl;
		cout << "															  ▧  :.:::::::::...::.:::::......:.......  ▧" << endl;
		cout << "															  ▧  :.:.:....  . .:...:. ..:.:::::...:::  ▧" << endl;
		cout << "															  ▧  . .....::.i:...:.:::::.::.:::::::::   ▧" << endl;
		cout << "															  ▧  . .... .i:...:..i:...:.::...::...     ▧" << endl;
		cout << "															  ▧  . .. ..i:...:.::...::...::...         ▧" << endl;
		cout << "															  ▧  . ..i:...:.::...::...                 ▧" << endl;
		cout << "															  ▧  ::... :.::::::::                      ▧" << endl;
		cout << "															  ▧  :.::::::::                            ▧" << endl;
		cout << "															  ▧                                        ▧" << endl;
		cout << "															  ▧                   PDQBBQQZ27PDQBBQQZ27 ▧" << endl;
		cout << "															  ▧              PDQBBQQZ27rPDQBBQQZ27QBB  ▧" << endl;
		cout << "															  ▧         PDQBBQQZ27PvQBBPDQBBQQZ27PBB   ▧" << endl;
		cout << "															  ▧         BQQZ2BQQBQQZ27QBBQQZ27.        ▧" << endl;
		cout << "															  ▧    7LvjDdd7LvjDddbvjDddbUj5i ..        ▧" << endl;
		cout << "															  ▧                                        ▧" << endl;
		cout << "															  ▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧▧" << endl;
		
		// 버젼 표시
		gotoxy(87, 56);
		cout << "ver " << gm->ver;

		/*
		gotoxy(80, 56);
		cout << "뒤로가려면 ESC를 누르시오.";
		*/

		// 선택
		gotoxy(32, 51);
		cout << "< PLAY >";
		gotoxy(88, 51);
		cout << "< PLAY >";
		gotoxy(144, 51);
		cout << "< PLAY >";
		gotoxy(select - 8, 51);
		cout << "<     SELECT     >";
		gotoxy(select, 54);
		cout << "▲";

		key_input = _getch();
		if (key_input == SPECIAL_VALUE)
		{
			key_input = _getch();
			if (key_input == LEFT && select > 36)
			{
				select -= 56;
				sm->channel[0]->stop();
				sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
				if (select == 35 + 56 * 0) sm->system->playSound(sm->sound[1], 0, false, &sm->channel[0]);
				else if (select == 35 + 56 * 1) sm->system->playSound(sm->sound[2], 0, false, &sm->channel[0]);
				else if (select == 35 + 56 * 2) sm->system->playSound(sm->sound[3], 0, false, &sm->channel[0]);
			}
			else if (key_input == RIGHT && select < 145)
			{
				select += 56;
				sm->channel[0]->stop();
				sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
				if (select == 35 + 56 * 0) sm->system->playSound(sm->sound[1], 0, false, &sm->channel[0]);
				else if (select == 35 + 56 * 1) sm->system->playSound(sm->sound[2], 0, false, &sm->channel[0]);
				else if (select == 35 + 56 * 2) sm->system->playSound(sm->sound[3], 0, false, &sm->channel[0]);
			}
		}
		else if (key_input == ENTER)
		{
			sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
			if (select == 35 + 56 * 0)
			{
				return 1;
			}
			else if (select == 35 + 56 * 1)
			{
				return 2;
			}
			else if( select == 35 + 56 * 2)
			{
				return 3;
			}
		}
		else if (key_input == ESC)
		{
			sm->channel[0]->stop();
			sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
			return 0;
		}

		//

		

	}
}
