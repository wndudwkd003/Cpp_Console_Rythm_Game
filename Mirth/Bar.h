#pragma once
#include "GameManager.h"
class Bar
{
public:
	bool create_flag;
	bool flag;
	string sprite[2];
	vector<int> cre_coord;
	vector<int> now_coord;
	clock_t start_clock, finish_clock;
	int time;
	int m_time, s_time, ms_time;
	char key;
	int state;	// 0=no create, 1=perfect, 2=good, 3=bad
	Bar();
	Bar(vector<string>);
	vector<int> get_move_bar(vector<int>);
	
};
