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
  neighbords_alive = 5;
}

Cell::~Cell() {}

CellStates Cell::GetActualState(void) const { return actual_state; }

CellStates Cell::GetNextState(void) const { return next_state; }

int Cell::GetNeighboursAlive(void) const { return neighbords_alive; }

void Cell::SetNeighbordsAlive(int neighbords) { neighbords_alive = neighbords; }

void Cell::SetActualState(CellStates state) { actual_state = state; }

void Cell::SetNextState(CellStates state) { next_state = state; }

void Cell::SetPositionRow(int row) { pos_row = row; }

void Cell::SetPositionCol(int col) { pos_col = col; }

int Cell::Neighbors(const Grid& map) {
  int counter = 0;
  int i_ = pos_col + 1;
  int j_ = pos_row + 1;
  for (int i = pos_col - 1; i <= i_; i++) {
    for (int j = pos_row - 1; j <= j_; j++) {
      if (map.GetCell(i, j).GetActualState() == kAlive) counter++;
    }
  }
  if (actual_state == kAlive) --counter;
  return counter;
}

void Cell::UpdateState(void) {
  // Si la celula esta muerta y tiene 3 vecinos vivos pasa a estar viva
  if (actual_state == kDead && neighbords_alive == 3) next_state = kAlive;
  // Si la celula esta viva y tiene 3 o 2 vecinos vivos sigue viva
  else if (actual_state == kAlive &&
           (neighbords_alive == 3 || neighbords_alive == 2))
    next_state = kAlive;
  // En cualquier otro caso la celula esta muerta
  else
    next_state = kDead;
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
