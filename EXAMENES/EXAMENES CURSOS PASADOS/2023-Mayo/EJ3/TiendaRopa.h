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

class TiendaRopa {
    private:

    list<string> camisetas;
    unordered_map<string, deque<list<string>::iterator>> localizadores;

    public:

    TiendaRopa(){
    }

    void insertar_izquierda(string color){
        camisetas.push_front(color);
        localizadores[color].push_front(camisetas.begin());
    }

    void insertar_derecha(string color){
        camisetas.push_back(color);
        list<string>::iterator it = camisetas.end();
        it--;
        localizadores[color].push_back(it);
    }

    void compra_izquierda(){
        if (camisetas.empty()){
            throw domain_error ("Tienda sin camisetas");
        }
        string color = camisetas.front();
        camisetas.pop_front();
        localizadores[color].pop_front();
    }

    void compra_derecha(){
        if (camisetas.empty()){
            throw domain_error ("Tienda sin camisetas");
        }
        string color = camisetas.back();
        camisetas.pop_back();
        localizadores[color].pop_back();
    }

    string pregunta(){
        bool hay = false;

        int iz = 1;
        auto itIz = camisetas.begin();
        while (itIz != camisetas.end() && localizadores[*itIz].front() != localizadores[*itIz].back()){
            iz++;
            itIz++;
        }
        if (itIz != camisetas.end()){
            hay = true;
        }

        int dr = 1;
        auto itDr = camisetas.end();
        itDr--;
        while (itDr != camisetas.begin() && localizadores[*itDr].front() != localizadores[*itDr].back()){
            dr++;
            itDr--;
        }

        if (hay){
            if (iz < dr){
                return to_string(iz) + " IZQUIERDA";
            }
            else if (iz > dr){
                return to_string(dr) + " DERECHA";
            }
            else if (iz == dr){
                return to_string(iz) + " CUALQUIERA";
            }
        }
        return "NADA INTERESANTE";
    }
};