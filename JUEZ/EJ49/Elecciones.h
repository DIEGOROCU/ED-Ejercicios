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

class Elecciones {
    private:

    struct tEstado {
        string nombre;
        int compromisarios;
        map<string, int> partidos;
    };
    map<string, tEstado> estados;

    public:

    void nuevo_estado(const string &nombre, int num_compromisarios) {
        auto it = estados.find(nombre);
        if (it == estados.end()) {
            estados[nombre] = tEstado{nombre, num_compromisarios, {}};
        } else {
            throw domain_error("Estado ya existente");
        }
    }

    void sumar_votos(const string &estado, const string &partido, int num_votos) {
        auto it = estados.find(estado);
        if (it != estados.end()) {
            auto &estado_info = it->second;
            estado_info.partidos[partido] += num_votos;
        } else {
            throw domain_error("Estado no encontrado");
        }
    }

    string ganador_en(const string &estado) const {
        auto it = estados.find(estado);
        if (it != estados.end()) {
            const auto &estado_info = it->second;
            int max_votos = 0;
            string ganador;
            for (const auto &p : estado_info.partidos) {
                if (p.second > max_votos) {
                    max_votos = p.second;
                    ganador = p.first;
                }
            }
            return ganador;
        } else {
            throw domain_error("Estado no encontrado");
        }
    }

    vector<pair<string,int>> resultados() const {
        vector<pair<string,int>> resultados;
        for (const auto &estado : estados) {
            string ganador = ganador_en(estado.first);
            int compromisarios = estado.second.compromisarios;
            auto it = resultados.begin();
            while (it != resultados.end() && it->first < ganador) {
                ++it;
            }
            if (it != resultados.end() && it->first == ganador) {
                it->second += compromisarios;
            } else {
                resultados.insert(it, make_pair(ganador, compromisarios));
            }
        }
        return resultados;
    }

};