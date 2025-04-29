
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
  
La idea de la solucion es ir recorriendo el arbol, recorriendo siempre las ramas de la izquierda primero y luego las de la derecha.
Para ello, utilizamos una funcion recursiva que recibe el arbol, la altura actual y un vector donde guardaremos los valores de los nodos que se encuentran en la primera posicion de cada altura.
Si hemos llegado a una nueva altura (es decir, que la el vector este vacio (-1) en esa posicion) guardamos el valor del nodo en esa posicion.
El coste de la solucion es O(n), ya que recorremos todos los nodos del arbol una vez, realizando operaciones de coste constante en cada uno de ellos en cantidades tambien constantes.
  @ </answer> */
 
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

 void resuelve(BinTree<int> const& arbol, int alturaActual, vector<int> & sol) {

    // Si hemos llegado a un nodo vacio, no hacemos nada
    if (arbol.empty()) return;
    else {
        // Si no, seguimos recorriendo el arbol
        resuelve(arbol.left(), alturaActual + 1, sol);
        resuelve(arbol.right(), alturaActual + 1, sol);
        // Si hemos llegado a una altura demasiado profunda, redimensionamos el vector
        if (sol.size() <= alturaActual) sol.resize(alturaActual + 1, -1);
        // Si es el primer numero que encontramos en esa altura, lo guardamos
        if (sol[alturaActual] == -1) sol[alturaActual] = arbol.root();
    }
 }
 
 void resuelveCaso() {
    
    // leer los datos de la entrada
    BinTree<int> arbol = read_tree<int>(cin);
    vector<int> sol;
    
    // resolver el caso posiblemente llamando a otras funciones
    resuelve(arbol, 0, sol);
    
    // escribir la solución
    for (int i = 0; i < sol.size(); ++i) {
        cout << sol[i] << " ";
    }
    cout << endl;
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
 