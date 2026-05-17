#ifndef GUERRERO_H
#define GUERRERO_H

#include "Personaje.h"

class Guerrero : public Personaje {
private:
  int escudo;
  int fuerza;
  HabilidadEspecial<int> estocada{5};

public:
  Guerrero(string);

  ~Guerrero();

  void atacar(Personaje &) override;
};

#endif
