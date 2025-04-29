
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

 pair<int, int> resolver(BinTree<char> const& arbol) {
    if (arbol.empty()) return {0, 0};
    else if (arbol.left().empty() && arbol.right().empty()) return {1, 1};
    else {
       auto izq = resolver(arbol.left());
       auto der = resolver(arbol.right());
       return {min(izq.first, der.first) + 1, izq.second + der.second + 1};
    }
 }
 
 void resuelveCaso() {
    
    // leer los datos de la entrada

    BinTree<char> arbol = read_tree<char>(cin);
    
    // resolver el caso posiblemente llamando a otras funciones

    auto [altura, nodos] = resolver(arbol);
    
    // escribir la solución

    cout << nodos - altura << '\n';
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
 