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

int comprobar_whitesmiths(const list<pair<int, char>> &programa)
{
    stack<pair<int, char>> pila;
    auto it = programa.begin();
    if (it == programa.end())
        return -1;
    pila.push(make_pair(it->first, it->second));
    if (pila.top().first != 0) return 0;
    int i = 0;
    while (it != programa.end())
    {
        if (it->second == '{')
        {
            if (it->first <= pila.top().first)
            {
                return i;
            }
            pila.push(make_pair(it->first, it->second));
        }
        else if (it->second == '}')
        {
            if (pila.top().second != '{')
            {
                return i;
            }
            if (pila.top().first != it->first)
            {
                return i;
            }
            pila.pop();
        }
        else
        {
            if (it->first != pila.top().first)
            {
                return i;
            }
        }
        it++;
        i++;
    }
    return -1;
}

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

        // escribir la solución

        cin.ignore(10, '\n');

        list<pair<int, char>> lineas;

        for (int i = 0; i < n; i++)
        {
            // Para cada línea, la leemos de la entrada
            string l;
            getline(cin, l);

            // Contamos los espacios que hay antes del primer carácter no blanco
            int indent = 0;
            while (indent < l.size() && l[indent] == ' ')
            {
                indent++;
            }

            // Insertamos el par correspondiente en `lineas`
            lineas.push_back({indent, l[indent]});
        }

        // Llamamos a la función pedida
        int result = comprobar_whitesmiths(lineas);

        // Imprimimos el resultado
        if (result == -1)
        {
            cout << "CORRECTO\n";
        }
        else
        {
            cout << result + 1 << "\n";
        }

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
