#include "Arquero.hpp"
#include <iostream>
#include <algorithm> // necesario para max
using namespace std;

Arquero::Arquero(int puntosAtaque, float precision)
    : Personaje(puntosAtaque), precision(precision) {}

void Arquero::atacar(Personaje& objetivo) {
    int divisor = max(1, getPuntosAtaque() / 2); // evita division entre 0
    int baseDamage = (rand() % divisor) + divisor;

    bool critico = (static_cast<float>(rand()) / RAND_MAX) < precision;
    if (critico) {
        baseDamage = static_cast<int>(baseDamage * 1.5);
        cout << "Arquero realiza un tiro critico. Dano: " << baseDamage << endl;
    } else {
        cout << "Arquero ataca con dano normal: " << baseDamage << endl;
    }

    objetivo.recibeAtaque(baseDamage);
}

void Arquero::recibeAtaque(int puntos) {
    Personaje::recibeAtaque(puntos);
    if (getSalud() == 0) {
        revive();
    }
}

void Arquero::imprimir() const {
    Personaje::imprimir();
    cout << "Precision: " << precision * 100 << "%" << endl;
}

void Arquero::revive() {
    if (getSalud() == 0 && precision > 0.85f && !yaRevivio) {
        setSalud(getVida() * 0.2); // revive con 20% de vida
        yaRevivio = true;
        cout << "¡Arquero no muere gracias a su precision!" << endl;
    } else if (getSalud() == 0) {
        cout << "El Arquero ha muerto." << endl;
    }
}
