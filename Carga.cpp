#include "Carga.h"

// Constructor
Carga::Carga(double x, double y, double carga) 
    : posX(x), posY(y), q(carga) {
}

// Getters
double Carga::getPosX() const {
    return posX;
}

double Carga::getPosY() const {
    return posY;
}

double Carga::getCarga() const {
    return q;
}

// Calcular distancia euclidiana desde la carga hasta un punto (x, y)
double Carga::calcularDistancia(double x, double y) const {
    double dx = x - posX;
    double dy = y - posY;
    return std::sqrt(dx * dx + dy * dy);
}
