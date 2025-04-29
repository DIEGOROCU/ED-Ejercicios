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

BinTree<int> reconstruir(vector<int> &preOrden, vector<int> &inOrden, int preIzq, int preDer, int inIzq, int inDer) {
    if (preIzq >= preDer) return BinTree<int>();
    int raiz = preOrden[preIzq];
    int i = inIzq;
    while (inOrden[i] != raiz) ++i;
    BinTree<int> izq = reconstruir(preOrden, inOrden, preIzq + 1, preIzq + 1 + i - inIzq, inIzq, i);
    BinTree<int> der = reconstruir(preOrden, inOrden, preIzq + 1 + i - inIzq, preDer, i + 1, inDer);
    return BinTree<int>(izq, raiz, der);
}
 
 bool resuelveCaso() {
    
    // leer los datos de la entrada

    int tam;
    cin >> tam;
    
    // fin de la entrada
    if (!cin){
        return false;
    }
    
    // resolver el caso posiblemente llamando a otras funciones

    BinTree<int> arbol;
    vector<int> preOrden(tam);
    vector<int> inOrden(tam);
    for (int i = 0; i < tam; ++i) {
        cin >> preOrden[i];
    }
    for (int i = 0; i < tam; ++i) {
        cin >> inOrden[i];
    }
    arbol = reconstruir(preOrden, inOrden, 0, tam, 0, tam);
    
    // escribir la solución

    arbol.display(cout);
    cout << endl;
 
    return true;
 }
 
 //@ </answer>
 //  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
 
 int main() {
    // ajustes para que cin extraiga directamente de un fichero
 #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
 #endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
 #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
 #endif
    return 0;
 }
 