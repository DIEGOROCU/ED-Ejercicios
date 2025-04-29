
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

tuple<int, int, bool> resolver(const BinTree<int> &arbol)
{
   if (arbol.empty())
   {
      return {0, 1, true};
   }
   else
   {
      auto [alturaIz, multiIz, estableIz] = resolver(arbol.left());
      auto [alturaDr, multiDr, estableDr] = resolver(arbol.right());
      bool dev = true;
      if (alturaIz > 0 && multiIz == 1 && abs(alturaIz - 1 - alturaDr) > 1)
      {
         dev = false;
      }
      if (alturaDr > 0 && multiDr == 1 && abs(alturaDr - 1 - alturaIz) > 1)
      {
         dev = false;
      }
      int altura = max(alturaIz, alturaDr) + 1;
      int multi;
      if (alturaIz == alturaDr && alturaIz > 0)
      {
         multi = multiIz + multiDr;
      }
      else if (alturaIz > alturaDr)
      {
         multi = multiIz;
      }
      else
      {
         multi = multiDr;
      }
      dev = dev && estableIz && estableDr;
      return {altura, multi, dev};
   }
}

void resuelveCaso()
{

   // leer los datos de la entrada

   BinTree<int> arbol = read_tree<int>(std::cin);
   bool sol = std::get<2>(resolver(arbol));
   cout << (sol ? "SI" : "NO") << endl;

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
