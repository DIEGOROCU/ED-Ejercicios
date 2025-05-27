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
 
 #include "Musica.h"
 
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
     Musica miMusica;
 
     while (instruccion != "FIN"){
         try {
            if (instruccion == "addSong"){
                string can, au;
                int dur;
                cin >> can >> au >> dur;
                miMusica.addSong(can, au, dur);
            }
            else if (instruccion == "addToPlaylist") {
                string can;
                cin >> can;
                miMusica.addToPlay(can);
            }
            else if (instruccion == "play") {
                cout << miMusica.play() << endl;
            }
            else if (instruccion == "totalTime") {
                cout << miMusica.totalTime() << endl;
            }
            else if (instruccion == "deleteSong") {
                string can;
                cin >> can;
                miMusica.deleteSong(can);
            }
            else if (instruccion == "recent") {
                int n;
                cin >> n;
                auto recientes = miMusica.recent(n);
                cout << "Las " << recientes.size() << " mas recientes";
                for (const auto& can : recientes) {
                    cout << " " << can;
                }
                cout << endl;
            }
            else if (instruccion == "current") {
                cout << "En curso: " << miMusica.current("") << endl;
            }
         }
         catch (domain_error& e) {
             cout << "ERROR " << e.what() << endl;
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
