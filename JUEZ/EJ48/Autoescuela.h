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

class Autoescuela {
    private:
        struct tAlummno{
            string profesor;
            int puntos = 0;
        };
        map<string, set<string>> profesores;
        map<string, tAlummno> alumnos; // nombre, (profesor, puntos)
    public:

    Autoescuela() : profesores(), alumnos() {} // Constructor por defecto

    void alta(string const _profesor, string const _alumno) {
        auto it = profesores.find(_profesor);
        if (it == profesores.end()) {
            profesores[_profesor] = set<string>();
        }
        profesores[_profesor].insert(_alumno);
        alumnos[_alumno].profesor = _profesor;
    }

    bool es_alumno(string const _alumno, string const _profesor) {
        auto it = alumnos.find(_alumno);
        if (it != alumnos.end()) {
            return it->second.profesor == _profesor;
        } else {
            return false;
        }
    }

    int puntuacion(string const _alumno) {
        auto it = alumnos.find(_alumno);
        if (it != alumnos.end()) {
            return it->second.puntos;
        } else {
            throw domain_error("El alumno " + _alumno + " no esta matriculado");
        }
    }

    void actualizar(string const _alumno, int _puntos) {
        auto it = alumnos.find(_alumno);
        if (it != alumnos.end()) {
            it->second.puntos += _puntos;
        } else {
            throw domain_error("El alumno " + _alumno + " no esta matriculado");
        }
    }

    vector<string> examen(string const _profesor, int const _puntos) {
        vector<string> alumnos_examen;
        auto it = profesores.find(_profesor);
        if (it != profesores.end()) {
            for (const auto& alumno : it->second) {
                if (alumnos[alumno].puntos >= _puntos) {
                    alumnos_examen.push_back(alumno);
                }
            }
        }
        sort(alumnos_examen.begin(), alumnos_examen.end());
        return alumnos_examen;
    }

    void aprobar(string const _alumno) {
        auto it = alumnos.find(_alumno);
        if (it != alumnos.end()) {
            it->second.puntos = 0;
            profesores[it->second.profesor].erase(_alumno);
            alumnos.erase(it);
        } else {
            throw domain_error("El alumno " + _alumno + " no esta matriculado");
        }
    }

};