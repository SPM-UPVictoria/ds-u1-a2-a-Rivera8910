#ifndef CARGA_H
#define CARGA_H

#include <cmath>
class Carga {
private:
    double posX;  // Posición en el eje X
    double posY;  // Posición en el eje Y
    double q;     // Valor de la carga (positiva o negativa)

public:
    Carga(double x, double y, double carga);
    double getPosX() const;
    double getPosY() const;
    double getCarga() const;
    
    double calcularDistancia(double x, double y) const;
};

#endif // CARGA_H
