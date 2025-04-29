/*@ <authors>
 *
 * Nombre, apellidos y usuario del juez (DGXX) de los autores de la solución.
 * Diego Rodriguez Cubeo DG30
 *
 *@ </authors> */

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

#include "Autoescuela.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

    // leer los datos de la entrada
    string instruccion;
    cin >> instruccion;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    Autoescuela Autoescuela;

    while (instruccion != "FIN")
    {
        try
        {
            if (instruccion == "alta")
            {
                string alumno, profesor;
                cin >> alumno >> profesor;
                Autoescuela.alta(profesor, alumno);
            }
            else if (instruccion == "es_alumno")
            {
                string alumno, profesor;
                cin >> alumno >> profesor;
                bool es_alumno = Autoescuela.es_alumno(alumno, profesor);
                if (es_alumno)
                {
                    cout << alumno << " es alumno de " << profesor << std::endl;
                }
                else
                {
                    cout << alumno << " no es alumno de " << profesor << endl;
                }
            }
            else if (instruccion == "examen"){
                string profesor;
                int puntos;
                cin >> profesor >> puntos;
                vector<string> alumnos_examen = Autoescuela.examen(profesor, puntos);
                cout << "Alumnos de " << profesor << " a examen:" << endl;
                for (const auto& alumno : alumnos_examen) {
                    cout << alumno << endl;
                }
            }
            else if (instruccion == "actualizar"){
                string alumno;
                int puntos;
                cin >> alumno >> puntos;
                Autoescuela.actualizar(alumno, puntos);
            }
            else if (instruccion == "puntuacion"){
                string alumno;
                cin >> alumno;
                int puntuacion = Autoescuela.puntuacion(alumno);
                cout << "Puntuacion de " << alumno << ": " << puntuacion << endl;
            }
            else if (instruccion == "aprobar"){
                string alumno;
                cin >> alumno;
                Autoescuela.aprobar(alumno);
            }
        }
        catch (domain_error &e)
        {
            cout << "ERROR" << endl;
            //cout << "ERROR: " << e.what() << endl;
        }
        cin >> instruccion;
    }

    // escribir la solución

    cout << "---" << endl;

    return true;
   
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main()
{
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    while (resuelveCaso())
        ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
