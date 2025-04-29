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

#include <deque>

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

deque<int> mergeSort(deque<int> &q) {
    if (q.size() <= 1) return q;
    deque<int> left, right;
    int i = 0;
    // Leemos las dos mitades
    while (i < q.size() / 2) {
        left.push_back(q.front());
        q.pop_front();
        i++;
    }
    while (!q.empty()) {
        right.push_back(q.front());
        q.pop_front();
    }
    // Ordenamos las dos mitades
    left = mergeSort(left);
    right = mergeSort(right);
    deque<int> res;
    // Mezclamos las dos mitades
    while (!left.empty() && !right.empty()) {
        if (left.front() < right.front()) {
            res.push_back(left.front());
            left.pop_front();
        }
        else {
            res.push_back(right.front());
            right.pop_front();
        }
    }
    // Añadimos el resto de elementos
    while (!left.empty()) {
        res.push_back(left.front());
        left.pop_front();
    }
    while (!right.empty()) {
        res.push_back(right.front());
        right.pop_front();
    }
    return res;
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

        deque<int> q, res;
        for (int i = 0; i < n; i++) {
            int aux;
            cin >> aux;
            q.push_back(aux);
        }

        res = mergeSort(q);

        // escribir la solución
        while (!res.empty()) {
            cout << res.front() << " ";
            res.pop_front();
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
