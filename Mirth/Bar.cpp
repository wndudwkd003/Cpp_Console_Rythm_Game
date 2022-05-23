#include "Bar.h"
Bar::Bar()
{
	state = 0;
	create_flag = false;
	flag = false;
	sprite[0] = "牟收收收收收收收收收收收收收汕";
	sprite[1] = "汎收收收收收收收收收收收收收汛";
	m_time = 0;
	s_time = 0;
	ms_time = 0;
	time = 0;
	key = 'a';
}
Bar::Bar(vector<string> gm_note)
{
	state = 0;
	create_flag = false;
	flag = false;
	sprite[0] = "牟收收收收收收收收收收收收收汕";
	sprite[1] = "汎收收收收收收收收收收收收收汛";
	m_time = stoi(gm_note[0]);
	s_time = stoi(gm_note[1]);
	ms_time = stoi(gm_note[2]);
	time = m_time * 60000 + s_time * 1000 + ms_time;
	key = gm_note[3].front();
	switch (key)
	{
	case 'a':
		cre_coord.push_back(5);
		cre_coord.push_back(3);
		break;
	case 's':
		cre_coord.push_back(23);
		cre_coord.push_back(3);
		break;
	case 'd':
		cre_coord.push_back(43);
		cre_coord.push_back(3);
		break;
	case 'j':
		cre_coord.push_back(63);
		cre_coord.push_back(3);
		break;
	case 'k':
		cre_coord.push_back(83);
		cre_coord.push_back(3);
		break;
	case 'l':
		cre_coord.push_back(103);
		cre_coord.push_back(3);
		break;
	default:
		break;
	}
	now_coord.push_back(cre_coord[0]);
	now_coord.push_back(cre_coord[1]);
}

vector<int> Bar::get_move_bar(vector<int> coord)
{
	now_coord[0] = coord[0];
	now_coord[1] = coord[1] + 1;
	return now_coord;
}





