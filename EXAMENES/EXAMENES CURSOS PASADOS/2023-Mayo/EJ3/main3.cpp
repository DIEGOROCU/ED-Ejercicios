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
 
 #include "TiendaRopa.h"
 
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
 
 bool resuelveCaso()
 {
     string instruccion;
     cin >> instruccion;
     if (!cin) return false;

     TiendaRopa tienda;

     while (instruccion != "FIN") {
         try {
             if (instruccion == "inserta_izquierda") {
                 string color; cin >> color;
                 tienda.insertar_izquierda(color);
             }
             else if (instruccion == "inserta_derecha") {
                 string color; cin >> color;
                 tienda.insertar_derecha(color);
             }
             else if (instruccion == "compra_izquierda") {
                 tienda.compra_izquierda();
             }
             else if (instruccion == "compra_derecha") {
                 tienda.compra_derecha();
             }
             else if (instruccion == "pregunta") {
                 cout << tienda.pregunta() << endl;
             }
         }
         catch (domain_error& e) {
             cout << "ERROR: " << e.what() << endl;
         }
         cin >> instruccion;
     }

     cout << "---" << endl;
     return true;
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
 
     while (resuelveCaso())
         ;
 
     // para dejar todo como estaba al principio
 #ifndef DOMJUDGE
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
 #endif
     return 0;
 }
