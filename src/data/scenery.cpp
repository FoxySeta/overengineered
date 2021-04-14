/*
  University of Bologna
  First cicle degree in Computer Science
  00819 - Programmazione

  Stefano Volpe #969766
  04/09/2021

  scenery.cpp: implementation of Data::Scenery.
*/

#include "scenery.hpp"

std::basic_istream<wchar_t> &Data::operator>>(std::basic_istream<wchar_t> &i,
                                              Scenery::Autotile &a) {
  i >> a.singlet;
  i.ignore();
  i >> a.concave_top_left >> a.concave_top_right;
  i.ignore();
  i >> a.concave_bottom_left >> a.concave_bottom_right;
  i.ignore();
  i >> a.top_left >> a.top >> a.top_right;
  i.ignore();
  i >> a.left >> a.center >> a.right;
  i.ignore();
  return i >> a.bottom_left >> a.bottom >> a.bottom_right;
}

std::basic_istream<wchar_t> &Data::operator>>(std::basic_istream<wchar_t> &i,
                                              Scenery &s) {
  i >> s.ground;
  i.ignore();
  i >> s.platform;
  size_t sky_colors;
  i >> sky_colors;
  s.sky = Nostd::Vector<Engine::Color>(sky_colors);
  for (auto &x : s.sky) {
    short color_code;
    i >> color_code;
    x = Engine::short_to_color(color_code);
  }
  return i;
};
