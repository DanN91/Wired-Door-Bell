/*
    File: BuzzerPlayer.cpp
    Author: Arduino.cc
    Website: https://www.arduino.cc/en/Tutorial/PlayMelody

    Adaptations made by Daniel Nistor
*/

#include "BuzzerPlayer.h"

BuzzerPlayer::BuzzerPlayer(byte pwmPin)
 : m_buzzerPin(pwmPin)
{
    // nothing more
}

void BuzzerPlayer::Initialize() const
{
    pinMode(m_buzzerPin, OUTPUT);
}

void BuzzerPlayer::Play(Song song) const
{
    Serial.println("NotesCount: " + String(song.notesCount));

    // play all notes in the song
    for (byte i = 0; i < song.notesCount; ++i)
    {
        // play note
        Play(song.notes[i]);
        // and pause between each note? in percent
        delay(((1000 / song.notes[i].beats) * song.pause) / 100);
    }
}

// Pulse the speaker to play a tone for a particular duration
void BuzzerPlayer::Play(Note note) const
{
    // 
    tone(m_buzzerPin, note.frequency);

    // hold the tone according to its value
    delay(1000 / note.beats);

    // 
    noTone(m_buzzerPin);
}