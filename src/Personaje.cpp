#include "Personaje.h"

Personaje::Personaje(string nombre, string tipo, int danio, int poderTotal, int nivel,
                     int exp, int salud, bool vivo) {

  this->nombre = nombre;
  this->tipo = tipo;
  this->danio = danio;
  this->poderTotal = poderTotal;
  this->nivel = (nivel < 1) ? 1 : nivel;
  this->experiencia = (exp < 0) ? 0 : exp;
  this->salud = (salud < 0) ? 0 : salud;
  this->saludMaxima = this->salud;
  this->vivo = vivo;
  this->poderMaximo = 10;
}

Personaje::~Personaje() {}

void Personaje::atacar(Personaje &otro) {
  otro.recibirDanio(danio);
  if (otro.salud <= 0) {
    otro.vivo = false;
  }
  cout << nombre << " realiza un ataque generico!" << endl;
}

void Personaje::subirNivel() {
  nivel++;
  if (poderMaximo > 0)
    poderMaximo--;
  saludMaxima += 20;
  danio += 10;
  cout << '\n' <<nombre << " ha subido al nivel " << nivel << "!\n" << endl;
}

void Personaje::cargarExperiencia(int xp) {
  if (xp <= 0)
    return;
  experiencia += xp;
  while (experiencia >= 100) {
    experiencia -= 100;
    subirNivel();
  }
}

Personaje &Personaje::operator+(int xp) {
  cargarExperiencia(xp);
  return *this;
}

bool Personaje::operator>(const Personaje &otro) {
  if (nivel != otro.nivel)
    return nivel > otro.nivel;
  return experiencia > otro.experiencia;
}

void Personaje::recibirDanio(int danioRecibido) {
  salud -= danioRecibido;
  if (salud <= 0) {
    salud = 0;
    vivo = false;
  // } else if (salud <= (saludMaxima * 0.2)) {
  //   menuAtaqueEspecial();
  // }
  }
}

// void Personaje::menuAtaqueEspecial() {

// }

// void Personaje::ataqueEspecial(Personaje &otro) {

// }

void Personaje::recibirCuracion(int vidaRecibida) {
  if (estaVivo()) {
    salud += vidaRecibida;
    if (salud > saludMaxima) {
      salud = saludMaxima;
    } else if (salud > (saludMaxima * 0.2)) {
      esCritico = false;
    }
  }
}

bool Personaje::estaVivo() { return vivo; }

bool Personaje::estaCritico() { return esCritico; }

string Personaje::getNombre() { return nombre; }

string Personaje::getTipo() { return tipo; }

int Personaje::operator()() { return nivel * danio + poderTotal; }

ostream &operator<<(ostream &os, const Personaje &p) {
      os << '"' << p.nombre << "\" Nivel: " << p.nivel << " | XP: " << p.experiencia
     << " | Salud: " << p.salud;

  return os;
}

istream &operator>>(istream &is, Personaje &p) {
  cout << "Nombre: ";
  is >> p.nombre;
  cout << "Nivel: ";
  is >> p.nivel;
  if (p.nivel < 1)
    p.nivel = 1;
  cout << "Experiencia: ";
  is >> p.experiencia;
  if (p.experiencia < 0)
    p.experiencia = 0;
  cout << "Salud: ";
  is >> p.salud;
  if (p.salud < 0)
    p.salud = 0;
  return is;
}
