#pragma once

#include "fmod.hpp"
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "SoundManager.h"

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define ENTER 13
#define SPECIAL_VALUE 224
#define ESC 27

using namespace std;
using namespace FMOD;
class GameManager
{
public:
	string ver = "1.0.0";
	int room_number;

	double time;
	double end_time;
	int m_time;
	int s_time;
	int ms_time;
	int state;
	int end_m_time;
	int end_s_time;
	int end_ms_time;


	vector<vector<string>> note[3];
	vector<vector<string>> setting;
	vector<vector<string>> score;
	vector<vector<string>> read_text(const string);

	int bg_sound;
	int eff_sound;
	int sync;

	GameManager();
	void time_clear();
	void time_start();
	void time_stop();
	void set_music_time(int, int , int);
	vector<vector<string>> get_note(int);
};

void gotoxy(short x, short y);
void selec(GameManager*, SoundManager*);
int p_lobby_room(GameManager*, SoundManager*);
int p_start_room(GameManager*, SoundManager*);
void p_game_help(GameManager*, SoundManager*);
void p_game_setting(GameManager*, SoundManager*);
void p_game_exit();
void play_room(int, GameManager*, SoundManager*);