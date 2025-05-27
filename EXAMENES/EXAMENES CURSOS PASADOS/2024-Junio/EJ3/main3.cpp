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
 
 #include "Camping.h"
 
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

    Camping camping;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "nueva_reserva") {
                string persona;
                int parcela, dia;
                cin >> persona >> parcela >> dia;
                camping.nueva_reserva(persona, parcela, dia);
                cout << "OK" << endl;
            }
            else if (instruccion == "cancelar_reserva") {
                string persona;
                cin >> persona;
                camping.cancelar_reserva(persona);
                cout << "OK" << endl;
            }
            else if (instruccion == "quien_reserva") {
                int parcela, dia;
                cin >> parcela >> dia;
                string titular = camping.quien_reserva(parcela, dia);
                cout << "(" << parcela << ", " << dia << ") reservada por " << titular << endl;
            }
            else if (instruccion == "puede_extender_reserva") {
                string persona;
                int n;
                cin >> persona >> n;
                bool puede = camping.puede_extender_reserva(persona, n);
                cout << persona << (puede ? " puede" : " no puede") << " extender la reserva " << n << " dias" << endl;
            }
            else if (instruccion == "menor_distancia_vecinos") {
                string persona;
                cin >> persona;
                int dist = camping.menor_distancia_vecinos(persona);
                if (dist == -1)
                    cout << "INFINITO" << endl;
                else
                    cout << dist << endl;
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
 