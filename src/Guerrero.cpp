#include "Guerrero.h"

Guerrero::Guerrero()
    : Personaje("DEFAULT", "Guerrero", 10, 1, 0, 110, true), escudo(5), fuerza(5) {};

Guerrero::~Guerrero() {}

void Guerrero::atacar(Personaje &otro) {
  estocada.cargar();

  if (estocada.lanzar() || estaCritico()) {
    int danioCritico = (danio + fuerza);
    otro.recibirDanio(danioCritico);
    cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
         << " (" << otro() << ") con su ATAQUE CRITICO!" << endl;
    estocada.resetPoder();
    esCritico = false;
  } else {
    otro.recibirDanio(danio + fuerza);
    cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
         << " (" << otro() << ") con su espada!" << endl;
  }
}

void Guerrero::subirNivel(int n) {
  int correct_n = n - 1;

  Personaje::subirNivel(n);
  
  fuerza += 5 * correct_n;
  salud = saludMaxima += escudo * correct_n;
}