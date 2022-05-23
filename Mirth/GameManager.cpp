#include "GameManager.h"

void gotoxy(short x, short y)
{
    COORD pos = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}

GameManager::GameManager()
{
    setting = read_text("data/user.txt");
    score = read_text("data/score.txt");
    bg_sound = stoi(setting[0][0]);
    eff_sound = stoi(setting[1][0]);
    sync = stoi(setting[2][0]);

    note[0] = read_text("data/Lvly - Million.txt");
    note[1] = read_text("data/AJR - Burn The House Down.txt");
    note[2] = read_text("data/Unlike Pluto - Everything Black.txt");
    state = 0;
}

void GameManager::set_music_time(int m, int s, int ms)
{
    this->end_m_time = m;
    this->end_s_time = s;
    this->end_ms_time = ms;
}
void GameManager::time_clear()
{
    m_time = 0;
    s_time = 0;
    ms_time = 0;
}
void GameManager::time_start()
{

}
void GameManager::time_stop()
{

}

vector<vector<string>> GameManager::get_note(int i)
{
    return note[i];
}


vector<vector<string>> GameManager::read_text(const string uri)
{
    string ch;
    string ch_tmp;
    vector<vector<string>> vec;
    ifstream textf(uri);
    if (textf.is_open())
    {
        vector<string> tmp;
        while (!textf.eof())
        {
            ch = textf.get();
            if (ch == ";")
            {
                vec.push_back(tmp);
                tmp.clear();
                continue;
            }
            else if (ch != " " && ch != "\n" && ch != "\0")
            {
                if (ch != ",")
                {
                    ch_tmp.append(ch);
                }
                else
                {
                    tmp.push_back(ch_tmp);
                    ch_tmp = "";
                }
            }
        }
        textf.close();
    }
    else
    {
        cout << "파일을 열 수 없습니다." << endl;
    }
    return vec;
}

