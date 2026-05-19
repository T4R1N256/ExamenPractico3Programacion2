#include "Curandero.h"

Curandero::Curandero()
    : Personaje("DEFAULT", "Curandero", 10, 1, 0, 100, true), canCuracion(20),
      rapidez(15) {};

void Curandero::atacar(Personaje &otro) {
    bastonVeneno.cargar();

  if (bastonVeneno.lanzar() || estaCritico()) {
      int danioCritico = (danio + rapidez);
      otro.recibirDanio(danioCritico);
      cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
           << " (" << otro() << ") con su ATAQUE CRITICO!" << endl;
      bastonVeneno.resetPoder();
      esCritico = false;
    } else {
      otro.recibirDanio(danio);
      cout << this->nombre << " (" << (*this)() << ") ataca a " << otro.getNombre()
           << " (" << otro() << ") con su baston!" << endl;
    }
}

void Curandero::curar(Personaje &otro) {
  otro.recibirCuracion(canCuracion);
  cout << endl << this->nombre << " ha curado a " << otro.getNombre() << "! +"
       << canCuracion << endl;
}

void Curandero::subirNivel(int n) {
  int correct_n = n - 1;

  Personaje::subirNivel(n);
  
  canCuracion += 50 * correct_n;
  rapidez += 15 * correct_n;
}

Curandero::~Curandero() {}