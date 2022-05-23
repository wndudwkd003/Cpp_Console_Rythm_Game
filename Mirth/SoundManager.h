#pragma once
#include "fmod.hpp"

using namespace FMOD;

class SoundManager
{
public:
    System* system;
    Sound** sound;
    Channel** channel;
    float bg_volume;
    float ef_volume;
    void* extradriverdata;
    SoundManager();
    ~SoundManager();
    void sound_control();
};

