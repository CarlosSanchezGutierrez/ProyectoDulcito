#include "Guerrero.hpp"
#include <iostream>
using namespace std;

Guerrero::Guerrero(int puntosAtaque, int fuerza)
    : Personaje(puntosAtaque), fuerza(fuerza) {}

void Guerrero::atacar(Personaje& objetivo) {
    int base = getPuntosAtaque();
    int mitad = base / 2;
    int baseDamage = rand() % (base - mitad + 1) + mitad; // arreglo: daño entre mitad y base
    int totalDamage = baseDamage + (fuerza / 2);
    cout << "Guerrero potencia su ataque con fuerza (" << fuerza << "): "
         << totalDamage << " puntos de dano." << endl;
    objetivo.recibeAtaque(totalDamage);
}

void Guerrero::recibeAtaque(int puntos) {
    if (fuerza > 50) {
        puntos = static_cast<int>(puntos * 0.8);
        cout << "Guerrero reduce dano gracias a su fuerza. Dano reducido a "
             << puntos << " puntos." << endl;
    }
    Personaje::recibeAtaque(puntos);

    if (getSalud() == 0) {
        revive();
    }
}

void Guerrero::imprimir() const {
    Personaje::imprimir();
    cout << "Fuerza: " << fuerza << endl;
}

void Guerrero::revive() {
    if (getSalud() == 0 && fuerza > 70 && !yaRevivio) {
        setSalud(getVida() * 0.3); // revive con 30% de vida
        yaRevivio = true;
        cout << "¡Guerrero revive gracias a su fuerza!" << endl;
    } else if (getSalud() == 0) {
        cout << "El Guerrero ha muerto." << endl;
    }
}
