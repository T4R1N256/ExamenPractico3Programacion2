#include "Curandero.h"

Curandero::Curandero(string n)
    : Personaje(n, "Curandero", 15, 70, 1, 0, 100, true), canCuracion(10),
      rapidez(5) {};

void Curandero::atacar(Personaje &otro) {
    bastonVeneno.cargar();

  if (bastonVeneno.lanzar() || estaCritico()) {
      int danioCritico = (danio + 10 + rapidez);
      otro.recibirDanio(danioCritico);
      cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
           << " (" << otro.getTipo() << ") con su ATAQUE CRITICO!";
            otro(danioCritico); cout << endl;
      bastonVeneno.resetPoder();
      esCritico = false;
    } else {
      otro.recibirDanio(danio);
      cout << this->nombre << " (" << tipo << ") ataca a " << otro.getNombre()
           << " (" << otro.getTipo() << ") con su baston!" << endl;
    }
}

void Curandero::curar(Personaje &otro) {
  otro.recibirCuracion(canCuracion);
  cout << this->nombre << " ha curado a " << otro.getNombre() << "! +"
       << canCuracion << endl;
}

Curandero::~Curandero() {}