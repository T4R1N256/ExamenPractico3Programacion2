#include "Arquero.h"

Arquero::Arquero()
    : Personaje("DEFAULT", "Arquero", 20, 1, 0, 100, true), velocidad(15),
      canFlechas(5) {};

Arquero::~Arquero() {}

void Arquero::atacar(Personaje &otro) {

  if (canFlechas > 0) {
    flechaFuego.cargar();

    if (flechaFuego.lanzar() || estaCritico()) {
      int danioCritico = (danio + velocidad);
      otro.recibirDanio(danioCritico);
      cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
           << " (" << otro() << ") con su ATAQUE CRITICO!" << endl; 
      flechaFuego.resetPoder();
      esCritico = false;
    } else {
      otro.recibirDanio(danio);
      cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
           << " (" << otro() << ") con su arco!" << endl;
    }
    canFlechas--;
  } else {
    cout << this->nombre << " (" << tipo << ") tuvo que recargar flechas"
         << endl;
    canFlechas = 5;
  }
}

void Arquero::subirNivel(int n) { 
  int correct_n = n - 1;

  Personaje::subirNivel(n);

  velocidad += 20 * correct_n; 
}