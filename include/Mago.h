#ifndef MAGO_H
#define MAGO_H

#include "Personaje.h"

class Mago : public Personaje {
private:
  int danVeneno;
  int campFuerza;
  HabilidadEspecial<int> pocionDanio{2};

public:
  Mago(string);

  ~Mago();

  void atacar(Personaje &) override;
};

#endif