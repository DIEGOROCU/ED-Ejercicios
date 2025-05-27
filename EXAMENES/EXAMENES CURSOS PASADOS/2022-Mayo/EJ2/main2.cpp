
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

tuple<int,int, int, bool> intermedios(BinTree<int> const& arbol){
    if (arbol.empty()){
        return {0,0,0, false};
    }
    else {
        auto [sumIzI, sumIzD, intIz, hijoIz] = intermedios(arbol.left());
        auto [sumDrI, sumDrD, intDr, hijoDr] = intermedios(arbol.right());
        int r = arbol.root();
        int i, d;
        bool hijo = false;
        if (arbol.left().empty()){
            i = 0;
        }
        else {
            i = arbol.left().root();
            hijo = true;
        }
        if (arbol.right().empty()){
            d = 0;
        }
        else {
            d = arbol.right().root();
            hijo = true;
        }
        
        int inter = 0;
        if (r != 0){
            if (i == abs(sumIzI - sumIzD) % r) inter += hijoIz;
            if (d == abs(sumDrI - sumDrD) % r) inter += hijoDr;
        }
        else {
            inter = (!arbol.left().empty()) + (!arbol.right().empty());
        }
        
        return {sumIzI + sumIzD + i, sumDrI + sumDrD + d, intIz + intDr + inter, true};
    }
}

void resuelveCaso()
{

   // leer los datos de la entrada
   BinTree<int> arbol = read_tree<int>(cin);

   // resolver el caso posiblemente llamando a otras funciones

   auto[a, b, i, c] = intermedios(arbol);

   // escribir la solución
   cout << i << endl;
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
