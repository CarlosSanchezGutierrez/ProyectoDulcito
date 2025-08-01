#pragma once
#include "Personaje.hpp"

class Guerrero : public Personaje {
private:
    int fuerza; // Potenciador del ataque y defensa
    bool yaRevivio = false;

public:
    Guerrero(int puntosAtaque, int fuerza);

    void atacar(Personaje& objetivo) override;
    void recibeAtaque(int puntos) override;
    void imprimir() const override;
    void revive() override;
};
