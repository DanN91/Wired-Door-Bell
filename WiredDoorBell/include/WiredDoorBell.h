#pragma once

#include <Arduino.h>

#include <BuzzerPlayer.h>
#include <IPushButtonObserver.h>

using Buzzer::BuzzerPlayer;

class WiredDoorBell final : public IPushButtonObserver
{
public:
    explicit WiredDoorBell(uint8_t playerPWMPin);

    void Initialize() const;

    // IPushButtonObserver
    void WasPressed() override;

private:
    BuzzerPlayer m_player;
};