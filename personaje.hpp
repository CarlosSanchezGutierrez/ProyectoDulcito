// Crear el archivo header de la clase Personaje, no olvides las guardas o el pragma.
#pragma once
#include <iostream>
using namespace std;

class Personaje{
public:
    Personaje();
    Personaje(int puntosAtaque);

    int getVida() const;
    int getSalud() const;
    int getPuntosAtaque() const;

    void setVida(int vida);
    void setSalud(int salud);
    void setPuntosAtaque(int puntosAtaque);
    void setNivel(int nivel);
    int getNivel() const; // ya no es virtual

    int porcentajeSalud() const;
    void imprimeBarra() const; // ya no es virtual

    virtual void recibeAtaque(int puntos);
    virtual void atacar(Personaje& objetivo) = 0; // ahora es virtual puro
    virtual void imprimir() const;
    virtual void revive() = 0;

    bool operator>(const Personaje& otro) const;

private:
    int vida, salud, puntosAtaque, nivel;
};
