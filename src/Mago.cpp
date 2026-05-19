#include "Mago.h"

Mago::Mago()
    : Personaje("DEFAULT", "Mago", 20, 1, 0, 105, true), danVeneno(10),
      campFuerza(5), canPociones(3) {};

Mago::~Mago() {}

void Mago::atacar(Personaje &otro) {
  pocionDanio.cargar();

  if (canPociones) {
    if (pocionDanio.lanzar() || estaCritico()) {
      int danioCritico = (danio + danVeneno);
      otro.recibirDanio(danioCritico);
      cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
         << " (" << otro() << ") con su ATAQUE CRITICO!" << endl;
      pocionDanio.resetPoder();
      esCritico = false;
    } else {
      otro.recibirDanio(danio);
      cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
         << " (" << otro() << ") con su pocion de veneno!" << endl;
    }
    canPociones--;
  } else {
    cout << this->nombre << " (" << tipo << ") tuvo que crear mas pociones!"
         << endl;
    canPociones = 3;
  }
}

void Mago::subirNivel(int n) { 
  int correct_n = n - 1;

  Personaje::subirNivel(n);
  
  danVeneno += 20 * correct_n;
  salud = saludMaxima += campFuerza * correct_n;
}