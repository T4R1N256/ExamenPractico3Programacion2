#include "Mago.h"

Mago::Mago(string n)
    : Personaje(n, "Mago",15, 70, 1, 0, 100, true), danVeneno(50), campFuerza(5) {};

Mago::~Mago() {
  cout << "Mago " << nombre << " destruido correctamente..." << endl;
}

void Mago::atacar(Personaje &otro) {
  otro.recibirDanio(danio);
  cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre() << " (" << otro.getTipo() << ") con su pocion de veneno!" << endl;
};