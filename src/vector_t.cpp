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

template <class T>
vector_t<T>::vector_t(const int n) {
  sz_ = n;
  Build();
}

template <class T>
vector_t<T>::~vector_t() {
  Destroy();
}

template <class T>
void vector_t<T>::Build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

template <class T>
void vector_t<T>::Destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

template <class T>
void vector_t<T>::Resize(const int n) {
  Destroy();
  sz_ = n;
  Build();
}

template <class T>
inline T vector_t<T>::GetVal(const int i) const {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}

template <class T>
inline int vector_t<T>::GetSize() const {
  return sz_;
}

template <class T>
void vector_t<T>::SetVal(const int i, const T d) {
  assert(i >= 0 && i < GetSize());
  v_[i] = d;
}

template <class T>
T& vector_t<T>::operator[](const int i) {
  assert(i >= 0 && i < GetSize());
  return v_[i];
}
