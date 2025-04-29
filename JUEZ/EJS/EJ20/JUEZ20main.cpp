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
 
 using namespace std;
 
 /*@ <answer>
   
  Escribe aquí un comentario general sobre la solución, explicando cómo
  se resuelve el problema y cuál es el coste de la solución, en función
  del tamaño del problema.

    Explicación de la solución:
    Usamos una pila para almacenar los accidentes que vamos leyendo. En cada iteración leemos un accidente y lo comparamos con los que ya tenemos en la pila. Si el accidente actual tiene más victimas que los que ya tenemos en la pila, quitamos los que tienen menos victimas que el actual. Después mostramos el primer
    accidente con más victimas o NO HAY si no hay ninguno. Por último añadimos el accidente a la pila.

    Coste de la solución:
    El coste de la solución es O(n) donde n es el número de accidentes que leemos.
    Al leer cada accidente realizamos comprobaciones constantes y añadimos el accidente a la pila.
    Ademas, el numero total de accidentes quitados es como mucho n, por lo que en total haremos como mucho
    n operaciones de quitar elementos de la pila, n operaciones de añadir elementos a la pila, n operaciones de mostrar elementos de la pila y n comparaciones de elementos de la pila.
  
  @ </answer> */
 
 
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

 struct tAccidente {
    string fecha;
    int victimas;
 };
 
 bool resuelveCaso() {
    
    // leer los datos de la entrada

    int cant;
    cin >> cant;
    
    // fin de la entrada
    if (!cin){
        return false;
    }
    
    // resolver el caso posiblemente llamando a otras funciones

    stack<tAccidente> dq;

    for (int i = 0; i < cant; i++) {
        // Leemos el accidente
        tAccidente a;
        cin >> a.fecha >> a.victimas;
        // Quitamos todos los accidentes que tengan menos victimas que el actual, ya que no nos interesan ni ahora (al tener menos no se muestran) ni despues
        while (!dq.empty() && dq.top().victimas <= a.victimas) {
            dq.pop();
        }
        // Mostramos el accidente con mas victimas o NO HAY si no hay ninguno
        if (!dq.empty()) {
            tAccidente aux = dq.top();
            cout << aux.fecha << endl;
        }
        else {
            cout << "NO HAY" << endl;
        }
        // Añadimos el accidente a la pila
        dq.push(a);
    }

    
    
    // escribir la solución

    cout << "---" << endl;
 
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
 