#include "Guerrero.h"

Guerrero::Guerrero(string n)
    : Personaje(n, "Guerrero", 15, 70, 1, 0, 100, true), escudo(50), fuerza(5), estocada(10) {};

Guerrero::~Guerrero() {
  cout << "Guerrero " << nombre << " destruido correctamente..." << endl;
}

void Guerrero::atacar(Personaje &otro) {
  estocada.cargar();

  if (estocada.getPoder() >= 5) {
    
    estocada.resetPoder();
  } else {
    otro.recibirDanio(danio + fuerza);
    cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre() << " (" << otro.getTipo() << ") con su espada!" << endl;
  }
};