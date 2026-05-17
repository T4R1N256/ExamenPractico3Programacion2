#ifndef HABILIDADESPECIAL_H
#define HABILIDADESPECIAL_H

template <typename T>
class HabilidadEspecial {
private:
    T poder; // se suma cada que hace un ataque, contador
    T poderMaximo;

public:
    HabilidadEspecial(T poderMaximo) : poder(0), poderMaximo(poderMaximo) {}

    T getPoder();
    T getPoderMaximo();
    void cargar();
    void resetPoder();

    
};

#endif