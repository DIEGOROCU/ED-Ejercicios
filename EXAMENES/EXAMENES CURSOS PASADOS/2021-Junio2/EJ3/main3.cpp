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
 
 #include "Granja.h"
 
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
    Granja clase;

    while (instruccion != "FIN"){
        try {
            if (instruccion == "alta") {
                string id;
                int n;
                cin >> id >> n;
                clase.alta(id, n);
            }
            else if (instruccion == "datos") {
                string id, plaga;
                int n;
                cin >> id >> plaga >> n;
                clase.datos(id, plaga, n);
            }
            else if (instruccion == "fumigar") {
                // Ahora devuelve una lista
                vector<pair<string, int>> res = clase.fumigar();
                for (const auto& par : res) {
                    cout << "Fumigar la plaga " << par.second << " del sector " << par.first << endl;
                }
            }
            else if (instruccion == "plagas") {
                string id;
                cin >> id;
                list<pair<string, int>> plagas = clase.plagas(id);
                cout << "Plagas del sector " << id << " :";
                for (const auto& par : plagas) {
                    cout << " " << par.first << " " << par.second;
                }
                cout << endl;
            }
        }
        catch (domain_error& e) {
            cout << "ERROR: " << e.what() << endl;
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
 