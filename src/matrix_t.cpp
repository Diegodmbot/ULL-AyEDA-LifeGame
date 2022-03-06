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

#include "matrix_t.hpp"

matrix_t::matrix_t(const int m, const int n) {
  rows_ = m;
  cols_ = n;
  v_.Resize(rows_ * cols_);
}

matrix_t::~matrix_t() {}

void matrix_t::Resize(const int m, const int n) {
  assert(m > 0 && n > 0);
  rows_ = m;
  cols_ = n;
  v_.Resize(rows_ * cols_);
}

inline int matrix_t::GetRows() const { return rows_; }

inline int matrix_t::GetCols() const { return cols_; }

Cell& matrix_t::operator()(const int i, const int j) const {
  assert(i >= 0 && i <= GetRows());
  assert(j >= 0 && j <= GetCols());
  return v_[pos(i, j)];
}

inline int matrix_t::pos(const int i, const int j) const {
  assert(i >= 0 && i <= GetRows());
  assert(j >= 0 && j <= GetCols());
  return (i - 1) * GetCols() + (j - 1);
}