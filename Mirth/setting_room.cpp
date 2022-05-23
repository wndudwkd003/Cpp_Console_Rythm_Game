#include "GameManager.h"

void p_game_setting(GameManager* gm, SoundManager* sm)    // 세팅
{
	system("mode con: cols=64 lines=40");
	int select = 35;	// 기본값
	int key_input = 0;
	int u_select_num = 12;

	while (true)
	{
		sm->channel[0]->setVolume(sm->bg_volume);
		sm->channel[3]->setVolume(sm->ef_volume);
		sm->channel[4]->setVolume(sm->ef_volume);
		sm->system->update();
		Sleep(100);
		system("cls");

		for (int i = 2; i < 60; i++)
		{
			gotoxy(i, 1);
			cout << "□";
		}
		for (int i = 2; i < 38; i++)
		{
			gotoxy(2, i);
			cout << "□";
		}
		for (int i = 2; i < 38; i++)
		{
			gotoxy(60, i);
			cout << "□";
		}
		for (int i = 2; i < 60; i++)
		{
			gotoxy(i, 38);
			cout << "□";
		}

		gotoxy(27, 5);
		cout << "<   Setting   >";
		gotoxy(24, 12);
		cout << "BackGround Sound:     " << gm->bg_sound;
		gotoxy(28, 19);
		cout << "Effect Sound:     " << gm->eff_sound;
		gotoxy(29, 26);
		cout << "Sync Timing:     " << gm->sync;
		gotoxy(12, 33);
		cout << "ESC를 누르면 저장되고 메인으로 돌아갑니다.";


		gotoxy(51, u_select_num);
		cout << "◀";

		key_input = _getch();
		if (key_input == SPECIAL_VALUE)
		{
			key_input = _getch();
			if (key_input == UP && u_select_num > 13)
			{
				sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
				u_select_num -= 7;
			}
			else if (key_input == DOWN && u_select_num < 20)
			{
				sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
				u_select_num += 7;
			}
		}
		else if (key_input == ENTER)
		{
			sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
			while (true)
			{
				sm->channel[0]->setVolume(sm->bg_volume);
				sm->channel[3]->setVolume(sm->ef_volume);
				sm->channel[4]->setVolume(sm->ef_volume);
				sm->system->update();
				
				Sleep(100);
				system("cls");

				for (int i = 2; i < 60; i++)
				{
					gotoxy(i, 1);
					cout << "□";
				}
				for (int i = 2; i < 38; i++)
				{
					gotoxy(2, i);
					cout << "□";
				}
				for (int i = 2; i < 38; i++)
				{
					gotoxy(60, i);
					cout << "□";
				}
				for (int i = 2; i < 60; i++)
				{
					gotoxy(i, 38);
					cout << "□";
				}

				gotoxy(27, 5);
				cout << "<   Setting   >";
				gotoxy(24, 12);
				cout << "BackGround Sound:     " << gm->bg_sound;
				gotoxy(28, 19);
				cout << "Effect Sound:     " << gm->eff_sound;
				gotoxy(29, 26);
				cout << "Sync Timing:     " << gm->sync;
				gotoxy(12, 33);
				cout << "ESC를 누르면 저장되고 메인으로 돌아갑니다.";

				gotoxy(43, u_select_num);
				cout << "◁";
				gotoxy(48, u_select_num);
				cout << "▷";
				gotoxy(51, u_select_num);
				cout << "  ";

				key_input = _getch();
				if (key_input == SPECIAL_VALUE)
				{
					key_input = _getch();
					if (key_input == LEFT)
					{
						if (u_select_num == 12 && gm->bg_sound > 0)
						{
							sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
							gm->bg_sound -= 1;
						}
						else if (u_select_num == 19 && gm->eff_sound > 0)
						{
							sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
							gm->eff_sound -= 1;
						}
						else if (u_select_num == 26 && gm->sync > -3)
						{
							sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
							gm->sync -= 1;
						}
						sm->bg_volume = gm->bg_sound * 0.2f;
						sm->ef_volume = gm->eff_sound * 0.2f;
						
					}
					else if (key_input == RIGHT)
					{
						if (u_select_num == 12 && gm->bg_sound < 5)
						{
							sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
							gm->bg_sound += 1;
						}
						else if (u_select_num == 19 && gm->eff_sound < 5)
						{
							sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
							gm->eff_sound += 1;
						}
						else if (u_select_num == 26 && gm->sync < 3)
						{
							sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
							gm->sync += 1;
						}
						sm->bg_volume = gm->bg_sound * 0.2f;
						sm->ef_volume = gm->eff_sound * 0.2f;
					}
				}
				else if (key_input == ENTER)
				{
					sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
					break;
				}
				
			}
		}
		else if (key_input == ESC)
		{
			sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
			ofstream writeFile;
			writeFile.open("data/user.txt");
			writeFile.clear();
			string str;
			str.append(to_string(gm->bg_sound));
			str.append(",;\n");
			writeFile.write(str.c_str(), 4);
			str.clear();
			str.append(to_string(gm->eff_sound));
			str.append(",;\n");
			writeFile.write(str.c_str(), 4);
			str.clear();
			str.append(to_string(gm->sync));
			str.append(",;\n");
			writeFile.write(str.c_str(), 4);
			str.clear();
			writeFile.close();
			return;
		}
	}
}