#ifndef ARQUERO_H
#define ARQUERO_H

#include "Personaje.h"

class Arquero : public Personaje {
private:
  int velocidad;
  int canFlechas;
  HabilidadEspecial<int> flechaFuego{5};

public:
  Arquero();

  ~Arquero();

  void subirNivel(int n) override;

  void atacar(Personaje &) override;
};

#endif