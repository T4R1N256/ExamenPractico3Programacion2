#include "Curandero.h"

Curandero::Curandero(string n)
    : Personaje(n, "Curandero",15, 70, 1, 0, 100, true), canCuracion(10), rapidez(5) {};

void Curandero::atacar(Personaje &otro) {
  otro.recibirDanio(danio);
  cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre() << " (" << otro.getTipo() << ") con su baston!" << endl;
}

void Curandero::curar(Personaje &otro) {
  otro.recibirCuracion(canCuracion);
  cout << this->nombre << " ha curado a " << otro.getNombre() << "! +" << canCuracion << endl;
}

Curandero::~Curandero() {
  cout << "Curandero " << nombre << " destruido correctamente" << endl;
}