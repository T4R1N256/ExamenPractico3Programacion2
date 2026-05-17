/*
Tarin Gutierrez Alejandro 247521
Hernandez Garrido Jesus Eduardo 249285
Coronado Rodriguez Miguel Angel 246025
*/

#include "Arquero.h"
#include "Curandero.h"
#include "Guerrero.h"
#include "Mago.h"
#include "Personaje.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <limits>
#include <unistd.h>
#include <vector>
using namespace std;

// Despues de 100 de XP se sube un nivel

// enum asigna un token al id de tipo personaje
enum TipoPersonaje { GUERRERO = 1, CURANDERO = 2, ARQUERO = 3, MAGO = 4 };

enum Error {
  ERROR = -1,
};

// valida entrada de numeros enteros
int leerInt() {
  int num;

  while (true) {
    if (cin >> num) {
      if (num >= 0) {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return num;
      } else {
        cout << "Error. Ingrese un numero mayor a 0: ";
      }
    } else {
      cout << "Entrada invalida. Intente de nuevo: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
  }
}

int MenuPrincipal() {
  int opc;
  cout << "Ingresa una opción: " << endl
       << "1. Iniciar juego" << endl
       << "0. Salir" << endl;

  do {
    opc = leerInt();
  } while (opc != 1 && opc != 0);

  return opc;
}

int EscogerPersonaje() {
  int opc = 0;

  while (opc < 1 || opc > 4) {
    cout << "Escoje tu personaje: " << endl
         << "1. Guerrero" << endl
         << "2. Curandero" << endl
         << "3. Arquero" << endl
         << "4. Mago" << endl;

    opc = leerInt();
  }

  return opc;
}

int EscogerCompanero(int p) {
  int opc = 0;

  if (p == 1) {
    while (opc < 1 || opc > 4 || opc == p) {
      cout << endl
           << "Escoje tu compañero: " << endl
           << "2. Curandero" << endl
           << "3. Arquero" << endl
           << "4. Mago" << endl;

      opc = leerInt();
    }

  } else if (p == 2) {
    while (opc < 1 || opc > 4 || opc == p) {
      cout << endl
           << "Escoje tu compañero: " << endl
           << "1. Guerrero" << endl
           << "3. Arquero" << endl
           << "4. Mago" << endl;

      opc = leerInt();
    }
  } else if (p == 3) {
    while (opc < 1 || opc > 4 || opc == p) {
      cout << endl
           << "Escoje tu compañero: " << endl
           << "1. Guerrero" << endl
           << "2. Curandero" << endl
           << "4. Mago" << endl;

      opc = leerInt();
    }
  } else {
    while (opc < 1 || opc > 4 || opc == p) {
      cout << endl
           << "Escoje tu compañero: " << endl
           << "1. Guerrero" << endl
           << "2. Curandero" << endl
           << "3. Arquero" << endl;

      opc = leerInt();
    }
  }

  return opc;
}

Personaje *crearPersonaje(int tipo) {
  string nombre;

  cout << "Nombre del personaje: ";

  getline(cin, nombre);

  switch (tipo) {
  case GUERRERO:
    return new Guerrero(nombre);

  case CURANDERO:
    return new Curandero(nombre);

  case ARQUERO:
    return new Arquero(nombre);

  case MAGO:
    return new Mago(nombre);

  default:
    return nullptr;
  }
}

int generarIdAleatorio(int max) { return rand() % (max + 1); }

int main() {
  srand(time(NULL));

  int rondas = 0, expEquipo = 0, expEnemigo = 0;
  bool jugando = true;
  string res = "n";

  cout << "¡Bienvenido al juego de batalla de personajes!" << endl;

  do {
    if (!rondas)
      cout << "¿Quieres empezar a jugar? [s/n]: ";
    else
      cout << "\n¿Quieres jugar otra ronda? [s/n]: ";

    cin >> res;

    while (res != "s" && res != "S" && res != "n" && res != "N") {
      cout << "Opción inválida. Por favor, ingresa 's' para sí o 'n' para no: ";
      cin >> res;
    }

    if (res == "s" || res == "S") {
      rondas++;
    } else {
      jugando = false;
      cout << "¡Gracias por jugar! Hasta la próxima." << endl;
    }

    cout << "\n========== RONDA " << rondas << " ==========" << endl;
    int id_jugador = EscogerPersonaje();

    // No necesario porque nunca llega al error
    while (id_jugador == ERROR) {
      cout << "Opcion invalida. Intente de nuevo: " << endl;
      id_jugador = EscogerPersonaje();
    }

    Personaje *jugador = crearPersonaje(id_jugador);

    int id_amigo = EscogerCompanero(id_jugador);

    while (id_amigo == ERROR) {
      cout << "Opcion invalida. Intente de nuevo: " << endl;
      id_amigo = EscogerCompanero(id_jugador);
    }

    Personaje *amigo = crearPersonaje(id_amigo);

    if (jugador == nullptr || amigo == nullptr) {
      cout << "Error al crear el personaje" << endl;
      return 0;
    }

    vector<Personaje *> equipo = {jugador, amigo};

    if (expEquipo) {
      for (Personaje *p : equipo) {
        p->cargarExperiencia(expEquipo / 2);
      }
    }

    Personaje *enemigos1 = nullptr;
    Personaje *enemigos2 = nullptr;

    vector<Personaje *> enemigos;

          cout << "\nEnemigo 1: " << endl;
    enemigos1 = crearPersonaje(generarIdAleatorio(3) + 1);
          enemigos.push_back(enemigos1);

          cout << "\nEnemigo 2: " << endl;
    enemigos2 = crearPersonaje(generarIdAleatorio(3) + 1);
          enemigos.push_back(enemigos2);

    if (expEnemigo) {
      for (Personaje *p : enemigos) {
        p->cargarExperiencia(expEnemigo / 2);
      }
    }

    cout << "\n=========== EQUIPO ==============" << endl;
    for (size_t i = 0; i < equipo.size(); i++) {
      cout << *equipo[i] << endl;
    }

    cout << "\n=========== ENEMIGOS ============" << endl;
    for (size_t i = 0; i < enemigos.size(); i++) {
      cout << *enemigos[i] << endl;
    }

    cout << endl;

    while (!equipo.empty() && !enemigos.empty()) {
      for (Personaje *p : equipo) {
        if (!enemigos.empty()) {
          p->atacar(*enemigos[generarIdAleatorio(1)]);
          // sleep(2);
          if (!enemigos[0]->estaVivo()) {
            cout << '\n' << enemigos[0]->getNombre() << " HA SIDO DERROTADO!\n" << endl;
            enemigos.erase(enemigos.begin());
          } else if (!enemigos[1]->estaVivo()) {
            cout <<'\n' << enemigos[1]->getNombre() << " HA SIDO DERROTADO!\n" << endl;
            enemigos.erase(enemigos.begin() + 1);
          }
        }
      }

      for (Personaje *e : enemigos) {
        if (!equipo.empty()) {
          e->atacar(*equipo[generarIdAleatorio(1)]);
          // sleep(2);
          if (!equipo[0]->estaVivo()) {
            cout << '\n' << equipo[0]->getNombre() << " HA SIDO DERROTADO!\n" << endl;
            equipo.erase(equipo.begin());
          } else if (!equipo[1]->estaVivo()) {
            cout << '\n' << equipo[1]->getNombre() << " HA SIDO DERROTADO!\n" << endl;
            equipo.erase(equipo.begin() + 1);
          }
        }
      }

      if (equipo.empty()) {
        cout << "\n¡HAS PERDIDO!\n" << endl;
        expEnemigo += generarIdAleatorio(100) + 100;
        expEquipo += generarIdAleatorio(50) + 50;
      } else if (enemigos.empty()) {
        cout << "\n¡HAS GANADO!\n" << endl;
        expEquipo += generarIdAleatorio(100) + 100;
        expEnemigo += generarIdAleatorio(50) + 50;
      }
    }

      delete jugador;
      delete amigo;
      delete enemigos1;
      delete enemigos2;

  } while (jugando);

  return 0;
}
