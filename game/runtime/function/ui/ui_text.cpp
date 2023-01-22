#include "ui_text.hpp"

namespace Tysm {
UI_Text::UI_Text(Position* pos,
                 const char* fontPath,
                 int fontSize,
                 std::string str,
                 SDL_Color fg,
                 SDL_Renderer* renderer)
{
    m_pos = pos;
    text = new Tysm::Text(fontPath, fontSize, renderer);
    fgColor = fg;
    m_str = str;
}

void UI_Text::show()
{
    text->RenderText(m_pos, m_str, fgColor);
}

UI_Text::~UI_Text()
{
    delete text;
}
}  // namespace Tysm
