#include <iostream>
using namespace std;

// Despues de 10 de XP se sube un nivel
//

class Personaje {
protected:
  string nombre;
  int nivel;
  int experiencia;
  int salud;
  int daño;
  int poderTotal;

public:
  Personaje(string nombre, int danio, int poderTotal, int nivel = 1,
            int exp = 0, int salud = 100);

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

Personaje::Personaje(string nombre, int danio, int poderTotal, int nivel,
                     int exp, int salud) {

  this->nombre = nombre;
  this->daño = 0;
  this->poderTotal = 0;
  this->nivel = (nivel < 1) ? 1 : nivel;
  this->experiencia = (exp < 0) ? 0 : exp;
  this->salud = (salud < 0) ? 0 : salud;
}

Personaje::~Personaje() { cout << "Personaje generico destruido..." << endl; }

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
  is >> p.salud;
  if (p.salud < 0)
    p.salud = 0;
  return is;
}

class Guerrero : public Personaje {
private:
  int escudo;
  int fuerza;

public:
  Guerrero(string);

  ~Guerrero();

  void atacar() override;
};

Guerrero::Guerrero(string n)
    : Personaje(n, 15, 70, 1, 0, 100), escudo(50), fuerza(5) {};

Guerrero::~Guerrero() {
  cout << "Guerrero " << nombre << " destruido correctamente..." << endl;
}

void Guerrero::atacar() {
  cout << "El guerrero realiza un ataque con su espada!" << endl;
};

class Mago : public Personaje {
private:
  int danVeneno;
  int campFuerza;

public:
  Mago(string, int, int);

  ~Mago();

  void atacar() override;
};

Mago::Mago(string n, int d, int c)
    : Personaje(n, 1, 0, 100), danVeneno(d), campFuerza(c) {};

Mago::~Mago() {
  cout << "Mago " << nombre << " destruido correctamente..." << endl;
}

void Mago::atacar() {
  cout << "El mago realiza un ataque con su pocion de veneno!" << endl;
};

class Curandero : public Personaje {
private:
  int canCuracion;
  int rapidez;

public:
  Curandero(string, int, int);

  ~Curandero();

  void atacar() override;
};

Curandero::Curandero(string n, int c, int r)
    : Personaje(n, 1, 0, 100), canCuracion(c), rapidez(r) {};

void Curandero::atacar() {
  cout << "El curandero realiza un ataque con su mano!" << endl;
};

Curandero::~Curandero() {
  cout << "Curandero " << nombre << " destruido correctamente" << endl;
}

class Arquero : public Personaje {
private:
  int velocidad;
  int canFlechas;

public:
  Arquero(string, int, int);

  ~Arquero();

  void atacar() override;
};

Arquero::Arquero(string n, int v, int c)
    : Personaje(n, 1, 0, 100), velocidad(v), canFlechas(c) {};

Arquero::~Arquero() {
  cout << "Arquero " << nombre << " destruido correctamente..." << endl;
}

void Arquero::atacar() {
  cout << "El curandero realiza un ataque con su mano!" << endl;
};

int MenuPrincipal() {
  int opc;
  cout << "Ingresa una opción: " << endl
       << "1. Iniciar juego" << endl
       << "0. Salir" << endl;

  cin >> opc;

  switch (opc) {
  case 0:
    return 0;
  case 1:
    return 1;
  }

  return 0;
}

int EscogerPersonaje() {
  int opc;
  cout << "Escoje tu personaje: " << endl
       << "1. Guerrero" << endl
       << "2. Curandero" << endl
       << "3. Arquero" << endl
       << "4. Mago" << endl;

  cin >> opc;

  switch (opc) {
  case 1:
    return 1;
  case 2:
    return 2;
  case 3:
    return 4;
  case 4:
    return 4;
  default:
    cout << "Opcion no disponible!!!" << endl;
    return 0;
  }
}

int main() {

  if (MenuPrincipal() == 1) {
  }

  return 0;
}
