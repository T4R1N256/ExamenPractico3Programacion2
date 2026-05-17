#include "Mago.h"

Mago::Mago(string n)
    : Personaje(n, "Mago", 15, 70, 1, 0, 100, true), danVeneno(10),
      campFuerza(5) {};

Mago::~Mago() {}

void Mago::atacar(Personaje &otro) {
  pocionDanio.cargar();

  if (pocionDanio.lanzar() ) {
    int danioCritico = (danio + 20 + danVeneno);
    otro.recibirDanio(danioCritico);
    cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
         << " (" << otro.getTipo() << ") con su ATAQUE CRITICO!";
         otro(danioCritico); cout << endl;
    pocionDanio.resetPoder();
  } else {
    otro.recibirDanio(danio);
    cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
         << " (" << otro.getTipo() << ") con su pocion de veneno!" << endl;
  }
};