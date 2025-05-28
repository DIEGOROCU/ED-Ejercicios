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

class Camping {
    private:

    unordered_map <int, unordered_map<int, list<string>>> parcelas;
    unordered_map <int, map<int, list<string>>> parcelas_porPos;
    unordered_map <int, map<int, list<string>>> parcelas_porDia;
    //set<string> personasListaEspera;
    unordered_map<string, tuple<int, int, map<int, list<string>>::iterator, map<int, list<string>>::iterator>> personasParcelas;

    public:

    void nueva_reserva(const string &persona, int parcela, int dia){
        auto itPersona = personasParcelas.find(persona);
        if (itPersona != personasParcelas.end()){
            throw domain_error("Persona ya ha reservado");
        }
        parcelas[dia][parcela].push_back(persona);
        // Asegura que la lista existe antes de obtener el iterador
        auto& listaPorPos = parcelas_porPos[parcela][dia];
        auto itPorPos = parcelas_porPos[parcela].find(dia);
        listaPorPos.push_back(persona);
        auto& listaPorDia = parcelas_porDia[dia][parcela];
        auto itPorDia = parcelas_porDia[dia].find(parcela);
        listaPorDia.push_back(persona);
        personasParcelas[persona] = make_tuple(dia, parcela, itPorPos, itPorDia);
    }

    void cancelar_reserva(const string &persona){
        auto it = personasParcelas.find(persona);
        if (it == personasParcelas.end()){
            throw domain_error("No es titular de ninguna reserva");
        }
        auto [dia, parcela, itPos, itDia] = it->second;
        if (parcelas[dia][parcela].empty() || parcelas[dia][parcela].front() != persona){
            throw domain_error("No es titular de ninguna reserva");
        }
        parcelas[dia][parcela].pop_front();
        itPos->second.pop_front();
        itDia->second.pop_front();
    }

    string quien_reserva(int parcela, int dia) const {
        auto it = parcelas.find(dia);
        if (it == parcelas.end()){
            throw domain_error("Parcela no reservada");
        }
        auto itPar = it->second.find(parcela);
        if (itPar == it->second.end()){
            throw domain_error("Parcela no reservada");
        }
        if (itPar->second.empty()){
            throw domain_error("Parcela no reservada");
        }
        return itPar->second.front();
    }

    // O(1)
    bool puede_extender_reserva(const string &persona, int n) const {
        auto it = personasParcelas.find(persona);
        if (it == personasParcelas.end()){
            throw domain_error("No es titular de ninguna reserva");
        }
        auto [dia, parcela, itPos, itDia] = it->second;
        if (itPos->second.empty() || itPos->second.front() != persona){
            throw domain_error("No es titular de ninguna reserva");
        }
        auto itBusca = itPos;
        itBusca++;
        auto itParcela = parcelas_porPos.find(parcela);
        if (itBusca == itParcela->second.end()){
            return true;
        }
        return itBusca->first > itPos->first + n;
    }

    int menor_distancia_vecinos(const string &persona) const {
        auto it = personasParcelas.find(persona);
        if (it == personasParcelas.end()){
            throw domain_error("No es titular de ninguna reserva");
        }
        auto [dia, parcela, itPos, itDia] = it->second;
        if (itDia->second.empty() || itDia->second.front() != persona){
            throw domain_error("No es titular de ninguna reserva");
        }
        auto itParcela = parcelas_porDia.find(dia);
        auto itBuscaDelante = itDia;
        auto itBuscaDetras = itDia;
        bool hayDet = itDia != itParcela->second.begin();
        if (hayDet){
            itBuscaDetras--;
        }
        itBuscaDelante++;
        
        bool hayDel = !(itBuscaDelante == itParcela->second.end());
        //bool hayDet = !(itBuscaDetras == itParcela->second.begin());
        if (!hayDel && !hayDet){
            return -1;
        }
        int res;
        if (hayDel && hayDet){
            res = min(abs(itBuscaDelante->first - itDia->first), abs(itBuscaDetras->first - itDia->first));
            // cout << "PRUEBA "<< itBuscaDelante->first << " " << itBuscaDetras->first << " " << itDia->first << endl;
        }
        else if (hayDel){
            res = itBuscaDelante->first - itDia->first;
        }
        else {
            res = itBuscaDetras->first - itDia->first;
        }
        res = abs(res);
        res--;
        return res;
    }
};