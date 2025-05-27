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
 
 #include "Ferrovistan.h"
 
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

    Ferrovistan clase;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "nueva_linea") {
                string nombre;
                cin >> nombre;
                clase.linea_nueva(nombre);
            }
            else if (instruccion == "nueva_estacion") {
                string linea, nombre;
                int posicion;
                cin >> linea >> nombre >> posicion;
                clase.nueva_estacion(linea, nombre, posicion);
            }
            else if (instruccion == "eliminar_estacion") {
                string estacion;
                cin >> estacion;
                clase.eliminar_estacion(estacion);
            }
            else if (instruccion == "lineas_de") {
                string estacion;
                cin >> estacion;
                auto v = clase.lineas_de(estacion);
                cout << "Lineas de " << estacion << ":";
                for (const string& l : v) cout << " " << l;
                cout << endl;
            }
            else if (instruccion == "proxima_estacion") {
                string linea, estacion;
                cin >> linea >> estacion;
                string prox = clase.proxima_estacion(linea, estacion);
                cout << prox << endl;
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
 