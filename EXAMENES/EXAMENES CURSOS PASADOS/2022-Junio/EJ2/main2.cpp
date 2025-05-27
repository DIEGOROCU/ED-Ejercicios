
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

#include"BinTree.h"

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

pair<BinTree<int>, int> reconstruir(const BinTree<int>& arbol){
    if (arbol.empty()){
        return {BinTree<int>(), 0};
    }
    else if (arbol.left().empty() && arbol.right().empty()){
        return {BinTree<int>(arbol.root()), arbol.root()};
    }
    else {
        auto [aI, sI] = reconstruir(arbol.left());
        auto [aD, sD] = reconstruir(arbol.right());
        int suma = sI + sD + arbol.root();
        return {BinTree<int>(aI, suma, aD), suma};
    }
}

void resuelveCaso()
{

   // leer los datos de la entrada
   BinTree<int> arbol = read_tree<int>(cin);
   auto [a, s] = reconstruir(arbol);
   a.display(cout);
   cout << endl;

   // resolver el caso posiblemente llamando a otras funciones

   // escribir la solución
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
