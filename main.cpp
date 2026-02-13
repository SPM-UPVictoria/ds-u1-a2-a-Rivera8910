#include <iostream>
#include <iomanip>
#include <vector>
#include "Carga.h"

using namespace std;

const double K = 9.0;


const int FILAS = 10;
const int COLUMNAS = 10;

/**
 * Función template para calcular el campo eléctrico
 * E = k * q / d^2
 * 
 * @param k Constante del campo eléctrico
 * @param q Valor de la carga
 * @param d Distancia entre la carga y el punto
 * @return Campo eléctrico generado
 */
template <typename T>
T calcularCampoElectrico(T k, T q, T d) {

    if (d < 0.0001) {
        d = 0.0001;  
    }
    return (k * q) / (d * d);
}

template <typename T>
T calcularCampoTotal(T x, T y, const vector<Carga>& cargas) {
    T campoTotal = 0.0;
    
    for (const Carga& carga : cargas) {
        T distancia = carga.calcularDistancia(x, y);
        T campo = calcularCampoElectrico<T>(K, carga.getCarga(), distancia);
        campoTotal += campo;
    }
    
    return campoTotal;
}

/**
 * Función para llenar la matriz con los valores del campo eléctrico
 */
template <typename T>
void llenarMatrizCampo(T matriz[FILAS][COLUMNAS], const vector<Carga>& cargas) {
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            // Calcular el campo en la posición (i, j)
            matriz[i][j] = calcularCampoTotal<T>(static_cast<T>(i), 
                                                   static_cast<T>(j), 
                                                   cargas);
        }
    }
}

template <typename T>
void imprimirMatriz(T matriz[FILAS][COLUMNAS]) {
    cout << "  CAMPO ELÉCTRICO EN LA PLACA (10x10)  " << endl;
    cout << "     ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << setw(8) << j << " ";
    }
    cout << endl;
    
    cout << "    ";
    for (int j = 0; j < COLUMNAS; j++) {
        cout << "---------";
    }
    cout << endl;
    
    // Imprimir filas
    for (int i = 0; i < FILAS; i++) {
        cout << setw(2) << i << " | ";
        for (int j = 0; j < COLUMNAS; j++) {
            cout << setw(8) << fixed << setprecision(2) << matriz[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
 
    double placa[FILAS][COLUMNAS];
 
    vector<Carga> cargas;

    cout << "  SIMULACIÓN DE CAMPO ELÉCTRICO" << endl;

    // Definir algunas cargas de ejemplo
    cout << "Configuración de cargas:\n" << endl;
    
    cargas.push_back(Carga(2.0, 2.0, 5.0));
    cout << "  Carga 1: Posición (2, 2), q = +5.0 C" << endl;
    
    cargas.push_back(Carga(7.0, 7.0, -3.0));
    cout << "  Carga 2: Posición (7, 7), q = -3.0 C" << endl;
    
    cargas.push_back(Carga(5.0, 5.0, 4.0));
    cout << "  Carga 3: Posición (5, 5), q = +4.0 C" << endl;
    
    cargas.push_back(Carga(1.0, 8.0, -2.0));
    cout << "  Carga 4: Posición (1, 8), q = -2.0 C" << endl;
    
    cout << "\nConstante k = " << K << endl;
    cout << "\nCalculando campo eléctrico en cada punto..." << endl;
    
    // Llenar la matriz con los valores del campo eléctrico
    llenarMatrizCampo<double>(placa, cargas);
    
    // Imprimir la matriz resultante
    imprimirMatriz<double>(placa);
    
    cout << "Nota: Los valores positivos indican campo en dirección" << endl;
    cout << "      positiva y los negativos en dirección negativa." << endl;
    cout << "\nSimulación completada con éxito." << endl;
    
    return 0;
}
