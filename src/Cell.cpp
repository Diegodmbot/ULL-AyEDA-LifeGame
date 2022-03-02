/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmo y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/Cell
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 22/02/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#include "Cell.hpp"

Cell::Cell() {
  actual_state = kDead;
  next_state = kDead;
  neighbords_alive = 0;
}

Cell::~Cell() {}

CellStates Cell::GetActualState(void) { return actual_state; }

CellStates Cell::GetNextState(void) { return next_state; }

void Cell::SetActualState(CellStates state) { actual_state = state; }

void Cell::SetNextState(CellStates state) { next_state = state; }

void Cell::updateState(void) {}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  char output;
  switch (cell.actual_state) {
    case 0:
      output = ' ';
      break;
    case 1:
      output = 'X';
      break;
    default:
      break;
  }
  os << output;
  return os;
}
