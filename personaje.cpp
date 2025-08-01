#include "Personaje.hpp"
#include <cstdlib> // Para rand()

Personaje::Personaje() {
    vida = 100;
    salud = vida;
    puntosAtaque = 20;
    nivel = 1;
}

Personaje::Personaje(int puntosAtaque) {
    vida = 100;
    salud = vida;
    this->puntosAtaque = puntosAtaque;
    nivel = 1;
}

int Personaje::getVida() const { return vida; }
int Personaje::getSalud() const { return salud; }
int Personaje::getPuntosAtaque() const { return puntosAtaque; }
int Personaje::getNivel() const { return nivel; }

void Personaje::setVida(int vida) { this->vida = vida; }
void Personaje::setSalud(int salud) { this->salud = salud; }
void Personaje::setPuntosAtaque(int puntosAtaque) { this->puntosAtaque = puntosAtaque; }
void Personaje::setNivel(int nivel) { this->nivel = nivel; }

int Personaje::porcentajeSalud() const {
    return (salud * 100) / vida;
}

void Personaje::imprimeBarra() const {
    int porcentaje = porcentajeSalud();
    int llenos = (porcentaje * 20) / 100;
    int vacios = 20 - llenos;

    cout << "[";
    for (int i = 0; i < llenos; i++) cout << "%";
    for (int i = 0; i < vacios; i++) cout << "=";
    cout << "] " << porcentaje << "%" << endl;
}

void Personaje::recibeAtaque(int puntos) {
    salud -= puntos;
    if (salud < 0) salud = 0;
    cout << "El personaje ha recibido " << puntos << " puntos de dano." << endl;
}

void Personaje::imprimir() const {
    cout << "===================" << endl;
    cout << "Personaje Nivel: " << nivel << endl;
    cout << "Vida maxima: " << vida << endl;
    cout << "Salud actual: " << salud << endl;
    cout << "Puntos de ataque: " << puntosAtaque << endl;
    imprimeBarra();
    cout << "===================" << endl;
}

bool Personaje::operator>(const Personaje& otro) const {
    return nivel > otro.nivel;
}
