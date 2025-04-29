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
        map<string, vector<bool>> mapa;

        cin.ignore();

        for (int i = 0; i < n; ++i)
        {
            string frase;
            getline(cin, frase);
            char c;
            string palabra = "";
            for (int j = 0; j < frase.size(); ++j)
            {
                c = frase[j];
                if (isalpha(c))
                {
                    palabra += tolower(c);
                }
                else if (palabra.size() <= 2){
                    palabra = "";
                }
                else
                {
                    // Si la palabra no está en el mapa, inicializamos su vector con tamaño n y valores false
                    if (mapa.find(palabra) == mapa.end())
                    {
                        mapa[palabra] = vector<bool>(n, false);
                    }
                    // Marcamos el índice i como true
                    mapa[palabra][i] = true;
                    palabra = "";
                }
            }
            // Comprobamos la última palabra si no termina en un espacio
            if (palabra.size() > 2)
            {
                if (mapa.find(palabra) == mapa.end())
                {
                    mapa[palabra] = vector<bool>(n, false);
                }
                mapa[palabra][i] = true;
            }
        }

        // escribir la solución

        for (auto it = mapa.begin(); it != mapa.end(); ++it)
        {
            string palabra = it->first;
            vector<bool> v = it->second;
            cout << palabra << " ";
            for (int i = 0; i < v.size(); ++i)
            {
                if (v[i])
                {
                    cout << i + 1 << " ";
                }
            }
            cout << endl;
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
