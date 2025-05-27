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

class Ferrovistan {
    private:

    struct tLinea{
        unordered_map<string, int> estaciones_nombres;
        map<int, string> estaciones_posicion;
    };

    struct tEstacion {
        list<string> lineas;
        list<pair<string, map<int, string>::iterator>> iteradores;
    };

    unordered_map<string, tLinea> lineas;
    unordered_map<string, tEstacion> estaciones;

    public:

    void linea_nueva(const string& nombre){
        auto it = lineas.find(nombre);
        if (it != lineas.end()){
            throw domain_error("Linea existente");
        }
        tLinea linea;
        lineas[nombre] = linea;
    }

    void nueva_estacion(const string &linea, const string &nombre, int posicion){
        auto itL = lineas.find(linea);
        if (itL == lineas.end()){
            throw domain_error("Linea no existente");
        }
        auto itE1 = itL->second.estaciones_nombres.find(nombre);
        if (itE1 != itL->second.estaciones_nombres.end()){
            throw domain_error("Estacion duplicada");
        }
        auto itE2 = itL->second.estaciones_posicion.find(posicion);
        if (itE2 != itL->second.estaciones_posicion.end()){
            throw domain_error("Posicion ocupada");
        }
        // Todo correcto

        auto itEstacion = estaciones.find(nombre);
        if (itEstacion == estaciones.end()){
            tEstacion anadir;
            anadir.lineas.push_back(linea);
            itL->second.estaciones_nombres[nombre] = posicion;
            auto itAnadir = itL->second.estaciones_posicion.insert({posicion, nombre});
            anadir.iteradores.push_back(make_pair(linea, itAnadir.first));
            estaciones[nombre] = anadir;
        }
        else {
            tEstacion& anadir = itEstacion->second;
            anadir.lineas.push_back(linea);
            itL->second.estaciones_nombres[nombre] = posicion;
            auto itAnadir = itL->second.estaciones_posicion.insert({posicion, nombre});
            anadir.iteradores.push_back(make_pair(linea, itAnadir.first));
        }
    }

    void eliminar_estacion(const string &estacion){
        auto itEstacion = estaciones.find(estacion);
        if (itEstacion == estaciones.end()){
            throw domain_error("Estacion no existente");
        }
        tEstacion& est = itEstacion->second;
        for (auto lineaInfo : est.iteradores){
            lineas[lineaInfo.first].estaciones_nombres.erase(estacion);
            lineas[lineaInfo.first].estaciones_posicion.erase(lineaInfo.second);
        }
        estaciones.erase(estacion);
    }

    vector<string> lineas_de(const string &estacion) const {
        auto itEstacion = estaciones.find(estacion);
        if (itEstacion == estaciones.end()){
            throw domain_error("Estacion no existente");
        }
        vector<string> dev(itEstacion->second.lineas.begin(), itEstacion->second.lineas.end());
        sort(dev.begin(), dev.end());
        return dev;
    }

    string proxima_estacion(const string &linea, const string &estacion) const {
        auto itL = lineas.find(linea);
        if (itL == lineas.end()){
            throw domain_error("Linea no existente");
        }
        auto itE = itL->second.estaciones_nombres.find(estacion);
        if (itE == itL->second.estaciones_nombres.end()){
            throw domain_error("Estacion no existente");
        }
        auto itDev = itL->second.estaciones_posicion.find(itE->second);
        itDev++;
        if (itDev == itL->second.estaciones_posicion.end()){
            return "Final de linea";
        }
        else {
            return itDev->second;
        }    
    }

};