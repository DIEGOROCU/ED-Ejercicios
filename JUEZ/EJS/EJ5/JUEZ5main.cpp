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

 #include "teatro.h" 
 
 using namespace std;
 
 /*@ <answer>
   
  Escribe aquí un comentario general sobre la solución, explicando cómo
  se resuelve el problema y cuál es el coste de la solución, en función
  del tamaño del problema.
  Mediante busquedas binarias en un vector ordenado se resuelven las consultas de las butacas y las reservas pedidas
  Coste total en el caso peor con n reservas y m consultas:
  O(n * log n + n * n) + O(m * log n) = O(n^2 + m)
  Ya que se realizarian n busquedas binarias O(log n) para cada reserva, con una insercion O(n)
  Y m busquedas binarias O(log n) para cada consulta
  
  @ </answer> */
 
 
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>
 
 bool resuelveCaso() {
    
    // leer los datos de la entrada
 
    int reservas, consultas;
    cin >> reservas >> consultas;
    
    if (reservas == 0 && consultas == 0) return false;
 
    else {
    // resolver el caso posiblemente llamando a otras funciones

    Teatro t;
    for (int i = 0; i < reservas; i++) {
        int inicio, fin;
        cin >> inicio >> fin;
        string nombre;
        cin >> nombre;
        if (t.nueva_reserva(inicio, fin, nombre)) {
            cout << '.';
        }
        else {
            cout << 'X';
        }
    }
    cout << endl;
    for (int i = 0; i < consultas; i++) {
        int num_butaca;
        cin >> num_butaca;
        cout << t.nombre_reserva(num_butaca) << endl;
    }
     
    cout << "---" << endl;

    return true;
    }
    
 }
 
 //@ </answer>
 //  Lo que se escriba debajo de esta línea ya no forma parte de la solución.
 
 int main() {
    // ajustes para que cin extraiga directamente de un fichero
 #ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
 #endif
    
    while (resuelveCaso());
    
    // para dejar todo como estaba al principio
 #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
 #endif
    return 0;
 }
 