#include "GameManager.h"

void p_game_help(GameManager* gm, SoundManager* sm)    // 도움말
{
	system("mode con: cols=136 lines=40");
	sm->channel[0]->setVolume(sm->bg_volume);
	sm->channel[3]->setVolume(sm->ef_volume);
	sm->channel[4]->setVolume(sm->ef_volume);
	int select = 35;	// 기본값
	int key_input = 0;

	// 테두리 

	for (int i = 2; i < 132; i++)
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
		gotoxy(132, i);
		cout << "□";
	}
	for (int i = 2; i < 132; i++)
	{
		gotoxy(i, 38);
		cout << "□";
	}

	gotoxy(54, 5);
	cout << "Mirth 리듬 게임에 오신것을 환영합니다.";
	gotoxy(35, 9);
	cout << "이 게임은 노래를 들으며 플레이 하는 게임이며 수록된 곡은 총 3곡입니다.";
	gotoxy(20, 11);
	cout << "플레이 방법은 노래의 리듬과 위에서 내려오는 바(Bar)들의 타이밍에 맞춰서 키보드를 누르시면 됩니다.";
	gotoxy(18, 13);
	cout << "타이밍에 정확도에 따라서 Excellent, Good, Bad의 점수가 부여되며 노래가 끝나면 최종 점수가 기록됩니다.";
	gotoxy(24, 15);
	cout << "바(Bar)는 총 6개의 위치에서 내려오며 A, S, D, J, K, L 버튼을 눌러서 플레이 하시면 됩니다.";
	gotoxy(44, 17);
	cout << "선택은 Enter, 뒤로가기는 ESC 버튼을 누르시면 됩니다.";
	gotoxy(8, 22);
	cout << "권장하지는 않지만 게임 풀더안의 MP3파일의 이름을 그대로 하고 다른 MP3파일로 대체하면 다른 음악으로 플레이할 수 있습니다.";
	gotoxy(23, 24);
	cout << "이 경우 풀더안의 바(Bar)의 타이밍도 직접 입력해야 하며 노트 저장 프로그램은 풀더 안에 있습니다.";
	gotoxy(40, 29);
	cout << "음악 정보와 저작권 관련은 풀더안의 메모장을 확인해 주세요.";
	gotoxy(50, 34);
	cout << "메인 화면으로 돌아가려면 ESC를 누르세요.";

	while (true)
	{
		if (_getch() == ESC)
		{
			sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
			return;
		}
	}
}
