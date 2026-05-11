#include <iostream>
using namespace std;

class Personaje {
protected:
  string nombre;
  int nivel;
  int experiencia;
  int salud;

public:
  Personaje(string nombre, int nivel, int exp, int salud);

  virtual ~Personaje();

  virtual void atacar();

  void subirNivel();

  // Sobrecargar + para representar experiencia?
  void cargarExperiencia();
  Personaje &operator+(const int);

  friend ostream &operator<<(const ostream &, const Personaje &);
  friend istream &operator>>(const istream &, const Personaje &);
};

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
