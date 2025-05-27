
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

tuple<int, int, int, int, bool, bool, bool> esABBP(BinTree<int> const& arbol){
    if (arbol.empty()){
      return {0, 0, 0, 0, true, false, false};
    }
    else {
      auto [maxParIz, minParIz, maxImpIz, minImpIz, abbpIz, parIz, impIz] = esABBP(arbol.left());
      auto [maxParDr, minParDr, maxImpDr, minImpDr, abbpDr, parDr, impDr] = esABBP(arbol.right());
      int raiz = arbol.root();
      bool dev = abbpIz && abbpDr;
      bool hayPar = parIz || parDr;
      bool hayImp = impIz || impDr;
      int mxP, miP, mxI, miI;
      if (raiz % 2 == 0){
         mxP = raiz;
         miP = raiz;
         if (parIz){
            if (minParIz <= raiz) {
               dev = false;
            }
            mxP = max(mxP, maxParIz);
            miP = min(miP, minParIz);
         }
         if (parDr){
            if (maxParDr >= raiz){
               dev = false;
            }
            mxP = max(mxP, maxParDr);
            miP = min(miP, minParDr);
         }
         if (impIz && impDr){
            mxI = max(maxImpIz, maxImpDr);
            miI = min(minImpIz, minImpDr);
         }
         else {
            if (impIz){
               mxI = maxImpIz;
               miI = minImpIz;
            }
            if (impDr){
               mxI = maxImpDr;
               miI = minImpDr;
            }
         }  
         hayPar = true;
      }
      else {
         mxI = raiz;
         miI = raiz;
         if (impIz){
            if (maxImpIz >= raiz) {
               dev = false;
            }
            mxI = max(mxI, maxImpIz);
            miI = min(miI, minImpIz);
         }
         if (impDr){
            if (minImpDr <= raiz){
               dev = false;
            }
            mxI = max(mxI, maxImpDr);
            miI = min(miI, minImpDr);
         }
         if (parIz && parDr){
            mxP = max(maxParIz, maxParDr);
            miP = min(minParIz, minParDr);
         }
         else {
            if (parIz){
               mxP = maxParIz;
               miP = minParIz;
            }
            if (parDr){
               mxP = maxParDr;
               miP = minParDr;
            }
         }  
         hayImp = true;
      }
      return {mxP, miP, mxI, miI, dev, hayPar, hayImp};

    }
}

void resuelveCaso()
{

   // leer los datos de la entrada

   BinTree<int> arbol = read_tree<int>(cin);

   // resolver el caso posiblemente llamando a otras funciones
   auto [a,b,c,d,e,f, g] = esABBP(arbol);

   // escribir la solución

   if (e){
      cout << "SI" << endl;
   }
   else {
      cout << "NO" << endl;
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
