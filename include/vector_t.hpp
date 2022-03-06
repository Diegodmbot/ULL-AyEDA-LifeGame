/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmos y Estructuras de Datos Avanzados
 * @file: P01DiegoDiazMoron/vector_t
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 04/03/22
 * @version: 0.1
 * @brief: El Juego de la Vida.
 */

#ifndef VECTOR
#define VECTOR

#include <cassert>
#include <iostream>

#include "Cell.hpp"

class vector_t {
 public:
  vector_t(const int = 0);
  ~vector_t();
  // Getters - Setters
  Cell GetVal(int) const;
  int GetSize(void) const;
  void SetVal(int, Cell) const;
  Cell& operator[](int) const;
  // Metodos
  void Resize(const int);

 private:
  Cell* v_;
  int sz_;
  void Build(void);
  void Destroy(void);
};

#endif
