#include "GameManager.h"

void p_game_help(GameManager* gm, SoundManager* sm)    // ����
{
	system("mode con: cols=136 lines=40");
	sm->channel[0]->setVolume(sm->bg_volume);
	sm->channel[3]->setVolume(sm->ef_volume);
	sm->channel[4]->setVolume(sm->ef_volume);
	int select = 35;	// �⺻��
	int key_input = 0;

	// �׵θ� 

	for (int i = 2; i < 132; i++)
	{
		gotoxy(i, 1);
		cout << "��";
	}
	for (int i = 2; i < 38; i++)
	{
		gotoxy(2, i);
		cout << "��";
	}
	for (int i = 2; i < 38; i++)
	{
		gotoxy(132, i);
		cout << "��";
	}
	for (int i = 2; i < 132; i++)
	{
		gotoxy(i, 38);
		cout << "��";
	}

	gotoxy(54, 5);
	cout << "Mirth ���� ���ӿ� ���Ű��� ȯ���մϴ�.";
	gotoxy(35, 9);
	cout << "�� ������ �뷡�� ������ �÷��� �ϴ� �����̸� ���ϵ� ���� �� 3���Դϴ�.";
	gotoxy(20, 11);
	cout << "�÷��� ����� �뷡�� ����� ������ �������� ��(Bar)���� Ÿ�ֿ̹� ���缭 Ű���带 �����ø� �˴ϴ�.";
	gotoxy(18, 13);
	cout << "Ÿ�ֿ̹� ��Ȯ���� ���� Excellent, Good, Bad�� ������ �ο��Ǹ� �뷡�� ������ ���� ������ ��ϵ˴ϴ�.";
	gotoxy(24, 15);
	cout << "��(Bar)�� �� 6���� ��ġ���� �������� A, S, D, J, K, L ��ư�� ������ �÷��� �Ͻø� �˴ϴ�.";
	gotoxy(44, 17);
	cout << "������ Enter, �ڷΰ���� ESC ��ư�� �����ø� �˴ϴ�.";
	gotoxy(8, 22);
	cout << "���������� ������ ���� Ǯ������ MP3������ �̸��� �״�� �ϰ� �ٸ� MP3���Ϸ� ��ü�ϸ� �ٸ� �������� �÷����� �� �ֽ��ϴ�.";
	gotoxy(23, 24);
	cout << "�� ��� Ǯ������ ��(Bar)�� Ÿ�ֵ̹� ���� �Է��ؾ� �ϸ� ��Ʈ ���� ���α׷��� Ǯ�� �ȿ� �ֽ��ϴ�.";
	gotoxy(40, 29);
	cout << "���� ������ ���۱� ������ Ǯ������ �޸����� Ȯ���� �ּ���.";
	gotoxy(50, 34);
	cout << "���� ȭ������ ���ư����� ESC�� ��������.";

	while (true)
	{
		if (_getch() == ESC)
		{
			sm->system->playSound(sm->sound[5], 0, false, &sm->channel[4]);
			return;
		}
	}
}
