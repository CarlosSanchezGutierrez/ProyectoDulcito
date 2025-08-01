#include <iostream>
#include <vector>
#include "Personaje.hpp"
#include "Guerrero.hpp"
#include "Mago.hpp"
#include "Arquero.hpp"
using namespace std;

int main() {
    // Creamos un vector de apuntadores a Personaje
    vector<Personaje*> personajes;

    // Creamos dinámicamente un objeto de cada clase derivada
    personajes.push_back(new Guerrero(1, 3));
    personajes.push_back(new Arquero(3, 0.4f));
    personajes.push_back(new Mago(2, 90));

    // Imprimimos todos los personajes
    cout << "\n=== Lista de personajes ===\n";
    for (Personaje* p : personajes) {
        p->imprimir();
    }

    // Simulamos ataques entre personajes
    cout << "\n=== Combates ===\n";

    cout << "\n=== El guerrero ataca al arquero ===" << endl;
    personajes[0]->atacar(*personajes[1]);
    personajes[1]->imprimir();

    cout << "\n=== El arquero ataca al guerrero ===" << endl;
    personajes[1]->atacar(*personajes[0]);
    personajes[0]->imprimir();

    cout << "\n=== El mago ataca al arquero ===" << endl;
    personajes[2]->atacar(*personajes[1]);
    personajes[1]->imprimir();

    // Prueba de sobrecarga del operador >
    cout << "\n=== Comparación de niveles ===" << endl;
    cout << "Nivel del personaje 1 (Arquero): " << personajes[1]->getNivel() << endl;
    cout << "Nivel del personaje 2 (Mago): " << personajes[2]->getNivel() << endl;

    if (*personajes[1] > *personajes[2]) {
        cout << "El personaje 1 tiene mayor nivel que el personaje 2." << endl;
    } else {
        cout << "El personaje 1 no tiene mayor nivel que el personaje 2." << endl;
    }

    // Liberamos memoria
    for (Personaje* p : personajes) {
        delete p;
    }

    return 0;
}
