
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

 bool esPrimo(int n) {
    if (n == 0 || n == 1) return false;
    for (int i = 2; i <= sqrt(n); ++i)
       if (n % i == 0) return false;
    return true;
 }

 tuple<int, int, bool> resolver(BinTree<int> const& arbol, int alturaActual){
    if (arbol.empty() || esPrimo(arbol.root())){
         return {0, 0, false};
      }
      else {
         auto [numIz, alturaNumIz, multiplo7Iz] = resolver(arbol.left(), alturaActual + 1);
         auto [numDer, alturaNumDer, multiplo7Der] = resolver(arbol.right(), alturaActual + 1);
         if (arbol.root() % 7 == 0) return {arbol.root(), alturaActual, true};
         else if (multiplo7Iz && multiplo7Der) {
            if (alturaNumIz < alturaNumDer) return {numIz, alturaNumIz, true};
            else if (alturaNumIz > alturaNumDer) return {numDer, alturaNumDer, true};
            else return {numIz, alturaNumIz, true};
         }
         else if (multiplo7Iz) return {numIz, alturaNumIz, true};
         else if (multiplo7Der) return {numDer, alturaNumDer, true};
         else return {0, 0, false};
    }

 }


 
 void resuelveCaso() {
    
    // leer los datos de la entrada

      BinTree<int> arbol = read_tree<int>(cin);
      auto [num, altura, multiplo7] = resolver(arbol, 1);
      if (multiplo7) cout << num << " " << altura << '\n';
      else cout << "NO HAY\n";
    
    // resolver el caso posiblemente llamando a otras funciones
    
    // escribir la solución
 }
 
 //@ </answer>
 //  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
 
 int main() {
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
 