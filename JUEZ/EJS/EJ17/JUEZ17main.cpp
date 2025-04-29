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

 bool esVocal(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
 }
 
 bool resuelveCaso() {
    
    // leer los datos de la entrada

    stack<char> aux;
    queue<char> frase, resultado;
    deque<char> reordenamientoIzq, reordenamientoDer, reordenamiento;

    string fraseEntrada;
    getline(cin, fraseEntrada);
    
    // fin de la entrada
    if (!cin){
        return false;
    }
    
    // resolver el caso posiblemente llamando a otras funciones

    for (int i = 0; i < fraseEntrada.size(); i++) {
        frase.push(fraseEntrada[i]);
    }

    // Separamos los caracteres del inicio y del final de la frase
    bool inicio = true;
    while (!frase.empty()) {
        if (inicio){
            reordenamientoIzq.push_back(frase.front());
            frase.pop();
        }
        else {
            reordenamientoDer.push_back(frase.front());
            frase.pop();
        }
        inicio = !inicio;
    }

    // Reordenamos los caracteres
    while (!reordenamientoIzq.empty()) {
        reordenamiento.push_back(reordenamientoIzq.front());
        reordenamientoIzq.pop_front();
    }
    while (!reordenamientoDer.empty()) {
        reordenamiento.push_back(reordenamientoDer.back());
        reordenamientoDer.pop_back();
    }
    
    while (!reordenamiento.empty()) {
        if (esVocal(reordenamiento.front())) {
            while (!aux.empty()) {
                resultado.push(aux.top());
                aux.pop();
            }
            resultado.push(reordenamiento.front());
            reordenamiento.pop_front();
        }
        else {
            aux.push(reordenamiento.front());
            reordenamiento.pop_front();
        }
    }
    while (!aux.empty()) {
        resultado.push(aux.top());
        aux.pop();
    }

    // escribir la solución

    while (!resultado.empty()) {
        cout << resultado.front();
        resultado.pop();
    }

    cout << endl;
 
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
 