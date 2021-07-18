/*
  University of Bologna
  First cicle degree in Computer Science
  00819 - Programmazione

  Mattia Girolimetto #977478
  04/23/2021

  chunck_assembler.test.cpp: tests for World::ChunckAssembler.
*/
#include "chunk_assembler.hpp"
#include "../data/database.hpp"
#include "../nostd/test.hpp"
#include <cassert>

using namespace World;
using namespace Nostd;
using namespace Data;
using namespace Engine;

int main() {
  it("does something better no ask", [] {
    Database d("tests/alma.conf.csv", "tests/assets/", "tests/scoreboard.csv");
    assert(d.map_chunks().size() == 10);
    ChunkAssembler assembler(d.map_chunks(), d.sceneries());
    Matrix<BlockTile> m = assembler.get();
    // per Luca: a te interessa solo il codice qua sopra, in particolare
    // l'ultima riga. ignora i commenti qua sotto assembler.print_list();
    // assembler.print_scenery(d.sceneries()[0]);
  });
  return 0;
}
