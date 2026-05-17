#include "Guerrero.h"

Guerrero::Guerrero(string n)
    : Personaje(n, "Guerrero", 15, 70, 1, 0, 100, true), escudo(50), fuerza(5),
      estocada(10) {};

Guerrero::~Guerrero() {}

void Guerrero::atacar(Personaje &otro) {
  estocada.cargar();

  if (estocada.lanzar() || estaCritico()) {
    int danioCritico = (danio + fuerza + 20);
    otro.recibirDanio(danioCritico);
    cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
         << " (" << otro.getTipo() << ") con su ATAQUE CRITICO!";
         otro(danioCritico); cout << endl;
    estocada.resetPoder();
    esCritico = false;
  } else {
    otro.recibirDanio(danio + fuerza);
    cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
         << " (" << otro.getTipo() << ") con su espada!" << endl;
  }
};