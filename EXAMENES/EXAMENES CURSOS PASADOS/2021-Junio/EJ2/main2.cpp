
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

tuple<int, int, int, bool> cuadradoMayorProf(BinTree<int> const& arbol, int prof) {
   if (arbol.empty()){
      return {0, -1, 0, false};
   }
   else {
      auto [sumI, profMinI, minI, hayMinI] = cuadradoMayorProf(arbol.left(), prof + 1);
      auto [sumD, profMinD, minD, hayMinD] = cuadradoMayorProf(arbol.right(), prof + 1);
      int sum, profMin, mini, hayMin;
      int r = arbol.root();
      sum = sumI + sumD + r;
      if (hayMinI && hayMinD){
         profMin = min(profMinI, profMinD);
         if (profMinI >= profMinD){
            mini = minI;
         }
         else {
            mini = minD;
         }
         hayMin = true;
      }
      else if (hayMinI){
         profMin = profMinI;
         mini = minI;
         hayMin = true;
      }
      else if (hayMinD){
         profMin = profMinD;
         mini = minD;
         hayMin = true;
      }
      else {
         if (r == sumI + sumD){
            hayMin = true;
            mini = r;
            profMin = prof;
         }
         else {
            hayMin = false;
            mini = 0;
            profMin = 0;
         }
      }
      return {sum, profMin, mini, hayMin};
   }
}

void resuelveCaso()
{

   // leer los datos de la entrada
   BinTree<int> arbol = read_tree<int>(cin);

   // resolver el caso posiblemente llamando a otras funciones

   auto [a,b,c,d] = cuadradoMayorProf(arbol, 0);

   // escribir la solución
   if (d){
      cout << c << endl;
   }
   else {
      cout << -1 << endl;
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
