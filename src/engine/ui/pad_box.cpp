#include "pad_box.hpp"
#include <stdarg.h>
using namespace Engine::UI;

PadBox::PadBox(uint8_t max_width, uint8_t max_height,
               map<enum PAD, uint16_t> pads)
    : Box(max_width, max_height) {
  this->pads = pads;
  for (map<enum PAD, uint16_t>::iterator it = pads.begin(); it != pads.end();
       it++) {
    switch (it->first) {
    case PADDING_LEFT:
      pl = it->second;
    case PADDING_RIGHT:
      pr = it->second;
    case PADDING_TOP:
      pt = it->second;
    case PADDING_BOTTOM:
      pb = it->second;
    }
  }

  this->max_width = max_width - this->pl - this->pr;
  this->max_height = max_width - this->pt - this->pb;
}

template <typename T, typename A>
T append(Box *target, float w, float h, A arg) {
  uint16_t width = target->max_width * min(w, (float)1);
  uint16_t height = target->max_height * min(h, (float)1);
  T *box = new T(width, height, arg);
  target->add_child(box);
  return box;
}

// Creates a new PadBox instance and adds it to the target Box's children.
PadBox *PadBox::append(Box *target, float w, float h,
                       map<enum PAD, uint16_t> pads) {
  uint16_t width = target->max_width * min(w, (float)1);
  uint16_t height = target->max_height * min(h, (float)1);
  PadBox *box = new PadBox(width, height, pads);
  target->add_child(box);
  return box;
}

void PadBox::show(WINDOW *window, uint16_t x, uint16_t y) {
  Box *iter = this->first_child;
  uint8_t next_y = y, max_y = pt + y + max_height;
  while (iter != NULL) {
    // don't render items outside of this Box
    // TODO: scrollbars (?)
    if (next_y + iter->max_height > max_y) {
      break;
    }

    iter->show(window, x + pl, next_y + pt);
    next_y = next_y + iter->max_height;
    iter = iter->sibling;
  }
}
