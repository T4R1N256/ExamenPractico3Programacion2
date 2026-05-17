#ifndef HABILIDADESPECIAL_H
#define HABILIDADESPECIAL_H

template <typename T> class HabilidadEspecial {
private:
  T poder; // se suma cada que hace un ataque, contador
  T poderMaximo;

public:
  HabilidadEspecial(T maximo) : poder(0), poderMaximo(maximo) {}

  T getPoder();
  T getPoderMaximo();
  bool lanzar();
  void cargar();
  void resetPoder();
};

#endif