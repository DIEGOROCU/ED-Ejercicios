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
 
 #include "Subastas.h"
 
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

    Subastas clase;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "nuevo_participante") {
                string part;
                int saldo;
                cin >> part >> saldo;
                clase.nuevo_participante(part, saldo);
                cout << "OK" << endl;
            }
            else if (instruccion == "nueva_subasta") {
                string obj;
                int puja_min;
                cin >> obj >> puja_min;
                clase.nueva_subasta(obj, puja_min);
                cout << "OK" << endl;
            }
            else if (instruccion == "nueva_puja") {
                string part, obj;
                int cantidad;
                cin >> part >> obj >> cantidad;
                clase.nueva_puja(part, obj, cantidad);
                cout << "OK" << endl;
            }
            else if (instruccion == "abandonar_casa") {
                string part;
                cin >> part;
                clase.abandonar_casa(part);
                cout << "OK" << endl;
            }
            else if (instruccion == "cerrar_subasta") {
                string obj;
                cin >> obj;
                string ganador = clase.cerrar_subasta(obj);
                cout << obj << " ha sido ganado por: " << ganador << endl;
            }
            else if (instruccion == "subastas_ganadas") {
                string part;
                cin >> part;
                list<string> ganadas = clase.subastas_ganadas(part);
                cout << part << " ha ganado:";
                for (const string& obj : ganadas) cout << " " << obj;
                cout << endl;
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
 