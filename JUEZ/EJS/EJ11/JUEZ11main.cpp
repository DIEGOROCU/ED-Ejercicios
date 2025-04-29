
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

 #include "ListLinkedDouble.h"
 
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
 
 void resuelveCaso() {
    
    // leer los datos de la entrada
    int tam1, tam2;
    ListLinkedDouble lista1, lista2;

    cin >> tam1;
    for (int i = 0; i < tam1; i++) {
        int elem;
        cin >> elem;
        lista1.push_back(elem);
    }
    cin >> tam2;
    for (int i = 0; i < tam2; i++) {
        int elem;
        cin >> elem;
        lista2.push_back(elem);
    }
    
    // resolver el caso posiblemente llamando a otras funciones

    lista1.zip(lista2);
    
    // escribir la solución

    cout << lista1 << endl;

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
 