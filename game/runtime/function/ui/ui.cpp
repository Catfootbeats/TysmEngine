#include "ui.hpp"

#include <SDL_mouse.h>
#include <SDL_stdinc.h>

namespace Tysm {

bool UI::MouseOver()
{
    int mouseX, mouseY;
    Uint32 button = SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= m_pos.x && mouseX <= m_pos.x + m_width && mouseY >= m_pos.y &&
        mouseY <= m_pos.y - m_height) {
        return true;
    } else {
        return false;
    }
}

bool UI::OnLeftClick()
{
    int mouseX, mouseY;
    bool isOver;
    Uint32 button = SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= m_pos.x && mouseX <= m_pos.x + m_width && mouseY >= m_pos.y &&
        mouseY <= m_pos.y - m_height) {
        isOver = true;
    } else {
        isOver = false;
    }
    if (isOver && (button & SDL_BUTTON(SDL_BUTTON_LEFT))){
        return true;
    }else {
    return false;
    }
}

bool UI::OnRightClick()
{
    int mouseX, mouseY;
    bool isOver;
    Uint32 button = SDL_GetMouseState(&mouseX, &mouseY);
    if (mouseX >= m_pos.x && mouseX <= m_pos.x + m_width && mouseY >= m_pos.y &&
        mouseY <= m_pos.y - m_height) {
        isOver = true;
    } else {
        isOver = false;
    }
    if (isOver && (button & SDL_BUTTON(SDL_BUTTON_RIGHT))){
        return true;
    }else {
    return false;
    }
}

}  // namespace Tysm
