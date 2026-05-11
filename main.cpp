#include <iostream>
using namespace std;

class Personaje {
private:
  string nombre;
  int nivel;
  int experiencia;
  int salud;

public:
  Personaje(string nombre, int nivel = 1, int exp = 0, int salud = 100);

  virtual ~Personaje();

  virtual void atacar();

  void subirNivel();

  // Sobrecargar + para representar experiencia?
  void cargarExperiencia(int);
  Personaje &operator+(int);
  bool operator>(const Personaje &);
  int operator()(); // Nivel de poder?

  friend ostream &operator<<(ostream &, const Personaje &);
  friend istream &operator>>(istream &, Personaje &);
};

Personaje::Personaje(string nombre, int nivel, int exp, int salud) {
  this->nombre = nombre;
  this->nivel = (nivel < 1) ? 1 : nivel;
  this->experiencia = (exp < 0) ? 0 : exp;
  this->salud = (salud < 0) ? 0 : salud;
}

void Personaje::atacar() {
  cout << nombre << " realiza un ataque generico!" << endl;
}

void Personaje::subirNivel() {
  nivel++;
  cout << nombre << " ha subido al nivel" << nivel << "!" << endl;
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

int Personaje::operator()() { return 1; }

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
  if (p.salud < 0)
    p.salud = 0;
  return is;
}

class Guerrero : public Personaje {
public:
  Guerrero();

  void atacar() override;
};

class Mago : public Personaje {
public:
  Mago();

  void atacar() override;
};

class Curandero : public Personaje {
public:
  Curandero();

  void atacar() override;
};

class Arquero : public Personaje {
public:
  Arquero();

  void atacar() override;
};

int main() { return 0; }
