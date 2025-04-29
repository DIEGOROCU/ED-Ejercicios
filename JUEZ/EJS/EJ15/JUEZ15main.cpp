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

#include "QueueLinkedList.h"

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

    int alumnos, salto;
    cin >> alumnos >> salto;

    if (alumnos == 0 && salto == 0)
        return false;

    else
    {
        // resolver el caso posiblemente llamando a otras funciones

        if (alumnos <= 1)
        {
            cout << alumnos << endl;
            return true;
        }

        QueueLinkedList<int> cola;

        // Rellenamos los alumnos en la cola
        for (int i = 1; i <= alumnos; i++) {
            cola.push(i);
        }

        int restantes = alumnos;
        while (restantes > 1) {
            // Saltamos los alumnos necesarios
            for (int i = 0; i < salto; i++) {
                cola.push(cola.front());
                cola.pop();
            }
            // Quitamos el alumno que se va
            cola.pop();
            restantes--;
        }

        // escribir la solución

        cout << cola.front() << endl;

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
