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

class Restaurante {
    private:

    struct tMesa {
        unordered_map<string, list<pair<list<string>::iterator, list<pair<int, string>>::iterator>>> mapa_pedidos;
        list<string> pedidos;
    };

    unordered_map<int, tMesa> mesas;
    list<pair<int, string>> pedidos_restaurante;

    public:

    void nueva_mesa(int num){
        auto it = mesas.find(num);
        if (it != mesas.end()){
            throw domain_error("Mesa ocupada");
        }
        tMesa m;
        mesas[num] = m;
    }

    void nuevo_pedido(int mesa, const string &plato) {
        auto it = mesas.find(mesa);
        if (it == mesas.end()){
            throw domain_error("Mesa vacia");
        }
        tMesa* m = &(it->second);
        m->pedidos.push_back(plato);
        auto it1 = m->pedidos.end();
        it1--;
        pedidos_restaurante.push_back(make_pair(mesa, plato));
        auto it2 = pedidos_restaurante.end();
        it2--;
        m->mapa_pedidos[plato].push_back(make_pair(it1, it2));
    }

    void cancelar_pedido(int mesa, const string &plato) {
        auto it = mesas.find(mesa);
        if (it == mesas.end()){
            throw domain_error("Mesa vacia");
        }
        tMesa* m = &(it->second);
        auto itPlato = m->mapa_pedidos.find(plato);
        if (itPlato == m->mapa_pedidos.end()){
            throw domain_error("Producto no pedido por la mesa");
        }
        auto [itMesa, itLista] = itPlato->second.back();
        m->pedidos.erase(itMesa);
        pedidos_restaurante.erase(itLista);
        itPlato->second.pop_back();
    }

    pair<int, string> servir() {
        if (pedidos_restaurante.empty()){
            throw domain_error("No hay pedidos pendientes");
        }
        auto[mesa, plato] = pedidos_restaurante.front();
        auto it = mesas.find(mesa);
        tMesa* m = &(it->second);
        auto itPlato = m->mapa_pedidos.find(plato); 
        auto [itMesa, itLista] = itPlato->second.front();
        m->pedidos.erase(itMesa);
        pedidos_restaurante.erase(itLista); // Equivale a pop_front
        return make_pair(mesa, plato);
    }

    vector<string> que_falta(int mesa) const {
        auto it = mesas.find(mesa);
        if (it == mesas.end()){
            throw domain_error("Mesa vacia");
        }
        vector<string> dev(it->second.pedidos.begin(), it->second.pedidos.end());
        sort(dev.begin(), dev.end());
    }

};