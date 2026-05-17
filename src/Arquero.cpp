#include "Arquero.h"

Arquero::Arquero(string n)
    : Personaje(n, "Arquero", 15, 70, 1, 0, 100, true), velocidad(10), canFlechas(30) {};

Arquero::~Arquero() {
  cout << "Arquero " << nombre << " destruido correctamente..." << endl;
}

void Arquero::atacar(Personaje &otro) {
  if (canFlechas > 0) {
    otro.recibirDanio(danio + velocidad);
    canFlechas--;
  }
  cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre() << " (" << otro.getTipo() << ") con su arco!" << endl;
};