#include "button.hpp"

Engine::UI::Button::Button(uint16_t max_width, uint16_t max_height,
                           const wchar_t *content)
    : TextBox(max_width - 2, max_height - 2, content) {}
Engine::UI::Button::Button(uint16_t max_width, uint16_t max_height,
                           Nostd::WString &&content)
    : TextBox(max_width - 2, max_height - 2, content.c_str()) {}
Engine::UI::Button::~Button() {
  delwin(button_window);
  button_window = nullptr;
}

void Engine::UI::Button::show(WINDOW *window, uint16_t x, uint16_t y) {
  auto osize = TextBox::size();
  uint16_t abs_x, abs_y;
  getbegyx(window, abs_y, abs_x);

  if (button_window != nullptr)
    delwin(button_window);

  button_window =
      newwin(osize.second + 2, osize.first + 2, abs_y + y, abs_x + x);
  wclear(button_window);
  refresh();

  int color = color_pair();
  if (color != -1)
    wbkgd(button_window, color);

  // draw a box of ' ' chars to around the text to fill the background
  mvwhline(button_window, 0, 1, ' ', osize.first);
  mvwvline(button_window, 0, 0, ' ', osize.second + 2);
  mvwvline(button_window, 0, osize.first + 1, ' ', osize.second + 2);
  mvwhline(button_window, osize.second + 1, 1, ' ', osize.first);

  TextBox::show(button_window, 1, 1);
  refresh();
  wrefresh(button_window);
}
Nostd::Pair<uint16_t, uint16_t> Engine::UI::Button::size() {
  auto osize = TextBox::size();
  uint16_t width = osize.first + 2, height = osize.second + 2;
  return {width, height};
}
