/*
Tarin Gutierrez Alejandro 247521
Hernandez Garrido Jesus Eduardo 249285
Coronado Rodriguez Miguel Angel 246025
*/

#include <iostream>
#include <limits>
using namespace std;

// Despues de 100 de XP se sube un nivel

// enum asigna un token al id de tipo personaje
enum TipoPersonaje {
  GUERRERO = 1,
  CURANDERO = 2,
  ARQUERO = 3,
  MAGO = 4
};

enum Error {
  ERROR = -1,
};

class Personaje {
protected:
  string nombre;
  int nivel;
  int experiencia;
  int salud;
  int danio;
  int poderTotal;

public:
  Personaje(string nombre, int danio, int poderTotal, int nivel = 1,
            int exp = 0, int salud = 100);

  virtual ~Personaje();

  virtual void atacar();

  void subirNivel();

  void cargarExperiencia(int);
  Personaje &operator+(int); // añade experiencia?
  bool operator>(const Personaje &);
  int operator()(); // Nivel de poder?

  friend ostream &operator<<(ostream &, const Personaje &);
  friend istream &operator>>(istream &, Personaje &);
};

Personaje::Personaje(string nombre, int danio, int poderTotal, int nivel,
                     int exp, int salud) {

  this->nombre = nombre;
  this->danio = 0;
  this->poderTotal = 0;
  this->nivel = (nivel < 1) ? 1 : nivel;
  this->experiencia = (exp < 0) ? 0 : exp;
  this->salud = (salud < 0) ? 0 : salud;
}

Personaje::~Personaje() {}

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

// TODO
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
  Mago(string);

  ~Mago();

  void atacar() override;
};

Mago::Mago(string n)
    : Personaje(n, 15, 70, 1, 0, 100), danVeneno(50), campFuerza(5) {};

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
  Curandero(string);

  ~Curandero();

  void atacar() override;
};

Curandero::Curandero(string n)
    : Personaje(n, 15, 70, 1, 0, 100), canCuracion(10), rapidez(5) {};

void Curandero::atacar() {
  cout << "El curandero realiza un ataque con su baston!" << endl;
};

Curandero::~Curandero() {
  cout << "Curandero " << nombre << " destruido correctamente" << endl;
}

class Arquero : public Personaje {
private:
  int velocidad;
  int canFlechas;

public:
  Arquero(string);

  ~Arquero();

  void atacar() override;
};

Arquero::Arquero(string n)
    : Personaje(n, 15, 70, 1, 0, 100), velocidad(10), canFlechas(30) {};

Arquero::~Arquero() {
  cout << "Arquero " << nombre << " destruido correctamente..." << endl;
}

void Arquero::atacar() {
  cout << "El arquero realiza un ataque con su arco!" << endl;
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
  int opc;

  if (p == 1) {
    cout << endl << "Escoje tu compañero: " << endl
         << "2. Curandero" << endl
         << "3. Arquero" << endl
         << "4. Mago" << endl;

    cin >> opc;
  } else if (p == 2) {
    cout << endl << "Escoje tu compañero: " << endl
         << "1. Guerrero" << endl
         << "3. Arquero" << endl
         << "4. Mago" << endl;

    cin >> opc;
  } else if (p == 3) {
    cout << endl << "Escoje tu compañero: " << endl
         << "1. Guerrero" << endl
         << "2. Curandero" << endl
         << "4. Mago" << endl;

    cin >> opc;
  } else {
    cout << endl << "Escoje tu compañero: " << endl
         << "1. Guerrero" << endl
         << "2. Curandero" << endl
         << "3. Arquero" << endl;

    cin >> opc;
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

int main() {
    int id_jugador = EscogerPersonaje();

    while (id_jugador == ERROR) {
      cout << "Opcion invalida. Intente de nuevo: " << endl;
      id_jugador = EscogerPersonaje();
    }

    Personaje *jugador = crearPersonaje(id_jugador);
    
    int id_amigo = EscogerCompanero(id_jugador);

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (id_amigo == ERROR) {
      cout << "Opcion invalida. Intente de nuevo: " << endl;
      id_amigo = EscogerCompanero(id_jugador);
    }

    Personaje *amigo = crearPersonaje(id_amigo);

    if (jugador == nullptr || amigo == nullptr) {
      cout << "Error al crear el personaje" << endl;
      return 0;
    }

    cout << dynamic_cast<Personaje&>(*jugador) << endl;
    cout << dynamic_cast<Personaje&>(*amigo) << endl;

    delete jugador;
    delete amigo;

  return 0;
}
