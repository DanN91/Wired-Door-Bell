/*
    File: BuzzerPlayer.h
    Author: Arduino.cc
    Website: https://www.arduino.cc/en/Tutorial/PlayMelody

    Adaptations made by Daniel Nistor
*/

#pragma once

#include "Arduino.h"
#include "utility/Sound.h"

using namespace Buzzer;

class BuzzerPlayer
{
public:
    explicit BuzzerPlayer(byte pwmPin);
    void Initialize() const;

    void Play(Song song) const;
    void Play(Note note) const;

private:
    byte m_buzzerPin;
};
