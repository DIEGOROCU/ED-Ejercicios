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

class FantasiaFinal {
    private:

    struct tHeroe {
        string nombre;
        int vida;
        map<string, int> ataques;
    };
    unordered_map<string, pair<tHeroe, list<pair<string, int>>::iterator>> heroes;

    struct tVillano {
        string nombre;
        int vida;
        int ataque;
    };
    unordered_map<string, pair<tVillano, list<pair<string, int>>::iterator>>villanos;

    list<pair<string, int>> turnos;

    unordered_set<string> personajes;

    /*tHeroe& find_heroe(string h){
        auto it = heroes.find(h);
        if (it == heroes.end()){
            return nullptr;
        }
        return it->second;

    }*/

    public:

    void aparece_villano(string v, int s, int a){
        auto it = personajes.find(v);
        if (it != personajes.end()){
            throw invalid_argument("Personaje ya existente");
        }
        tVillano villano;
        villano.nombre = v;
        villano.vida = s;
        villano.ataque = a;
        turnos.push_back(make_pair(v, s));
        auto itTurno = turnos.end();
        --itTurno;
        villanos[v] = make_pair(villano, itTurno);
        personajes.insert(v);
    }

    void aparece_heroe(string h, int s){
        auto it = personajes.find(h);
        if (it != personajes.end()){
            throw invalid_argument("Personaje ya existente");
        }
        tHeroe heroe;
        heroe.nombre = h;
        heroe.vida = s;
        heroe.ataques.clear();
        turnos.push_back(make_pair(h, s));
        auto itTurno = turnos.end();
        --itTurno;
        heroes[h] = make_pair(heroe, itTurno);
        personajes.insert(h);
    }

    void aprende_ataque(string h, string a, int v){
        auto it = heroes.find(h);
        if (it == heroes.end()){
            throw invalid_argument("Heroe inexistente");
        }
        else {
            tHeroe& heroe = it->second.first;
            auto itAtaque = heroe.ataques.find(a);
            if (itAtaque != heroe.ataques.end()){
                throw invalid_argument("Ataque repetido");
            }
            else {
                heroe.ataques[a] = v;
            }
        }
    }

    vector<pair<string, int>> mostrar_ataques(string h){
        auto it = heroes.find(h);
        if (it == heroes.end()){
            throw invalid_argument("Heroe inexistente");
        }
        else {
            vector<pair<string, int>> dev;
            for (auto a : it->second.first.ataques){
                dev.push_back(make_pair(a.first, a.second));
            }
            return dev;
        }
    }

    vector<pair<string, int>> mostrar_turnos() {
        return vector<pair<string, int>>(turnos.begin(), turnos.end());
    }

    bool villano_ataca(string v, string h){
        auto itV = villanos.find(v);
        auto itH = heroes.find(h);
        if (itV == villanos.end()){
            throw invalid_argument("Villano inexistente");
        }
        if (itH == heroes.end()){
            throw invalid_argument("Heroe inexistente");
        }
        tVillano& villano = itV->second.first;
        tHeroe& heroe = itH->second.first;
        if (turnos.front().first != villano.nombre){
            throw invalid_argument("No es su turno");
        }
        heroe.vida -= villano.ataque;
        bool eliminado = false;
        if (heroe.vida <= 0){
            turnos.erase(itH->second.second);
            heroes.erase(itH); // Elimina completamente al héroe
            eliminado = true;
        }
        else {
            auto itHTurno = itH->second.second;
            itHTurno->second -= villano.ataque;
        }
        turnos.push_back(make_pair(v, villano.vida));
        auto itTurno = turnos.end();
        --itTurno;
        villanos[v] = make_pair(villano, itTurno);
        turnos.pop_front();
        return eliminado;
    }

    bool heroe_ataca(string h, string a, string v){
        auto itV = villanos.find(v);
        auto itH = heroes.find(h);
        if (itV == villanos.end()){
            throw invalid_argument("Villano inexistente");
        }
        if (itH == heroes.end()){
            throw invalid_argument("Heroe inexistente");
        }
        tVillano& villano = itV->second.first;
        tHeroe& heroe = itH->second.first;
        if (turnos.front().first != heroe.nombre){
            throw invalid_argument("No es su turno");
        }
        auto ataque = heroe.ataques.find(a);
        if (ataque == heroe.ataques.end()){
            throw invalid_argument("Ataque no aprendido");
        }
        villano.vida -= ataque->second;
        bool eliminado = false;
        if (villano.vida <= 0){
            turnos.erase(itV->second.second);
            villanos.erase(itV); // Elimina completamente al héroe
            eliminado = true;
        }
        else {
            auto itVTurno = itV->second.second;
            itVTurno->second -= ataque->second;
        }
        turnos.push_back(make_pair(h, heroe.vida));
        auto itTurno = turnos.end();
        --itTurno;
        heroes[h] = make_pair(heroe, itTurno);
        turnos.pop_front();
        return eliminado;
    }

};