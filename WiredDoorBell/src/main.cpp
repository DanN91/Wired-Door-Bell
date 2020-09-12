/* Wired Door Bell */
#include <Arduino.h>

#include <WiredDoorBell.h>
#include <TogglePushButton.h>

// #DNN:Hardware: No R -> MAX; 10R * 2 -> Volume 2; 100R -> Volume 3
WiredDoorBell doorBell(5);
TogglePushButton button(2, doorBell);

void setup()
{
    doorBell.Initialize();
};

void loop()
{
    button.HandleEvents();
    delay(100);
}