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

#include "ListLinkedSingle.h"

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

      ListLinkedSingle lista;
      for (int i = 0; i < n; i++){
        int aux;
        cin >> aux;
        lista.push_back(aux);
      }

      // escribir la solución

      int a = lista.burb();
      lista.print();
      cout << endl << a << endl;

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
