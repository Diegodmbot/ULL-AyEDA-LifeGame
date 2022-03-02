/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmo y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/main
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 22/02/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#ifndef CELL
#define CELL

#include <iostream>
#include <vector>

typedef enum { kDead = 0, kAlive = 1 } CellStates;
const int kNunmberOfNeighbors = 8;

class Cell {
 public:
  Cell();
  ~Cell(void);
  CellStates GetActualState(void);
  CellStates GetNextState(void);
  void SetActualState(CellStates state);
  void SetNextState(CellStates state);
  void updateState(void);

 private:
  /**
   * @brief Sobrecarga del operador '<<' para imprimir por pantalla
   *
   * @return viva 'X' o muerta ' '
   */
  friend std::ostream& operator<<(std::ostream& os, const Cell& cell);
  CellStates actual_state;
  CellStates next_state;
  int neighbords_alive;
};

#endif  // CELL