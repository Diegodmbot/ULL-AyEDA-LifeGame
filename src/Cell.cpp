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

#include "Grid.hpp"

Cell::Cell() {
  actual_state = kDead;
  next_state = kDead;
  neighbords_alive = 3;
}

Cell::~Cell() {}

CellStates Cell::GetActualState(void) { return actual_state; }

CellStates Cell::GetNextState(void) { return next_state; }

int Cell::GetNeighboursAlive(void) { return neighbords_alive; }

void Cell::SetActualState(CellStates state) { actual_state = state; }

void Cell::SetNextState(CellStates state) { next_state = state; }
void Cell::SetPositionRow(int row) { pos_row = row; }
void Cell::SetPositionCol(int col) { pos_col = col; }

int Cell::Neighbors(Grid& map) {
  for (int i = 1; i <= map.GetRowSize(); i++) {
    for (int j = 1; j <= map.GetColumnSize(); j++) {
    }
  }
}

void Cell::UpdateState(void) {
  if (actual_state == kAlive) {
    next_state = kDead;
  } else if (actual_state == kDead) {
    next_state = kAlive;
  }
}

std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  char output;
  switch (cell.actual_state) {
    case 0:
      output = '-';
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
