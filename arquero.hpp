#pragma once
#include "Personaje.hpp"

class Arquero : public Personaje {
private:
    float precision; // Probabilidad de tiro crítico
    bool yaRevivio = false;

public:
    Arquero(int puntosAtaque, float precision);

    void atacar(Personaje& objetivo) override;
    void recibeAtaque(int puntos) override;
    void imprimir() const override;
    void revive() override;
};
