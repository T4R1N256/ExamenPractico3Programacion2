#ifndef GUERRERO_H
#define GUERRERO_H

#include "Personaje.h"

class Guerrero : public Personaje {
private:
  int escudo;
  int fuerza;
  HabilidadEspecial<int> estocada{5};

public:
  Guerrero();

  ~Guerrero();

  void subirNivel(int n) override;
  void atacar(Personaje &) override;
};

#endif
