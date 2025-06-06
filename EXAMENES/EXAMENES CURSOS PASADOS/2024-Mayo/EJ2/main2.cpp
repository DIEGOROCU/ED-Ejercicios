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

#include "BinTree.h"

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



pair<int, int> interes(const BinTree<int> &arbol){
    if (arbol.empty()){
        return {0, 0};
    }
    else {
        auto [maxCamIz, maxRutaIz] = interes(arbol.left());
        auto [maxCamDr, maxRutaDr] = interes(arbol.right());
        int maxCam = max(maxCamIz, maxCamDr) + arbol.root();
        int maxRuta = max(maxRutaIz, maxRutaDr);
        maxRuta = max(maxRuta, maxCamIz + maxCamDr + arbol.root());
        return {maxCam, maxRuta};
    }
}

int max_interes_ruta(const BinTree<int> &montanya){
    auto [a, b] = interes(montanya);
    return b;
}

bool resuelveCaso()
{

   // leer los datos de la entrada

   BinTree<int> arbol = read_tree<int>(cin);

   if (arbol.empty())
      return false;

   else
   {
      // resolver el caso posiblemente llamando a otras funciones

      // escribir la solución
      cout << max_interes_ruta(arbol) << endl;

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
