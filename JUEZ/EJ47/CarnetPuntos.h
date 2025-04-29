#ifndef CARNETPUNTOS_H
#define CARNETPUNTOS_H

#include <string>
#include <map>
#include <set>
#include <stdexcept>

using namespace std;

class CarnetPuntos {
public:
    // Constructor
    CarnetPuntos() : personas(), puntos(16, 0) {} // Inicializa el vector de puntos con 16 elementos (0 a 15)

    // Métodos públicos (declaraciones, no implementación)
    void nuevo(const string& dni){
        auto it = personas.find(dni);
        if (it == personas.end()) {
            personas[dni] = 15;
            puntos[15]++; // Incrementa el contador de puntos
        } else {
            throw domain_error("Conductor duplicado");
        }
    }
    void quitar(const string& dni, int _puntos){
        auto it = personas.find(dni);
        if (it != personas.end()) {
            puntos[it->second]--; // Decrementa el contador de puntos actuales
            it ->second -= _puntos; // Resta puntos
            it ->second = max(it ->second, 0); // Asegura que no sea negativo
            puntos[it->second]++; // Incrementa el contador de nuevos puntos
        } else {
            throw domain_error("Conductor inexistente");
        }
    }
    int consultar(const string& dni) {
        auto it = personas.find(dni);
        if (it != personas.end()) {
            return it->second; // Devuelve los puntos
        } else {
            throw domain_error("Conductor inexistente");
        }
    }
    int cuantos_con_puntos(int _puntos) {
        if (_puntos < 0 || _puntos > 15) {
            throw domain_error("Puntos no validos");
        }
        int count = puntos[_puntos]; // Obtiene el número de conductores con 'puntos'
        return count; // Devuelve el número de conductores con más de 'puntos'
    }

private:
    // Atributos privados
    unordered_map<string, int> personas;
    vector<int> puntos; // Vector para contar los puntos de cada conductor
};

#endif // CARNETPUNTOS_H