#ifndef CURANDERO_H
#define CURANDERO_H

#include "Personaje.h"

class Curandero : public Personaje {
private:
  int canCuracion;
  int rapidez;
  HabilidadEspecial<int> bastonVeneno{4};

public:
  Curandero(string);

  ~Curandero();

  void atacar(Personaje &) override;
  void curar(Personaje &);
};

#endif