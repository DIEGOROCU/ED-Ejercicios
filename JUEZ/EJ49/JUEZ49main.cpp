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
 
 #include "Elecciones.h"
 
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
 
     // leer los datos de la entrada
     string instruccion;
     cin >> instruccion;
 
     // fin de la entrada
     if (!cin)
     {
         return false;
     }
 
     // resolver el caso posiblemente llamando a otras funciones
     Elecciones clase;
 
     while (instruccion != "FIN"){
         try {
            if (instruccion == "nuevo_estado") {
                 string nombre;
                 int num_compromisarios;
                 cin >> nombre >> num_compromisarios;
                 clase.nuevo_estado(nombre, num_compromisarios);
             }
             else if (instruccion == "sumar_votos") {
                 string estado, partido;
                 int num_votos;
                 cin >> estado >> partido >> num_votos;
                 clase.sumar_votos(estado, partido, num_votos);
             }
             else if (instruccion == "ganador_en") {
                 string estado;
                 cin >> estado;
                 string ganador = clase.ganador_en(estado);
                 cout << "Ganador en " << estado << ": " << ganador << endl;
             }
             else if (instruccion == "resultados") {
                 auto res = clase.resultados();
                 for (auto& p : res) {
                     cout << p.first << " " << p.second << endl;
                 }
             }
             else {
                 cout << "ERROR: Instrucción no válida" << endl;
             }
         }
         catch (domain_error& e) {
             cout << e.what() << endl;
         }
         cin >> instruccion;
     }
 
     // escribir la solución
 
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
 