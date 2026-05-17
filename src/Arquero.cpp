#include "Arquero.h"

Arquero::Arquero(string n)
    : Personaje(n, "Arquero", 15, 70, 1, 0, 100, true), velocidad(10),
      canFlechas(10) {};

Arquero::~Arquero() {}

void Arquero::atacar(Personaje &otro) {

  if (canFlechas > 0) {
    flechaFuego.cargar();

    if (flechaFuego.lanzar() || estaCritico()) {
      int danioCritico = (danio + velocidad + 20);
      otro.recibirDanio(danioCritico);
      cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
           << " (" << otro.getTipo() << ") con su ATAQUE CRITICO!"; 
           otro(danioCritico); cout << endl;
      flechaFuego.resetPoder();
      esCritico = false;
    } else {
      otro.recibirDanio(danio);
      cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
           << " (" << otro.getTipo() << ") con su arco!" << endl;
    }
    canFlechas--;
  } else {
    cout << this->nombre << " (" << tipo << ") tuvo que recargar flechas"
         << endl;
    canFlechas = 10;
  }
};