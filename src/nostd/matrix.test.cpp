/*
  University of Bologna
  First cicle degree in Computer Science
  00819 - Programmazione

  Stefano Volpe #969766
  03/25/2021

  matrix.test.cpp: tests for Nostd::Matrix and its helper entities.
*/

#include "matrix.hpp"
#include <cassert>
#include <iostream>

using namespace Nostd;
using std::cout;

int main() {
  Matrix<int> m({3, 4}, 1);
  cout << "\t✓ ???\n";
}

#include "matrix.cpp"
