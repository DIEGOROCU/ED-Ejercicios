/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (ED-DGxx) de los autores de la solución (sustituye esta línea por esos datos; si sois dos, uno en cada línea).
 *
 *@ </authors> */

/*@ <answer>

  Sustituye este párrafo por una explicación de tu solución y una justificación del coste.

 *@ </answer> */

#include <iostream>
#include <fstream>

#include <map>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// Implementa a continuación la función que resuelve un caso de
// prueba. Puedes utilizar otras funciones auxiliares, pon su
// implementación debajo de la etiqueta <answer>.
//@ <answer>

struct tDeporte
{
    string nombre;
    int cantidad = 0;
    tDeporte(string nombre) : nombre(nombre) {}
};

struct tAlumno
{
    string nombre;
    int cantidad = 0;
    set<tDeporte*> deportes;
    tAlumno(string nombre) : nombre(nombre) {}
};

bool resuelveCaso()
{

    // completar
    string nombre;
    cin >> nombre;
    set<tAlumno*> alumnos;
    while (nombre != "_FIN_")
    {
        tDeporte* deporte = new tDeporte(nombre);
        cin >> nombre;
        while (!isupper(nombre[0]) && nombre != "_FIN_")
        {
            tAlumno* alumno = new tAlumno(nombre);
            if (alumnos.find(alumno) == alumnos.end())
            {
                alumnos.insert(alumno);
                alumno->deportes.insert(deporte);
                deporte->cantidad++;
            }
            else
            {
                auto it = alumnos.find(alumno);
                if (it != alumnos.end())
                {
                    (*it)->deportes.insert(deporte);
                    for (auto d : (*it)->deportes)
                    {
                        d->cantidad--;
                    }
                }
                (*it)->deportes.insert(deporte);
            }
            cin >> nombre;
        }        
    }

    // Recorramos todos los alumnos para obtener un vector de deportes ordenados, primero según la cantidad de alumnos que lo practican y luego por el nombre del deporte
    vector<tDeporte*> deportes;
    for (auto it : alumnos)
    {
        for (auto d : it->deportes)
        {
            // Realizamos una búsqueda binaria para ver si el deporte ya está en el vector
            auto it = lower_bound(deportes.begin(), deportes.end(), d, [](tDeporte* d1, tDeporte* d2) {
                return d1->nombre < d2->nombre;
            });
            if (it == deportes.end() || (*it)->nombre != d->nombre)
            {
                deportes.insert(it, d);
            }
        }
    }
    sort(deportes.begin(), deportes.end(), [](tDeporte* d1, tDeporte* d2) {
        if (d1->cantidad == d2->cantidad)
            return d1->nombre < d2->nombre;
        return d1->cantidad > d2->cantidad;
    });

    // Imprimimos los deportes
    for (auto d : deportes)
    {
        cout << d->nombre << " " << d->cantidad - 1 << endl;
    }

    cout << "---" << endl;

    return true;
}

//@ </answer>
// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

int main()
{
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    // Descomentar si se trabaja en Visual Studio
    // system("PAUSE");
#endif
    return 0;
}
