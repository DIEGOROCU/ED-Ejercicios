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

class Granja
{
private:
    struct tParcela
    {
        int plantas = 0;
        // int infectadas = 0;
        unordered_map<string, map<string, pair<int, bool>>::iterator> iteradores;
        map<string, pair<int, bool>> plagas;
    };

    unordered_map<string, tParcela> parcelas;

    list<pair<string, int>> infectadas;

public:
    void alta(string id, int n)
    {
        tParcela &p = parcelas[id];
        p.plantas += n;
    }

    void datos(string id, string p, int n)
    {
        auto it = parcelas.find(id);
        if (it == parcelas.end())
        {
            throw domain_error("Sector no existente");
        }
        tParcela &par = it->second;
        if (n > par.plantas)
        {
            throw domain_error("Numero de plantas incorrecto");
        }
        auto itPlaga = par.iteradores.find(p);
        if (itPlaga == par.iteradores.end())
        {
            pair<int, bool> miPair = make_pair(n, n >= par.plantas / 4);
            auto [itInsertado,  boolInsertado] = par.plagas.insert(make_pair(p, miPair));
            par.iteradores[p] = itInsertado;
            if (n >= par.plantas / 4)
            {
                infectadas.push_back(make_pair(p, n));
            }
        }
        else {
            itPlaga->second->second.first = n;
            if (n >= par.plantas / 4 && itPlaga->second->second.second == false)
            {
                infectadas.push_back(make_pair(p, n));
                itPlaga->second->second.second = true;
            }
        }
    }

    vector<pair<string, int>> fumigar()
    {
        vector<pair<string, int>> dev(infectadas.begin(), infectadas.end());
        for (auto it : parcelas)
        {
            tParcela &p = it.second;
            for (auto& [plaga, itPlaga]: p.iteradores)
            {
                if (itPlaga->second.first >= p.plantas / 4)
                {
                    itPlaga->second.first = 0;
                    itPlaga->second.second = false;
                }
            }
        }
        infectadas.clear();
        return dev;
    }

    list<pair<string, int>> plagas(string id) {
        list<pair<string, int>> lista;
        auto it = parcelas.find(id);
        if (it == parcelas.end())
        {
            throw domain_error("Sector no existente");
        }
        for (auto iterador : it->second.plagas) {
            lista.push_back(make_pair(iterador.first, iterador.second.first));
        }
        return lista;
    }
};