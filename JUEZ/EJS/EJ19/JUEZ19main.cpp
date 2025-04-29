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

 #include <deque>
 #include <queue>

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

 struct tNum {
     int numero;
     int pos;
 };

 bool operator<(tNum const& a, tNum const& b){
     return a.numero < b.numero;
 }
 
 bool resuelveCaso() {
    
    // leer los datos de la entrada

    int tam, longitud;
    cin >> tam >> longitud;
    
    // fin de la entrada
    if (!cin){
        return false;
    }

    deque<tNum> dq;
    
    // resolver el caso posiblemente llamando a otras funciones

    int num;
    cin >> num;
    dq.push_back({num, 0});

    // Buscamos el máximo de los primeros longitud elementos
    for (int i = 1; i < longitud; i++){
        cin >> num;
        if (dq.front().numero < num){
            dq.clear();
            dq.push_back({num, i});
        }
        else {
            while (!dq.empty() && dq.back().numero < num){
                dq.pop_back();
            }
            dq.push_back({num, i});
        }
    }

    cout << dq.front().numero << " ";

    // Con el resto de elementos
    for (int i = longitud; i < tam; i++){
        cin >> num;
        // Si el nuevo elemento es mayor que el máximo, actualizamos el máximo
        if (dq.front().numero < num){
            dq.clear();
            dq.push_back({num, i});
        }
        else {
            while (!dq.empty() && dq.back().numero < num){
                dq.pop_back();
            }
            dq.push_back({num, i});
        }
        if (dq.front().pos <= i - longitud){
            dq.pop_front();
        }
        // Escribimos el máximo
        cout << dq.front().numero << " ";
    }
    
    // escribir la solución

    cout << "\n";
 
    return true;
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
 