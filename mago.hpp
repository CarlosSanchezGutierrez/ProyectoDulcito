#pragma once
#include "Personaje.hpp"

class Mago : public Personaje {
private:
    int maná;
    bool yaRevivio = false;

public:
    Mago(int puntosAtaque, int maná);

    void atacar(Personaje& objetivo) override;
    void recibeAtaque(int puntos) override;
    void imprimir() const override;
    void revive() override;
};
