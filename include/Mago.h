#ifndef MAGO_H
#define MAGO_H

#include "Personaje.h"

class Mago : public Personaje {
private:
  int danVeneno;
  int campFuerza;
  int canPociones;
  HabilidadEspecial<int> pocionDanio{2};

public:
  Mago();

  ~Mago();

  void subirNivel(int n) override;
  void atacar(Personaje &) override;
};

#endif