#ifndef TEXT_BOX_HPP
#define TEXT_BOX_HPP

#include "box.hpp"
#include <ncurses.h>
#include <vector>
using namespace std;

namespace Engine {
namespace UI {

class TextBox : public Box {
private:
  const wchar_t *content;
  vector<wchar_t *> lines;

public:
  TextBox(uint16_t width, uint16_t height, const wchar_t *content);

  vector<wchar_t *> split_content();
  bsize_t size();
  void show(WINDOW *window, uint16_t x, uint16_t y);
};

} // namespace UI
} // namespace Engine

#endif // TEXT_BOX_HPP
