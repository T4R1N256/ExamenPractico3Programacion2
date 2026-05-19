#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <iostream>
#include "HabilidadEspecial.h"

using namespace std;

class Personaje {
protected:
  string nombre;
  string tipo;
  int nivel;
  int experiencia;
  int salud;
  int saludMaxima;
  int danio;
  bool vivo;
  bool esCritico;
  int poderMaximo;

public:
  Personaje(); // sandbox?
  Personaje(string nombre, string tipo, int danio, int nivel = 1,
            int exp = 0, int salud = 100, bool vivo = true);

  virtual ~Personaje() = 0;

  virtual void atacar(Personaje &) = 0;

  virtual void subirNivel(int);
  string getNombre();
  string getTipo();
  int getSalud();
  bool estaVivo();
  bool estaCritico();

  void recibirDanio(int);
  void recibirCuracion(int);
  void cargarExperiencia(int);
  Personaje &operator+(int); // añade experiencia
  bool operator>(const Personaje &); // compara el nivel o experiencia de 2 personajes
  string operator()(); // TODO

  friend ostream &operator<<(ostream &, const Personaje &);
  friend istream &operator>>(istream &, Personaje &); // TODO
};

#endif