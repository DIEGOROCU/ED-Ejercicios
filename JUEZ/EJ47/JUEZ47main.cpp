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

#include "CarnetPuntos.h"

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
    CarnetPuntos carnet;

    while (instruccion != "FIN"){
        try {
            if (instruccion == "nuevo"){
                string dni;
                cin >> dni;
                carnet.nuevo(dni);
            }
            else if (instruccion == "quitar"){
                string dni;
                int puntos;
                cin >> dni >> puntos;
                carnet.quitar(dni, puntos);
            }
            else if (instruccion == "consultar"){
                string dni;
                cin >> dni;
                int dev = carnet.consultar(dni);
                cout << "Puntos de " << dni << ": " << dev << endl;
            }
            else if (instruccion == "cuantos_con_puntos"){
                int puntos;
                cin >> puntos;
                int dev = carnet.cuantos_con_puntos(puntos);
                cout << "Con " << puntos << " puntos hay " << dev << endl;
            }
        }
        catch (domain_error& e) {
            cout << "ERROR: " << e.what() << endl;
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
