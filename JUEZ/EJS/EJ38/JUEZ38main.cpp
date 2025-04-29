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

#include "SetTree.h"

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

    char tipo;
    cin >> tipo;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones

    int tam;
    cin >> tam;
    if (tipo == 'N')
    {
        SetTree<int> arbol;
        int aux;
        cin >> aux;
        while (aux != -1)
        {
            if (arbol.size() < tam)
            {
                arbol.insert(aux);
            }
            else {
                int mini = arbol.minimun();
                if (aux > mini && !arbol.contains(aux))
                {
                    arbol.erase_min();
                    arbol.insert(aux);
                }
            }
            cin >> aux;
        }
        arbol.display(cout);
        cout << '\n';
    }
    else
    {
        SetTree<string> arbol;
        string aux;
        cin >> aux;
        while (aux != "FIN")
        {
            if (arbol.size() < tam)
            {
                arbol.insert(aux);
            }
            else {
                string mini = arbol.minimun();
                if (aux > mini && !arbol.contains(aux))
                {
                    arbol.erase_min();
                    arbol.insert(aux);
                }
            }
            cin >> aux;
        }
        arbol.display(cout);
        cout << '\n';
    }

    // escribir la solución

    

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
