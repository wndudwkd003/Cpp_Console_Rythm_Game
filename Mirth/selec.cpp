#include "GameManager.h"
void selec(GameManager* gm, SoundManager* sm)
{
    short u_select_num = p_start_room(gm, sm);

    switch (u_select_num)
    {
    default:
        break;
    case 27:
    {
        int select = p_lobby_room(gm, sm);
        if (select == 0)
        {
            selec(gm, sm);
        }
        else
        {
            play_room(select, gm, sm);
        }
        break;
    }
    case 29:
        p_game_help(gm, sm);
        selec(gm, sm);
        break;
    case 31:
        p_game_setting(gm, sm);
        selec(gm, sm);
        break;
    case 33:
        p_game_exit();
        break;
    }
}