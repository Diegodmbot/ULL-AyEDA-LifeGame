/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Algoritmos y Estructuras de Datos
 * @file: P01DiegoDiazMoron/vector_t
 * @author: Diego Diaz Moron
 * @mail: alu0101337975@ull.edu.es
 * @date: 04/03/22
 * @version: 0.1
 * @brief: Juego de la Vida.
 */

#include "vector_t.hpp"

vector_t::vector_t(const int n) {
  sz_ = n;
  Build();
}

vector_t::~vector_t() { Destroy(); }

void vector_t::Build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new Cell[sz_];
    assert(v_ != NULL);
  }
}

void vector_t::Destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

void vector_t::Resize(const int n) {
  Destroy();
  sz_ = n;
  Build();
}

inline Cell vector_t::GetVal(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

inline int vector_t::GetSize() const { return sz_; }

void vector_t::SetVal(const int i, const Cell d) {
  assert(i >= 0 && i < GetSize());
  v_[i] = d;
}

Cell& vector_t::operator[](const int i) {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}
