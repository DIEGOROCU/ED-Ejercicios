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

 #include "StackArray.h"
 
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
    string linea;
    getline(cin, linea);
    
    if (!cin){
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    StackArray<char> pila(linea.size());
    int i = 0;
    // Recorremos la linea
    while (i < linea.size()){
        // Si abre, lo metemos en la pila
        if (linea[i] == '(' || linea[i] == '[' || linea[i] == '{'){
            pila.push(linea[i]);
        } 
        // Si cierra, comprobamos que la pila no esté vacía y que el último elemento de la pila sea el que cierra
        else if (linea[i] == ')' || linea[i] == ']' || linea[i] == '}'){
            // Si la pila esta vacia es que no hubo apertura
            if (pila.empty()){
                cout << "NO\n";
                return true;
            } else {
                // Revisamos que el último elemento de la pila sea el que abre correspondiente
                char c = pila.top();
                pila.pop();
                if (c == '(' && linea[i] != ')'){
                    cout << "NO\n";
                    return true;
                } else if (c == '[' && linea[i] != ']'){
                    cout << "NO\n";
                    return true;
                } else if (c == '{' && linea[i] != '}'){
                    cout << "NO\n";
                    return true;
                }
            }
        }
        i++;
    }

    if (pila.empty()){
        cout << "SI\n";
    } else {
        cout << "NO\n";
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
 