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
 
 #include "FantasiaFinal.h"
 
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

    FantasiaFinal clase;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "aparece_villano") {
                string v;
                int s, a;
                cin >> v >> s >> a;
                clase.aparece_villano(v, s, a);
            }
            else if (instruccion == "aparece_heroe") {
                string h;
                int s;
                cin >> h >> s;
                clase.aparece_heroe(h, s);
            }
            else if (instruccion == "aprende_ataque") {
                string h, a;
                int v;
                cin >> h >> a >> v;
                clase.aprende_ataque(h, a, v);
            }
            else if (instruccion == "mostrar_ataques") {
                string h;
                cin >> h;
                auto ataques = clase.mostrar_ataques(h);
                cout << "Ataques de " << h << endl;
                for (auto const& par : ataques) {
                    cout << par.first << " " << par.second << endl;
                }
            }
            else if (instruccion == "mostrar_turnos") {
                auto turnos = clase.mostrar_turnos();
                cout << "Turno:" << endl;
                for (auto const& par : turnos) {
                    cout << par.first << " " << par.second << endl;
                }
            }
            else if (instruccion == "villano_ataca") {
                string v, h;
                cin >> v >> h;
                bool eliminado = clase.villano_ataca(v, h);
                cout << v << " ataca a " << h << endl;
                if (eliminado) cout << h << " derrotado" << endl;
            }
            else if (instruccion == "heroe_ataca") {
                string h, a, v;
                cin >> h >> a >> v;
                bool eliminado = clase.heroe_ataca(h, a, v);
                cout << h << " ataca a " << v << endl;
                if (eliminado) cout << v << " derrotado" << endl;
            }
        }
        catch (invalid_argument& e) {
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
 