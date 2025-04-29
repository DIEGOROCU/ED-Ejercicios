
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
 
 void resuelveCaso()
 {
 
    // leer los datos de la entrada
    int capitulos;
    cin >> capitulos;
    unordered_map<int, int> capitulosLeidos;
    int maximo = 1, maximoProv = 1, inicio = 0;
    int auxi;
    cin >> auxi;
    capitulosLeidos[auxi] = 0;
    for (int i = 1; i < capitulos; ++i) {
        int capitulo;
        cin >> capitulo;
        if (capitulosLeidos.find(capitulo) == capitulosLeidos.end()) {
            maximoProv++;
            capitulosLeidos[capitulo] = i;
        }
        else {
            maximo = max(maximo, maximoProv);
            inicio = max(inicio, capitulosLeidos[capitulo] + 1);
            maximoProv = i - inicio + 1;
            capitulosLeidos[capitulo] = i;
        }
    }
    maximo = max(maximo, maximoProv);

    // resolver el caso posiblemente llamando a otras funciones
    
    cout << maximo << endl;
 
    // escribir la solución
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
 
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
       resuelveCaso();
 
    // para dejar todo como estaba al principio
 #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
 #endif
    return 0;
 }
 