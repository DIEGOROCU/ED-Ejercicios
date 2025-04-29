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

    int n;
    cin >> n;

    if (n == 0)
        return false;

    else
    {
        // resolver el caso posiblemente llamando a otras funciones
        map<string, int> mapa;

        for (int i = 0; i < n; i++)
        {
            string nombre;
            cin.ignore();
            getline(cin, nombre);
            string aprobado;
            cin >> aprobado;
            if (aprobado == "CORRECTO")
            {
                mapa[nombre]++;
            }
            else
            {
                mapa[nombre]--;
            }
        }

        // escribir la solución
        for (auto it = mapa.begin(); it != mapa.end(); ++it)
        {
            if (it->second != 0)
            {
                cout << it->first << ", " << it->second << endl;
            }
        }

        cout << "---" << endl;

        return true;
    }
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
