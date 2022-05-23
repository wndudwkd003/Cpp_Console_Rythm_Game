
#include "SoundManager.h"


SoundManager::SoundManager()
    :system(nullptr), channel(nullptr), sound(nullptr)
{
    System_Create(&system);
    sound = new Sound * [10];
    channel = new Channel * [5];
    bg_volume = 0;
    ef_volume = 0;

    system->init(5, FMOD_INIT_NORMAL, extradriverdata);
    system->createSound("data/mp3/Parzival - William Rosat.mp3", FMOD_LOOP_NORMAL, 0, &sound[0]);
    system->createSound("data/mp3/Lvly - Million.mp3", FMOD_INIT_NORMAL, 0, &sound[1]);
    system->createSound("data/mp3/AJR - Burn The House Down.mp3", FMOD_INIT_NORMAL, 0, &sound[2]);
    system->createSound("data/mp3/Unlike Pluto - Everything Black.mp3", FMOD_INIT_NORMAL, 0, &sound[3]);
    system->createSound("data/mp3/ButtonClick.wav", FMOD_INIT_NORMAL, 0, &sound[4]);
    system->createSound("data/mp3/InputSound.mp3", FMOD_INIT_NORMAL, 0, &sound[5]);
}

SoundManager::~SoundManager()
{
    if(channel != nullptr || sound != nullptr)
    {
        for (int i = 0; i < 5; i++)
        {
            if (channel != nullptr && channel[i])
                channel[i]->stop();
            if (sound != nullptr && sound[i])
                sound[i]->release();
        }
    }
    delete channel;
    delete sound;
    if (system != nullptr)
    {
        system->release();
        system->close();
    }
}

void SoundManager::sound_control()
{

}