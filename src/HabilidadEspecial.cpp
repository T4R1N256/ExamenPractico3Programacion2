#include "HabilidadEspecial.h"

template <typename T> T HabilidadEspecial<T>::getPoder() { return poder; }

template <typename T> T HabilidadEspecial<T>::getPoderMaximo() {
  return poderMaximo;
}

template <typename T> bool HabilidadEspecial<T>::lanzar() {
  return poder >= poderMaximo;
}

template <typename T> void HabilidadEspecial<T>::cargar() {
  if (poder < poderMaximo) {
    poder++;
  }
}

template <typename T> void HabilidadEspecial<T>::resetPoder() { poder = 0; }

template class HabilidadEspecial<int>;
