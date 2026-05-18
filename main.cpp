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


  Personaje *jugador = nullptr, *amigo = nullptr, *enemigos1 = nullptr, *enemigos2 = nullptr;

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
      cout << "\n¡Gracias por jugar! Hasta la próxima." << endl;
      break;
    }

    // string sand;

    // cout << "Deseas activar el modo sandbox? [sand/n] (deberas ingresar manualmente TODA la informacion de tu personaje): ";

    // cin >> sand;

    // if (sand == "sand") {
        
    // }

    cout << "\n========== RONDA " << rondas << " ==========" << endl;
    int id_jugador = EscogerPersonaje();

    // No necesario porque nunca llega al error
    while (id_jugador == ERROR) {
      cout << "Opcion invalida. Intente de nuevo: " << endl;
      id_jugador = EscogerPersonaje();
    }
    
    jugador = crearPersonaje(id_jugador);

    int id_amigo = EscogerCompanero(id_jugador);

    while (id_amigo == ERROR) {
      cout << "Opcion invalida. Intente de nuevo: " << endl;
      id_amigo = EscogerCompanero(id_jugador);
    }

    amigo = crearPersonaje(id_amigo);

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

    if (rondas > 1) {
      cout << (equipo[0] > enemigos[0] ? 
        "Tu equipo es superior al equipo enemigo" : 
        "El equipo enemigo es superior a tu equipo") 
        << endl << endl;
    }
    
    while (!equipo.empty() && !enemigos.empty()) {
      for (auto *p : equipo) {
        if (!enemigos.empty()) {
          int idx = enemigos.size() > 1 ? generarIdAleatorio(1) : 0;
          Personaje *currAtacar = enemigos[idx];
          p->atacar(*currAtacar);
          // sleep(2);

          if (!currAtacar->estaVivo()) {
            cout << '\n' << currAtacar->getNombre() << " HA SIDO DERROTADO!\n" << endl;
            enemigos.erase(enemigos.begin() + idx); // arr[0 + idx]
                        delete currAtacar;
          }

          if (enemigos[0]->estaCritico() && enemigos[1]->getTipo() == "Curandero" && enemigos[1]->estaVivo() && enemigos[0]->estaVivo())
          {
              dynamic_cast<Curandero *>(enemigos[1])->curar(*enemigos[0]);
          } else if (enemigos[1]->estaCritico() && 
          enemigos[0]->getTipo() == "Curandero" &&
          enemigos[1]->estaVivo() && 
          enemigos[0]->estaVivo())
          {
              dynamic_cast<Curandero *>(enemigos[0])->curar(*enemigos[1]);
          }
        }
      }

      for (auto *e : enemigos) {
        if (!equipo.empty()) {
          int idx = equipo.size() > 1 ? generarIdAleatorio(1) : 0;
          Personaje *currAtacar = equipo[idx];
          e->atacar(*currAtacar);
          // sleep(2);

          if (!currAtacar->estaVivo()) {
            cout << '\n' << currAtacar->getNombre() << " HA SIDO DERROTADO!\n" << endl;
            equipo.erase(equipo.begin() + idx); // arr[0 + idx]
                        delete currAtacar;
          }

          if (equipo[0]->estaCritico() && equipo[1]->getTipo() == "Curandero" && equipo[1]->estaVivo() && equipo[0]->estaVivo())
          {
              dynamic_cast<Curandero *>(equipo[1])->curar(*equipo[0]);
          } else if (equipo[1]->estaCritico() && 
          equipo[0]->getTipo() == "Curandero" &&
          equipo[1]->estaVivo() && 
          equipo[0]->estaVivo())
          {
              dynamic_cast<Curandero *>(equipo[0])->curar(*equipo[1]);
          }
        }
      }

      if (equipo.empty()) {
        cout << "\n¡HAS PERDIDO!\n" << endl;
        expEnemigo += generarIdAleatorio(100) + 100;
        expEquipo += generarIdAleatorio(50) + 50;
        for (auto *e: enemigos) {
          delete e;
        }
      } else if (enemigos.empty()) {
        cout << "\n¡HAS GANADO!\n" << endl;
        expEquipo += generarIdAleatorio(100) + 100;
        expEnemigo += generarIdAleatorio(50) + 50;
        for (auto *a: equipo) {
          delete a;
        }
      }
    }


    
  } while (jugando);

      delete jugador;
      delete amigo;
      delete enemigos1;
      delete enemigos2;

  return 0;
}
