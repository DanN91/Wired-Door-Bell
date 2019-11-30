/*
    #DNN:ToDo
*/
#include <Arduino.h>

namespace Buzzer
{
  enum NoteFrequency : uint16_t
  {
      NOTE_Rest = 0,
      NOTE_C0 = 16,
      NOTE_CS0 = 17,
      NOTE_D0 = 18,
      NOTE_DS0 = 19,
      NOTE_E0 = 21,
      NOTE_F0 = 22,
      NOTE_FS0 = 23,
      NOTE_G0 = 25,
      NOTE_GS0 = 26,
      NOTE_A0 = 28,
      NOTE_AS0 = 29,
      NOTE_B0 = 31,
      NOTE_C1 = 33,
      NOTE_CS1 = 35,
      NOTE_D1 = 37,
      NOTE_DS1 = 39,
      NOTE_E1 = 41,
      NOTE_F1 = 44,
      NOTE_FS1 = 46,
      NOTE_G1 = 49,
      NOTE_GS1 = 52,
      NOTE_A1 = 55,
      NOTE_AS1 = 58,
      NOTE_B1 = 62,
      NOTE_C2 = 65,
      NOTE_CS2 = 69,
      NOTE_D2 = 73,
      NOTE_DS2 = 78,
      NOTE_E2 = 82,
      NOTE_F2 = 87,
      NOTE_FS2 = 93,
      NOTE_G2 = 98,
      NOTE_GS2 = 104,
      NOTE_A2 = 110,
      NOTE_AS2 = 117,
      NOTE_B2 = 123,
      NOTE_C3 = 131,
      NOTE_CS3 = 139,
      NOTE_D3 = 147,
      NOTE_DS3 = 156,
      NOTE_E3 = 165,
      NOTE_F3 = 175,
      NOTE_FS3 = 185,
      NOTE_G3 = 196,
      NOTE_GS3 = 208,
      NOTE_A3 = 220,
      NOTE_AS3 = 233,
      NOTE_B3 = 247,
      NOTE_C4 = 262,
      NOTE_CS4 = 277,
      NOTE_D4 = 294,
      NOTE_DS4 = 311,
      NOTE_E4 = 330,
      NOTE_F4 = 349,
      NOTE_FS4 = 370,
      NOTE_G4 = 392,
      NOTE_GS4 = 415,
      NOTE_A4 = 440,
      NOTE_AS4 = 466,
      NOTE_B4 = 494,
      NOTE_C5 = 523,
      NOTE_CS5 = 554,
      NOTE_D5 = 587,
      NOTE_DS5 = 622,
      NOTE_E5 = 659,
      NOTE_F5 = 698,
      NOTE_FS5 = 740,
      NOTE_G5 = 784,
      NOTE_GS5 = 831,
      NOTE_A5 = 880,
      NOTE_AS5 = 932,
      NOTE_B5 = 988,
      NOTE_C6 = 1047,
      NOTE_CS6 = 1109,
      NOTE_D6 = 1175,
      NOTE_DS6 = 1245,
      NOTE_E6 = 1319,
      NOTE_F6 = 1397,
      NOTE_FS6 = 1480,
      NOTE_G6 = 1568,
      NOTE_GS6 = 1661,
      NOTE_A6 = 1760,
      NOTE_AS6 = 1865,
      NOTE_B6 = 1976,
      NOTE_C7 = 2093,
      NOTE_CS7 = 2217,
      NOTE_D7 = 2349,
      NOTE_DS7 = 2489,
      NOTE_E7 = 2637,
      NOTE_F7 = 2794,
      NOTE_FS7 = 2960,
      NOTE_G7 = 3136,
      NOTE_GS7 = 3322,
      NOTE_A7 = 3520,
      NOTE_AS7 = 3729,
      NOTE_B7 = 3951,
      NOTE_C8 = 4186,
      NOTE_CS8 = 4435,
      NOTE_D8 = 4699,
      NOTE_DS8 = 4978,
      NOTE_E8 = 5274,
      NOTE_F8 = 5588,
      NOTE_FS8 = 5920,
      NOTE_G8 = 6272,
      NOTE_GS8 = 6645,
      NOTE_A8 = 7040,
      NOTE_AS8 = 7459,
      NOTE_B8 = 7902
  };

  constexpr const byte MultiplyByTwo(byte number) { return number * 2; }

  enum BPS : byte
  {
      One = 1,
      Two = MultiplyByTwo(One),
      Four = MultiplyByTwo(Two),
      Eight = MultiplyByTwo(Four),
      Sixteen = MultiplyByTwo(Eight),
      ThirtyTwo = MultiplyByTwo(Sixteen)
  };

  struct Note
  {
      NoteFrequency frequency;
      BPS beats;
  };

  struct Song
  {
      Note* notes;
      byte notesCount;
      byte tempo;
      byte pause;
  };
} // Buzzer

/*
 * This could use a number of enhancements:
 * ADD code to let the programmer specify how many times the melody should
 *     loop before stopping
 * ADD another octave
 * MOVE tempo, pause, and rest_count to #define statements
 * RE-WRITE to include volume, using analogWrite, as with the second program at
 *          http://www.arduino.cc/en/Tutorial/PlayMelody
 * ADD code to make the tempo settable by pot or other input device
 * ADD code to take tempo or volume settable by serial communication
 *          (Requires 0005 or higher.)
 * ADD code to create a tone offset (higer or lower) through pot etc
 * REPLACE random melody with opening bars to 'Smoke on the Water'
/ MELODY and TIMING  =======================================
//  melody[] is an array of notes, accompanied by beats[],
//  which sets each note's relative length (higher #, longer note)
int melody[] = {  C,  b,  g,  C,  b,   e,  R,  C,  c,  g, a, C };
int beats[]  = { 16, 16, 16,  8,  8,  16, 32, 16, 16, 16, 8, 8 };
int MAX_COUNT = sizeof(melody) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone_ = 0;
int beat = 0;
long duration  = 0;

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    }
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                
}

// LET THE WILD RUMPUS BEGIN =============================
void loop() {
  // Set up a counter to pull from melody[] and beats[]
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    duration = beat * tempo; // Set up timing

    playTone();
    // A pause between notes...
    delayMicroseconds(pause);

    if (DEBUG) { // If debugging, report loop, tone, beat, and duration
      Serial.print(i);
      Serial.print(":");
      Serial.print(beat);
      Serial.print(" ");    
      Serial.print(tone_);
      Serial.print(" ");
      Serial.println(duration);
    }
  }
}
*/