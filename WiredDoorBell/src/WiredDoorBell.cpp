#include <Sound.h>
#include <Songs.h>

#include "WiredDoorBell.h"

using namespace Buzzer;

WiredDoorBell::WiredDoorBell(uint8_t playerPWMPin)
    : m_player(playerPWMPin)
{
}

void WiredDoorBell::Initialize() const
{
    m_player.Initialize();
}

void WiredDoorBell::WasPressed()
{
    m_player.Play(InChristAlone);
}