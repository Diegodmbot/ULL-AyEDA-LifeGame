/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmos y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/matrix_t
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 04/03/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#ifndef MATRIX
#define MATRIX

#include "vector_t.hpp"

class matrix_t {
 public:
  matrix_t(const int = 0, const int = 0);
  ~matrix_t();
  // Getters - Setters
  int GetRows(void) const;
  int GetCols(void) const;
  // Metodos
  Cell& operator()(const int, const int);
  void Resize(const int, const int);

 private:
  int rows_, cols_;
  vector_t v_;

  int pos(const int, const int) const;
};

#endif