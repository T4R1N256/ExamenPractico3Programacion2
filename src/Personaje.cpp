#include "Personaje.h"

Personaje::Personaje() {
  this->nombre = "DEFAULT";
  this->tipo = "DEFAULT";
  this->danio = 1;
  this->nivel = 1;
  this->experiencia = 0;
  this->salud = 1;
  this->saludMaxima = 1;
  this->vivo = true;
  this->esCritico = false;
  this->poderMaximo = 10;
}

Personaje::Personaje(string nombre, string tipo, int danio,
                     int nivel, int exp, int salud, bool vivo) {

  this->nombre = nombre;
  this->tipo = tipo;
  this->danio = danio;
  this->nivel = (nivel < 1) ? 1 : nivel;
  this->experiencia = (exp < 0) ? 0 : exp;
  this->salud = salud;
  this->saludMaxima = salud;
  this->vivo = vivo;
  this->esCritico = false; // inicializar esCritico
  this->poderMaximo = 10;
}

Personaje::~Personaje() {}

/* No necesario al ser virtual puro
void Personaje::atacar(Personaje &otro) {
  otro.recibirDanio(danio);
  if (otro.salud <= 0) {
    otro.vivo = false;
  }
  cout << nombre << " realiza un ataque generico!" << endl;
}
*/

void Personaje::subirNivel(int n) {
  nivel = n;

  int correct_n = n - 1;

  if (poderMaximo > 0)
    poderMaximo--;
  salud = saludMaxima += 20 * correct_n;
  danio += (5 * correct_n);
  cout << '\n' << nombre << " ha subido al nivel " << nivel << "!" << endl;
}

void Personaje::cargarExperiencia(int xp) {
  cout << '\n' << this->nombre << "(" << this->tipo << ") pasa a la siguiente ronda con " << xp << " XP" << endl;
  if (xp <= 0)
    return;

  experiencia = ((nivel - 1) * 100) + xp;

  if (experiencia >= 100)
   {
    nivel = (experiencia / 100) + 1;
    experiencia -= 100 * (nivel - 1);
   }

  if (nivel > 1)
    subirNivel(nivel);
}

Personaje &Personaje::operator+(int xp) {
  cargarExperiencia(xp);
  return *this;
}

bool Personaje::operator>(const Personaje &otro) {
  return experiencia > otro.experiencia;
}

void Personaje::recibirDanio(int danioRecibido) {
  salud -= danioRecibido;
  if (salud <= 0) {
    salud = 0;
    vivo = false;
  } else if (salud <= (saludMaxima * 0.2)) {
    esCritico = true;
  }
}

void Personaje::recibirCuracion(int vidaRecibida) {
  if (estaVivo()) {
    salud += vidaRecibida;
    if (salud > saludMaxima) {
      salud = saludMaxima;
    }
    if (salud > (saludMaxima * 0.2)) {
      esCritico = false;
    }
  }
}

bool Personaje::estaVivo() { return vivo; }

bool Personaje::estaCritico() { return esCritico; }

string Personaje::getNombre() { return nombre; }

string Personaje::getTipo() { return tipo; }

int Personaje::getSalud() { return salud; }

string Personaje::operator()() { 
  return this->tipo + ": " + to_string(this->salud) + "/" + to_string(this->saludMaxima) + " HP"; 
}

ostream &operator<<(ostream &os, const Personaje &p) {
  os << '"' << p.nombre << "\"" << " | Tipo: " << p.tipo << " | Nivel: " << p.nivel << " | XP: " << p.experiencia
     << " | Salud: " << p.salud << " | Daño base: " << p.danio;

  return os;
}

istream &operator>>(istream &is, Personaje &p) {
  cout << "Ingresa el nombre del personaje: ";
  getline(is, p.nombre);
  return is;
}
