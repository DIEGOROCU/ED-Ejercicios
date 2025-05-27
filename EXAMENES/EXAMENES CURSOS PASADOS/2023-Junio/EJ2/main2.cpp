
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

pair<int,int> fantasia_final(BinTree<int> const& arbol){
    if (arbol.empty()){
        return {0,1};
    }
    else {
        auto [oroIz, vidaIz] = fantasia_final(arbol.left());
        auto [oroDr, vidaDr] = fantasia_final(arbol.right());
        int oroDev, vidaDev;
        if (oroIz > oroDr){
            oroDev = oroIz + max(arbol.root(), 0);
            vidaDev = vidaIz - min(arbol.root(), 0) - (arbol.root() == 0);
        }
        else if (oroIz < oroDr){
            oroDev = oroDr + max(arbol.root(), 0);
            vidaDev = vidaDr - min(arbol.root(), 0) - (arbol.root() == 0);
        }
        else {
            oroDev = oroIz + max(arbol.root(), 0);
            vidaDev = min(vidaIz, vidaDr) - min(arbol.root(), 0) - (arbol.root() == 0);
        }
        return {oroDev, max(1, vidaDev)};
    }
}

void resuelveCaso()
{

   // leer los datos de la entrada
   BinTree<int> arbol = read_tree<int>(cin);

   // resolver el caso posiblemente llamando a otras funciones
   auto[oro, vida] = fantasia_final(arbol);

   // escribir la solución

   cout << oro << " " << vida << endl;
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

   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
