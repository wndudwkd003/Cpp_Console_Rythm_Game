#include "GameManager.h"
#include "Bar.h"
#include <ctime>
#include <chrono>	// 시간관련 라이브러리
#include <array>
#pragma comment(lib, "winmm.lib")

using namespace std;

static int g_nScreenIndex;
static HANDLE g_hScreen[2];
time_t start_clock, finish_clock;

string play_score;
string play_time;

void ScreenPrint(short x, short y, string string);
void Render(int, GameManager*, Bar*, int);

array<bool, 6> keeyboard_flag;

int score_temp;

vector<int> sound_bar_coord;
double time_progress;

void play_room(int select_num, GameManager *gm, SoundManager *sm)    // 플레이 룸
{
	sound_bar_coord = { 128, 52 };
	time_progress = 0.05;

	system("mode con: cols=180 lines=60");
	bool flag = true;
	int key_input = 0;
	short u_select_num = 27;    // 27: "Game Start" 기본값

	//timeBeginPeriod(1); // timer interrupt 해상도를 1로 맞춥니다.
	
	// 이전에 나오던 배경음 정지
	sm->channel[0]->stop();
	
	CONSOLE_CURSOR_INFO cci;

	// 화면 버퍼 2개를 만든다.
	g_hScreen[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	g_hScreen[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

	// 커서를 숨긴다.
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(g_hScreen[0], &cci);
	SetConsoleCursorInfo(g_hScreen[1], &cci);

	// 바 인스턴스 생성
	int note_amount = gm->note[0].size();
	Bar* bar = new Bar[note_amount];
	for (int i = 0; i < note_amount; i++)
	{
		bar[i] = { gm->note->at(i)};
	}

	// gm에 노래가 끝나는 시간을 넣음
	gm->set_music_time(bar[note_amount - 1].m_time, bar[note_amount - 1].s_time, bar[note_amount - 1].ms_time);
	gm->end_time = gm->end_m_time * 60000 + gm->end_s_time * 1000 + gm->end_ms_time;

	// 타이머 시작
	auto startTime = std::chrono::system_clock::now();
	//start_clock = clock();


	while (1)
	{
		// 사운드 볼륨
		sm->channel[0]->setVolume(sm->bg_volume);
		sm->channel[3]->setVolume(sm->ef_volume);
		sm->channel[4]->setVolume(sm->ef_volume);
		sm->system->update();

		// 타이머 계산과 분, 초, 밀리초 계산
		//finish_clock = clock();
		//gm->ms_time = finish_clock - start_clock;
		auto endTime = std::chrono::system_clock::now();
		auto msec = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - startTime);
		gm->ms_time = msec.count();
		gm->s_time = gm->ms_time / CLOCKS_PER_SEC;
		gm->ms_time = gm->ms_time % CLOCKS_PER_SEC;
		gm->m_time = gm->s_time / 60;
		gm->s_time = gm->s_time % 60;

		// 테스트용 타이머
		gm->time = gm->m_time * 60000 + gm->s_time * 1000 + gm->ms_time;
		

		// 배경음 나오는 싱크 조절 아직 미완성
		if (gm->s_time == 1 && to_string(gm->ms_time)[0] >= '0' && to_string(gm->ms_time)[1] >= '1' && flag == true)
		{
			flag = false;
			sm->system->playSound(sm->sound[select_num], 0, false, &sm->channel[0]);
		}

		// 그리기
		Render(select_num, gm, bar, note_amount);

		// 키보드 입력, 전에 입력했었고 아직 키보드를 누르고 있었으면 작동안하게 했지만
		// 요즘 키보드는 무한 입력이 기본이라 제대로 작동은 안합니다
		if (GetAsyncKeyState(0x41) & 0x0001)
		{
			keeyboard_flag[0] = true;
			// a
			sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
		}
		else
		{
			keeyboard_flag[0] = false;
		}
		
		if (GetAsyncKeyState(0x53) & 0x0001)
		{
			// s
			keeyboard_flag[1] = true;
			sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
		}
		else
		{

			keeyboard_flag[1] = false;
		}
		if (GetAsyncKeyState(0x44) & 0x0001)
		{
			// d
			keeyboard_flag[2] = true;
			sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
		}
		else
		{
			keeyboard_flag[2] = false;
		}
		if (GetAsyncKeyState(0x4A) & 0x0001)
		{
			// j
			keeyboard_flag[3] = true;
			sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
		}
		else
		{
			keeyboard_flag[3] = false;
		}
		if (GetAsyncKeyState(0x4B) & 0x0001)
		{
			// k
			keeyboard_flag[4] = true;
			sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
		}
		else
		{
			keeyboard_flag[4] = false;
		}
		if (GetAsyncKeyState(0x4C) & 0x0001)
		{
			// l
			keeyboard_flag[5] = true;
			sm->system->playSound(sm->sound[4], 0, false, &sm->channel[3]);
		}
		else
		{
			keeyboard_flag[5] = false;
		}
		if (_kbhit())
		{
			key_input = _getch();
			
			
			if (key_input == SPECIAL_VALUE)
			{
				key_input = _getch();
				
			}
			else if (key_input == ENTER)
			{
				sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);

				break;  // 엔터 누르고 선택된 번호 return
			}
		}
	}

	CloseHandle(g_hScreen[0]);
	CloseHandle(g_hScreen[1]);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // 콘솔창의 핸들을 얻어옴
	COORD bufferSize = { 200, 3000 }; // 버퍼의 크기
	SetConsoleScreenBufferSize(hConsole, bufferSize); // 콘솔창 버퍼의 크기를 설정
	cout << gm->time << " " << gm->end_time << endl;
	cout << gm->time / gm->end_time << endl;

	for (int i = 0; i < note_amount; i++)
	{
		cout << i << " " << bar[i].flag << " " << bar[i].time << " " << endl;
	}
	//timeEndPeriod(1); // timer interrupt 초기화
}

void Render(int select_num, GameManager* gm, Bar* bar, int note_amount)
{
	COORD Coor = { 0, 0 };
	DWORD dw;
	FillConsoleOutputCharacter(g_hScreen[g_nScreenIndex], ' ', 180 * 60, Coor, &dw);

	ScreenPrint(0, 5, "                                                                                                                                 .BBBb   5BBBBr  QBBBBBB  2BBBBBB  BBBBBg   ");
	ScreenPrint(0, 6, "                                                                                                                                 DB5    BBi     BQ     BB rB    BQ          ");
	ScreenPrint(0, 7, "                                                                                                                                   SgBP BB      QR     7B .B  JZBY BBBBB    ");
	ScreenPrint(0, 8, "                                                                                                                                     BB KBQ     BBr   .BB vB. BB:  BB       ");
	ScreenPrint(0, 9, "                                                                                                                                  UBBB.   BBQBj  rBBBBBS  rB   BQ  BBBBBQ   ");
	ScreenPrint(0, 10, "                                                                                                                                                                BB          ");
	ScreenPrint(0, 11, "                                                                                                                                                                rB          ");

	play_score = "【   " + gm->score[select_num-1][0] + "   】";
	ScreenPrint(142, 16, play_score);

	ScreenPrint(0, 22, "                                                                                                                             BBBb SB      BBr   Bq  BQ  BBBBB PB BB   BBi.BB ");
	ScreenPrint(0, 23, "                                                                                                                                B RQ     ZBBB   vB  B   .rBb  BB BB   BBS       ");
	ScreenPrint(0, 24, "                                                                                                                             BQBB.ZB    iBU BB   :BB      BL  BB BEB BrB7.BB  ");
	ScreenPrint(0, 25, "                                                                                                                             Bi:  BB    BB   BB   BB     .BK  BB BB BS B7       ");
	ScreenPrint(0, 26, "                                                                                                                             r    :XDQ  d    iBP  qr      d.  rS U:    B2 2d ");

	play_time = "【   " + ((gm->m_time < 10) ? "0" + to_string(gm->m_time) : to_string(gm->m_time))
				+ "  :  " + ((gm->s_time < 10) ? "0" + to_string(gm->s_time) : to_string(gm->s_time))
				+ "  :  " + to_string(gm->ms_time)[0] + to_string(gm->ms_time)[1] + "  】";

	ScreenPrint(138, 33, play_time);

	if (gm->state == 1)
	{

		ScreenPrint(0, 39, "                                                                                                                                         iMZZX      kV     JRDgI    ");
		ScreenPrint(0, 40, "                                                                                                                                          i  SQi   gQBB    vvrrgQQ  ");
		ScreenPrint(0, 41, "                                                                                                                                          ULvZBi  vBi BX        iBJ ");
		ScreenPrint(0, 42, "                                                                                                                                          ii  BB  Bg  LBi       dBi ");
		ScreenPrint(0, 43, "                                                                                                                                          ZPqKBZ BB    BB  IBQBBBi  ");
		ScreenPrint(0, 44, "                                                                                                                                          iiii   i      BB iiii     ");
		ScreenPrint(0, 45, "                                                                                                                                                         Q          ");

	}
	else if (gm->state == 2)
	{
		ScreenPrint(0, 39, "                                                                                                                                  iEBBQBi  iDBBBV    iBBBBJ   UBBBBL    ");
		ScreenPrint(0, 40, "                                                                                                                                 QBv      JBJ   EBi QBr   BB      iQB   ");
		ScreenPrint(0, 41, "                                                                                                                                iBr  iXKv QS     BB Bi     BB       BB  ");
		ScreenPrint(0, 42, "                                                                                                                                 BB    BB BB    iBk BB    rBv      LBv  ");
		ScreenPrint(0, 43, "                                                                                                                                  KBRuvBB  kBBgBQv   RBBMBBi  kBBBQBi   ");
		ScreenPrint(0, 44, "                                                                                                                                       BB     i         i               ");
		ScreenPrint(0, 45, "                                                                                                                                       IB                               ");
	}
	else if (gm->state == 3)
	{
		ScreenPrint(0, 39, "                                                                                                                            RDb   IDZZRi iKgQg   PgbgR  REZZM    vZMr PqLkgX  ");
		ScreenPrint(0, 40, "                                                                                                                           vgPgBQ ikJkq  BBPuDBB YJuUb  SuJIU  BBBQB  QBQBgi  ");
		ScreenPrint(0, 41, "                                                                                                                               BB  ruIv  BB   BB ivuKi  vvuS  PBU       BL    ");
		ScreenPrint(0, 42, "                                                                                                                           BBBBB  BBir   BB dBB  BBUP  iBBii  YBQ       BP    ");
		ScreenPrint(0, 43, "                                                                                                                           BB     BBQBBv BB  BB  BB    iBBQBB  SBQBBZ   BM    ");
		ScreenPrint(0, 44, "                                                                                                                                    iii       BB          ii      ir          ");
		ScreenPrint(0, 45, "                                                                                                                                              iB                              ");
	}
      
	// 화면 테두리 및 칸 나누기
	for (int i = 2; i < 176; i++)
	{
		ScreenPrint(i, 1, "□");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(2, i, "□");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(176, i, "□");
	}
	for (int i = 2; i < 176; i++)
	{
		ScreenPrint(i, 58, "□");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(120, i, "□");
	}
	for (int i = 4; i < 119; i++)
	{
		ScreenPrint(i, 52, "─");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(21, i, "│");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(40, i, "│");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(60, i, "│");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(80, i, "│");
	}
	for (int i = 2; i < 58; i++)
	{
		ScreenPrint(100, i, "│");
	}

	// 재생 바
	for (int i = 127; i <= 169; i++)
	{
		ScreenPrint(i, 52, "━");
	}
	ScreenPrint(127, 52, "■");
	ScreenPrint(169, 52, "■");

	// 현재 시간과 끝나는 시간을 비교해서 재생구간 표시
	if (gm->time / gm->end_time >= time_progress / 2)
	{
		time_progress += 0.05;
		sound_bar_coord[0]++;
	}
	ScreenPrint(sound_bar_coord[0], sound_bar_coord[1], "●");

	// 키보드 누른 효과
	if (keeyboard_flag[0])
	{
		ScreenPrint(4, 2, "┍━━━━━━━━━━━━━━━┑");
		for (int i = 3; i < 57; i++)
		{
			ScreenPrint(4, i, "│               │");
		}
		ScreenPrint(5, 52, "───────────────");
		ScreenPrint(4, 57, "┕━━━━━━━━━━━━━━━┙");
	}

	if (keeyboard_flag[1])
	{
		ScreenPrint(22, 2, "┍━━━━━━━━━━━━━━━━┑");
		for (int i = 3; i < 57; i++)
		{
			ScreenPrint(22, i, "│                │");
		}
		ScreenPrint(23, 52, "────────────────");
		ScreenPrint(22, 57, "┕━━━━━━━━━━━━━━━━┙");
	}
	if (keeyboard_flag[2])
	{
		ScreenPrint(41, 2, "┍━━━━━━━━━━━━━━━━━┑");
		for (int i = 3; i < 57; i++)
		{
			ScreenPrint(41, i, "│                 │");
		}
		ScreenPrint(42, 52, "─────────────────");
		ScreenPrint(41, 57, "┕━━━━━━━━━━━━━━━━━┙");
	}
	if (keeyboard_flag[3])
	{
		ScreenPrint(61, 2, "┍━━━━━━━━━━━━━━━━━┑");
		for (int i = 3; i < 57; i++)
		{
			ScreenPrint(61, i, "│                 │");
		}
		ScreenPrint(62, 52, "─────────────────");
		ScreenPrint(61, 57, "┕━━━━━━━━━━━━━━━━━┙");
	}
	if (keeyboard_flag[4])
	{
		ScreenPrint(81, 2, "┍━━━━━━━━━━━━━━━━━┑");
		for (int i = 3; i < 57; i++)
		{
			ScreenPrint(81, i, "│                 │");
		}
		ScreenPrint(82, 52, "─────────────────");
		ScreenPrint(81, 57, "┕━━━━━━━━━━━━━━━━━┙");
	}

	if (keeyboard_flag[5])
	{
		ScreenPrint(101, 2, "┍━━━━━━━━━━━━━━━━┑");
		for (int i = 3; i < 57; i++)
		{
			ScreenPrint(101, i, "│                │");
		}
		ScreenPrint(102, 52, "────────────────");
		ScreenPrint(101, 57, "┕━━━━━━━━━━━━━━━━┙");
	}

	// 내려오는 노트들의 상태 체크 및 내려오는 코드
	// 키보드 눌렀을 때 상태도 체크 함
	for (int i = 0; i < note_amount; i++)
	{
		// 노트(바)들을 미리 정의된 시간에 맞춰서 생성 하도록 함
		// 밀리초 부분을 ==으로 하면 생성조차 안되는 것이 많음
		if (bar[i].m_time == gm->m_time && bar[i].s_time == gm->s_time &&
			to_string(bar[i].ms_time)[0] == to_string(gm->ms_time)[0] &&
			to_string(bar[i].ms_time)[1] >= to_string(gm->ms_time)[1])
		{
			bar[i].create_flag = true;
			bar[i].flag = true;
		}

		if (bar[i].create_flag == true)
		{
			// 노트(바)들이 밑으로 내려가도록
			vector<int> vec = bar[i].get_move_bar({ bar[i].now_coord[0], bar[i].now_coord[1] });
			ScreenPrint(vec[0], vec[1] - 1, bar[i].sprite[0]);
			ScreenPrint(vec[0], vec[1], bar[i].sprite[1]);

			// 노트들이 끝에 닿으면 제거
			if (bar[i].now_coord[1] >= 57)
			{
				bar[i].state = 3;
				bar[i].create_flag = false;

				gm->state = 1;
			}
			// 타이밍 맞추기
			else if (bar[i].now_coord[1] >= 56)
			{
				if ((bar[i].key == 'a' && keeyboard_flag[0]) ||
					(bar[i].key == 's' && keeyboard_flag[1]) ||
					(bar[i].key == 'd' && keeyboard_flag[2]) ||
					(bar[i].key == 'j' && keeyboard_flag[3]) ||
					(bar[i].key == 'k' && keeyboard_flag[4]) ||
					(bar[i].key == 'l' && keeyboard_flag[5]))
				{
					bar[i].state = 2;
					bar[i].create_flag = false;

					score_temp = 0;
					score_temp = stoi(gm->score[select_num - 1][0]);
					score_temp += 100;
					gm->score[select_num - 1][0] = to_string(score_temp);

					gm->state = 2;
				}
			}
			else if (bar[i].now_coord[1] >= 55)
			{
				if ((bar[i].key == 'a' && keeyboard_flag[0]) ||
					(bar[i].key == 's' && keeyboard_flag[1]) ||
					(bar[i].key == 'd' && keeyboard_flag[2]) ||
					(bar[i].key == 'j' && keeyboard_flag[3]) ||
					(bar[i].key == 'k' && keeyboard_flag[4]) ||
					(bar[i].key == 'l' && keeyboard_flag[5]))
				{
					bar[i].state = 1;
					bar[i].create_flag = false;

					score_temp = 0;
					score_temp = stoi(gm->score[select_num - 1][0]);
					score_temp += 500;
					gm->score[select_num - 1][0] = to_string(score_temp);

					gm->state = 3;
				}
			}
			else if (bar[i].now_coord[1] >= 53)
			{
				if ((bar[i].key == 'a' && keeyboard_flag[0]) ||
					(bar[i].key == 's' && keeyboard_flag[1]) ||
					(bar[i].key == 'd' && keeyboard_flag[2]) ||
					(bar[i].key == 'j' && keeyboard_flag[3]) ||
					(bar[i].key == 'k' && keeyboard_flag[4]) ||
					(bar[i].key == 'l' && keeyboard_flag[5]))
				{
					bar[i].state = 2;
					bar[i].create_flag = false;

					score_temp = 0;
					score_temp = stoi(gm->score[select_num - 1][0]);
					score_temp += 100;
					gm->score[select_num - 1][0] = to_string(score_temp);

					gm->state = 2;
				}
			}
			else if (bar[i].now_coord[1] >= 52)
			{
				if ((bar[i].key == 'a' && keeyboard_flag[0]) ||
					(bar[i].key == 's' && keeyboard_flag[1]) ||
					(bar[i].key == 'd' && keeyboard_flag[2]) ||
					(bar[i].key == 'j' && keeyboard_flag[3]) ||
					(bar[i].key == 'k' && keeyboard_flag[4]) ||
					(bar[i].key == 'l' && keeyboard_flag[5]))
				{
					bar[i].state = 3;
					bar[i].create_flag = false;

					gm->state = 1;
				}
			}
			
		}
	}

	SetConsoleActiveScreenBuffer(g_hScreen[g_nScreenIndex]);
	g_nScreenIndex = !g_nScreenIndex;
}

void ScreenPrint(short x, short y, string string)
{
	DWORD dw;
	COORD CursorPosition = { x, y };
	SetConsoleCursorPosition(g_hScreen[g_nScreenIndex], CursorPosition);
	WriteFile(g_hScreen[g_nScreenIndex], string.c_str(), strlen(string.c_str()), &dw, NULL);
}
