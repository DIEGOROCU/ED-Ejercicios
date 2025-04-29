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
 
 bool resuelveCaso() {
    
    // leer los datos de la entrada

    int tam;
    cin >> tam;
    
    // fin de la entrada
    if (!cin){
        return false;
    }
    
    // resolver el caso posiblemente llamando a otras funciones

    bool sePuede = true;
    stack<int> pila;
    vector<int> v(tam);
    for (int i = 0; i < tam; i++){
        cin >> v[i];
    }

    int mediano = - 1;

    for (int i = v.size() - 1; i > -1 && sePuede; --i){
        if (v[i] < mediano){
            sePuede = false;
        }
        else {
            while (!pila.empty() && pila.top() < v[i]){
                mediano = max(mediano, pila.top());
                pila.pop();
            }
            pila.push(v[i]);
        }
    }
   
    
    // escribir la solución

    if (sePuede){
        cout << "SIEMPRE PREMIO\n";
    }
    else {
        cout << "ELEGIR OTRA\n";
    }
 
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
 