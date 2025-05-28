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

class Subastas {
    private:

    struct tPersona {
        int saldo;
        unordered_map<string, tuple<int, list<string>::iterator, map<int, list<string>>::iterator>> sus_pujas;
        set<string> objetos_ganados;
    };
    struct tObjeto {
        //pair<int, string> ganador;
        int puja_minima;
        map<int, list<string>, greater<int>> pujadores;
        bool vendido;
    };

    unordered_map<string, tPersona> personas;
    unordered_map<string, tObjeto> objetos;

    public:

    void nuevo_participante(string part, int saldo_inicial) {
        auto it = personas.find(part);
        if (it != personas.end()){
            throw domain_error("Participante ya existente");
        }
        if (saldo_inicial <= 0){
            throw domain_error("Saldo inicial no valido");
        }
        tPersona p;
        p.saldo = saldo_inicial;
        personas[part] = p;
    }

    void nueva_subasta(string obj, int puja_min) {
        auto it = objetos.find(obj);
        if (it != objetos.end()){
            throw domain_error("Objeto no valido");
        }
        if (puja_min <= 0){
            throw domain_error("Puja inicial no valida");
        }
        tObjeto o;
        o.puja_minima = puja_min;
        o.vendido = false;
        objetos[obj] = o;
    }

    void nueva_puja(string part, string obj, int cantidad) {
        auto itP = personas.find(part);
        if (itP == personas.end()){
            throw domain_error("Participante no existente");
        }
        auto itO = objetos.find(obj);
        if (itO == objetos.end()){
            throw domain_error("Objeto no valido");
        }
        if (itO->second.vendido){
            throw domain_error("Objeto no valido");
        }
        if (itP->second.sus_pujas.count(obj)){
            throw domain_error("Participante repetido");
        }
        if (cantidad > itP->second.saldo || cantidad < itO->second.puja_minima){
            throw domain_error("Cantidad no valida");
        }
        auto itAnadir = itO->second.pujadores[cantidad].insert(itO->second.pujadores[cantidad].end(), part);
        itP->second.saldo -= cantidad;
        itP->second.sus_pujas[obj] = make_tuple(cantidad, itAnadir, itO->second.pujadores.find(cantidad));
    }

    list<string> subastas_ganadas(string part) const {
        auto itP = personas.find(part);
        if (itP == personas.end()){
            throw domain_error("Participante no existente");
        }
        list<string> dev(itP->second.objetos_ganados.begin(), itP->second.objetos_ganados.end());
        return dev;
    }

    void abandonar_casa(string part) {
        auto itP = personas.find(part);
        if (itP == personas.end()){
            throw domain_error("Participante no existente");
        }
        for (auto [objeto, pair] : itP->second.sus_pujas){
            auto [cantidad, iterador, itMapa] = pair;
            if (!objetos[objeto].vendido){
                objetos[objeto].pujadores[cantidad].erase(iterador);
                if (objetos[objeto].pujadores[cantidad].empty()){
                    objetos[objeto].pujadores.erase(itMapa);
                }
            }
        }
        personas.erase(part);
    }

    string cerrar_subasta(string obj) {
        auto itO = objetos.find(obj);
        if (itO == objetos.end()){
            throw domain_error("Objeto no valido");
        }
        if (itO->second.vendido){
            throw domain_error("Objeto no valido");
        }
        if (itO->second.pujadores.empty()){
            throw domain_error("Objeto no vendido");
        }
        bool hayGan = false;
        string gan;
        for (auto [cantidad, lista] : itO->second.pujadores){
            for (string nom : lista){
                if (!hayGan){
                    personas[nom].objetos_ganados.insert(obj);
                    hayGan = true;
                    gan = nom;
                } else {
                    personas[nom].saldo += cantidad;
                }
            }
        }
        itO->second.vendido = true;
        return gan;
    }

};