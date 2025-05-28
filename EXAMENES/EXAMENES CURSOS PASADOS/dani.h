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

class TiendaCamisetas {
private:
    //uso list porque quiero acceder al principio, al final y a valores intermedios
    list<string> barraCamisetas;

    //uso unordered_map porque me da igual el orden
    unordered_map<string, int> colorCuantas;


public:

    void inserta_izquierda(string color) {
        barraCamisetas.push_front(color); //O(1)
        colorCuantas[color]++; //O(1)
    }
    //El coste es O(1)

    void inserta_derecha(string color) {
        barraCamisetas.push_back(color); //O(1)
        colorCuantas[color]++; //O(1)
    }
    //El coste es O(1)

    void compra_izquierda() {
        if (barraCamisetas.empty())
            throw std::domain_error("Tienda sin camisetas");
        string color = barraCamisetas.front(); //O(1)
        if (colorCuantas[color] == 1) { //O(1)
            colorCuantas.erase(color); //O(1)
        }
        else {
            colorCuantas[color]--; //O(1)
        }
        barraCamisetas.pop_front(); //O(1)
    }
    //El coste es O(1)

    void compra_derecha() {
        if (barraCamisetas.empty())
            throw std::domain_error("Tienda sin camisetas");
       string color = barraCamisetas.back(); //O(1)
        if (colorCuantas[color] == 1) { //O(1)
            colorCuantas.erase(color); //O(1)
        }
        else {
            colorCuantas[color]--; //O(1)
        }
        barraCamisetas.pop_back(); //O(1)
    }
    //El coste es O(1)

    string pregunta() {
        int mejorIz = barraCamisetas.size();
        int cont = 1;
        string color;
        for (auto it = barraCamisetas.begin(); it != barraCamisetas.end() && mejorIz == barraCamisetas.size(); ++it) {
            color = *it;
            if (colorCuantas[color] == 1) mejorIz = cont;
            cont++;
        }
        int mejorDer = barraCamisetas.size();
        cont = 1;
        for(auto it = barraCamisetas.rbegin(); it != barraCamisetas.rend() && mejorDer == barraCamisetas.size(); ++it){
            color = *it;
            if (colorCuantas[color] == 1) mejorDer = cont;
            cont++;
        }
        if (mejorDer == barraCamisetas.size() && mejorIz == barraCamisetas.size())
            return "NADA INTERESANTE";
        else if (mejorDer == mejorIz)
            return to_string(mejorDer) + " CUALQUIERA";
        else if (mejorDer < mejorIz)
            return to_string(mejorDer) + " DERECHA";
        else return to_string(mejorIz) + " IZQUIERDA";
    }
    //El coste en el caso peor es O(N) siendo N el numero de camisetas

};