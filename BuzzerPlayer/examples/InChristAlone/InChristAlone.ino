/* In Christ Alone */

#include <BuzzerPlayer.h>

BuzzerPlayer buzzer(11);

constexpr Note MELODY[]
{
    // Verse One: In Christ Alone, My hope is found
    { NOTE_D3, BPS::Two },
    { NOTE_E3, BPS::Two },
    { NOTE_G3, BPS::Four },
    { NOTE_G3, BPS::Four },
    { NOTE_G3, BPS::One }, { NOTE_G3, BPS::Two },

    { NOTE_D3, BPS::Two },
    { NOTE_E3, BPS::Two },
    { NOTE_G3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::One },

    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::Four },
    { NOTE_G3, BPS::Four },
    { NOTE_E3, BPS::Two },
    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::Two },
    { NOTE_G3, BPS::Two },
    { NOTE_G3, BPS::One }, { NOTE_G3, BPS::Two },

    { NOTE_D3, BPS::Two },
    { NOTE_E3, BPS::Two },
    { NOTE_G3, BPS::Four },
    { NOTE_G3, BPS::Four },
    { NOTE_G3, BPS::One }, { NOTE_G3, BPS::Two },

    { NOTE_D3, BPS::Two },
    { NOTE_E3, BPS::Two },
    { NOTE_G3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::One },

    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::Four },
    { NOTE_G3, BPS::Four },
    { NOTE_E3, BPS::Two },
    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::Two },
    { NOTE_G3, BPS::Two },
    { NOTE_G3, BPS::One }, { NOTE_G3, BPS::Two },

    // Chorus: What heights of love, What depths of peace
    { NOTE_G3, BPS::Two },
    { NOTE_B3, BPS::Two },
    { NOTE_D4, BPS::Two },
    { NOTE_E4, BPS::One }, { NOTE_E4, BPS::Two },
    { NOTE_E4, BPS::Two },
    { NOTE_D4, BPS::Two },
    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::Two },

    { NOTE_G3, BPS::Two },
    { NOTE_G4, BPS::Two },
    { NOTE_FS4, BPS::Two },
    { NOTE_E4, BPS::One }, { NOTE_E4, BPS::Two },
    { NOTE_E4, BPS::Two },
    { NOTE_D4, BPS::Two },
    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::Two },

    // My Comforter, My All in All
    { NOTE_D3, BPS::Two },
    { NOTE_E3, BPS::Two },
    { NOTE_G3, BPS::Four },
    { NOTE_G3, BPS::Four },
    { NOTE_G3, BPS::One }, { NOTE_G3, BPS::Two },

    { NOTE_D3, BPS::Two },
    { NOTE_E3, BPS::Two },
    { NOTE_G3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::One },

    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::Four },
    { NOTE_G3, BPS::Four },
    { NOTE_E3, BPS::Two },
    { NOTE_B3, BPS::Two },
    { NOTE_A3, BPS::One }, { NOTE_A3, BPS::Two },
    { NOTE_G3, BPS::Two },
    { NOTE_G3, BPS::One }, { NOTE_G3, BPS::Two },
};

const Song InChristAlone { MELODY, sizeof(MELODY)/sizeof(Note), 80, 2 };

void setup()
{
    Serial.begin(57600);

    buzzer.Initialize();

    Serial.println("*** Buzzer Player Ready ***");
};

// #DNN:ToDo, See Debounce example and make a class for a PushButton with state

void loop()
{
    buzzer.Play(InChristAlone);

    delay(10000);
}