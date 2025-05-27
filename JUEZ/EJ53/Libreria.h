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

class Libreria {
    private:

    struct tLibro{
        string nombre;
        int ventas;
        bool operator<(tLibro otro){
            if (this->ventas < otro.ventas){
                return true;
            }
            else if (this->ventas > otro.ventas){
                return false;
            }
            else {
                return this->nombre < otro.nombre;
            }
        }
        bool operator==(tLibro otro){
            return this->ventas == otro.ventas && this->nombre == otro.nombre;
        }
    };
    map<string, tuple<int, int, list<tLibro>::iterator>> libros;
    list<tLibro> _top;

    public:

    Libreria(): _top(10){};

    void nuevo_libro(string nom, int can){
        auto it = libros.find(nom);
        if (it == libros.end()){
            libros[nom] = make_tuple(can, 0, _top.end());
            get<3> (it->second) = _top.end();
            tLibro l = {nom, 0};
            _top.push_back(l);
        }
        else {
            get<0>(it->second) += can;
        }
    }

    void comprar(string nom){
        auto it = libros.find(nom);
        if (it == libros.end()){
            throw invalid_argument("Libro no existente");
        }
        else if ( get<0>(it->second) <= 0){
            throw out_of_range("No hay ejemplares");
        }
        else {
            get<0>(it->second)--;
            get<1>(it->second)++;

        }
    }

    bool estaLibro(string nom){
        auto it = libros.find(nom);
        return it != libros.end();
    }

    void elim_libro(string nom, int can){
        auto it = libros.find(nom);
        if (it == libros.end()){
            return;
        }
        else {
            libros.erase(it);
        }
    }

    int numEjemplares(string nom){
         auto it = libros.find(nom);
        if (it == libros.end()){
            throw invalid_argument("Libro no existente");
        }
        else {
            return  get<0>(it->second);
        }
    }

    vector<string> top10(){
        
    }

};