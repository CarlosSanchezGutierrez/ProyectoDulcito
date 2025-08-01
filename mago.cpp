#include "Mago.hpp"
#include <iostream>
using namespace std;

Mago::Mago(int puntosAtaque, int maná)
    : Personaje(puntosAtaque), maná(maná) {}

void Mago::atacar(Personaje& objetivo) {
    int baseDamage = (rand() % (getPuntosAtaque() / 2)) + (getPuntosAtaque() / 2);
    bool hechizoFuerte = (rand() % 100) < maná;
    if (hechizoFuerte) {
        baseDamage *= 2;
        cout << "Mago lanza un hechizo fuerte. Dano: " << baseDamage << endl;
    } else {
        cout << "Mago ataca con dano normal: " << baseDamage << endl;
    }
    objetivo.recibeAtaque(baseDamage);

    if (objetivo.getSalud() == 0) {
        maná += 10;
        cout << "El Mago absorbe mana del enemigo derrotado. Mana actual: "
             << maná << endl;
    }
}

void Mago::recibeAtaque(int puntos) {
    if (getNivel() >= 4 && maná > 80) {
        puntos /= 3;
        cout << "Mago reduce el dano a 1/3 gracias a su mana." << endl;
    } else if (getNivel() >= 3 && maná > 60) {
        puntos /= 2;
        cout << "Mago reduce el dano a la mitad gracias a su mana." << endl;
    } else if (getNivel() >= 2 && maná == 100) {
        puntos = static_cast<int>(puntos * 0.75);
        cout << "Mago reduce el dano a 75% gracias a su mana." << endl;
    }
    Personaje::recibeAtaque(puntos);

    if (getSalud() == 0) {
        revive();
    }
}

void Mago::imprimir() const {
    Personaje::imprimir();
    cout << "Mana: " << maná << endl;
}

void Mago::revive() {
    if (getSalud() == 0 && maná > 70 && !yaRevivio) {
        setSalud(getVida() * 0.4); // revive con 40% de vida
        maná -= 50;
        yaRevivio = true;
        cout << "¡El Mago revive magicamente!" << endl;
    } else if (getSalud() == 0) {
        cout << "El Mago ha muerto." << endl;
    }
}
