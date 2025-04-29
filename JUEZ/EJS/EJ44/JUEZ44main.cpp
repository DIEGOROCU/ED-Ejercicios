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

struct tJugador{
    string nombre;
    int cantRes = 0;
    tJugador(string nombre): nombre(nombre){};
};

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
        unordered_map<int, unordered_set<tJugador*>> numeros;
        map<string, tJugador*> jugadores;
        // Leamos los jugadores y sus bingos
        for (int i = 0; i < n; ++i)
        {
            string nombre;
            cin >> nombre;
            int num;
            cin >> num;
            tJugador* jugador = new tJugador(nombre);
            while (num != 0)
            {
                numeros[num].insert(jugador);
                jugador->cantRes++;
                cin >> num;
            }
            jugadores[nombre] = jugador;
        }

        // escribir la solución

        bool bingo = false;
        int num;
        cin >> num;
        while (!bingo){
            if (numeros[num].size() > 0)
            {
                for (tJugador* j : numeros[num])
                {
                    if (j->cantRes == 1)
                    {
                        j->cantRes--;
                        bingo = true;
                    }
                    else {
                        j->cantRes--;
                    }
                }
            }
            if (!bingo)
            {
                cin >> num;
            }
        }

        for (const auto& [s, jugador] : jugadores)
        {
            if (jugadores[s]->cantRes == 0)
            {
                cout << jugadores[s]->nombre << " ";
            }
        }

        cout << endl;

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
