#ifndef CARNETPUNTOS_H
#define CARNETPUNTOS_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cctype>

#include <stack>
#include <queue>
#include <deque>

#include <list>
#include <forward_list>

#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <tuple>

using namespace std;

using namespace std;

class CarnetPuntos {
public:
    // Constructor
    CarnetPuntos() : personas(), puntos(16, vector<string>(0, "")) {} // Inicializa el vector de puntos con 16 elementos (0 a 15)

    // Métodos públicos (declaraciones, no implementación)
    void nuevo(const string& dni){
        auto it = personas.find(dni);
        if (it == personas.end()) {
            personas[dni] = 15;
            puntos[15].push_back(dni); // Añade el dni al vector de puntos 15
        } else {
            throw domain_error("Conductor duplicado");
        }
    }
    void quitar(const string& dni, int _puntos){
        auto it = personas.find(dni);
        if (it != personas.end() && it->second > 0) {
            puntos[it->second].erase(remove(puntos[it->second].begin(), puntos[it->second].end(), dni), puntos[it->second].end()); // Elimina el dni del vector de puntos actuales
            it ->second -= _puntos; // Resta puntos
            it ->second = max(it ->second, 0); // Asegura que no sea negativo
            puntos[it->second].push_back(dni); // Añade el dni al vector de nuevos puntos
        } else if (it == personas.end()) {
            throw domain_error("Conductor inexistente");
        }
    }
    void recuperar(const string& dni, int _puntos) {
        auto it = personas.find(dni);
        if (it != personas.end() && it->second < 15) {
            puntos[it->second].erase(remove(puntos[it->second].begin(), puntos[it->second].end(), dni), puntos[it->second].end()); // Elimina el dni del vector de puntos actuales
            it->second += _puntos; // Suma puntos
            it->second = min(it->second, 15); // Asegura que no supere 15
            puntos[it->second].push_back(dni); // Añade el dni al vector de nuevos puntos
        } else if (it == personas.end()) {
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
        int count = puntos[_puntos].size(); // Cuenta el número de conductores con los puntos solicitados
        return count; // Devuelve el número de conductores con más de 'puntos'
    }
    vector<string> lista_con_puntos(int _puntos) {
        if (_puntos < 0 || _puntos > 15) {
            throw domain_error("Puntos no validos");
        }
        return puntos[_puntos]; // Devuelve la lista de conductores con los puntos solicitados
    }

private:
    // Atributos privados
    unordered_map<string, int> personas;
    vector<vector<string>> puntos; // Vector para contar los puntos de cada conductor
};

#endif // CARNETPUNTOS_H