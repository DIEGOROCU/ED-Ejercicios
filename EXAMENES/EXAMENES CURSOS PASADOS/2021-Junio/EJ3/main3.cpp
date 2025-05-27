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
 
 #include "Hospital.h"
 
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

    Hospital hospital;

    while (instruccion != "FIN") {
        try {
            if (instruccion == "altaMedico") {
                string medico;
                cin >> medico;
                hospital.altaMedico(medico);
            }
            else if (instruccion == "pedirConsulta") {
                string paciente, medico;
                cin >> paciente >> medico;
                hospital.pedirConsulta(paciente, medico);
            }
            else if (instruccion == "siguientePaciente") {
                string medico;
                cin >> medico;
                string paciente = hospital.siguientePaciente(medico);
                cout << paciente << endl;
            }
            else if (instruccion == "atenderConsulta") {
                string medico;
                cin >> medico;
                hospital.atenderConsulta(medico);
            }
            else if (instruccion == "abandonarConsulta") {
                string paciente;
                cin >> paciente;
                list<string> medicos = hospital.abandonarConsulta(paciente);
                medicos.sort(); // Orden alfabético
                cout << "Medicos abandonados:";
                for (const string& m : medicos) cout << " " << m;
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
 