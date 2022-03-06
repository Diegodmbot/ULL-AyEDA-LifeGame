/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmo y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/Grid
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 22/02/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#ifndef GRID
#define GRID

#include <fstream>  // files
#include <sstream>  // std::stringstream
#include <string>
#include <vector>

#include "Cell.hpp"
#include "matrix_t.hpp"

#define BETWEEN(value, min, max) (value >= min && value <= max)

// typedef std::vector<std::vector<Cell>> matrix;
const int kDefaultSize = 50;

class Grid {
 public:
  Grid(char*);
  ~Grid(void);
  // Getters - Setters
  int GetRowSize(void);
  int GetColumnSize(void);
  const Cell& GetCell(int, int) const;
  // Metodos
  /**
   * @brief Se pasa al siguiente turno
   *
   */
  void NextGeneration(void);
  void Write(void);

 private:
  /**
   * @brief Lee el fichero "input.dfa" y construye el DFA.
   *
   * @param argv Nombre del fichero.
   */
  void Read(char*);
  /**
   * @brief Si el valor de la fila o columna es 1 o menor, tomara el tamano por
   * defecto
   *
   * @param i numero de filas o columnas
   * @return tamano final de la matriz
   */
  int FormatSize(const int);
  void SetPositionCell(void);
  int row_size;
  int column_size;
  matrix_t matrix_cell;
};
#endif  // GRID