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

 void insertarOrdenado(vector<pair<int, int>>& v, pair<int, int> p) {
     auto it = v.begin();
     while (it != v.end() && it->second < p.second) {
         ++it;
     }
     if (it == v.end()) {
         v.push_back(p);
     } else if (it->second > p.second) {
         v.insert(it, p);
     } else {
         it->first += p.first;
     }
 }
 
 bool resuelveCaso()
 {
 
    int hRep, hYem, hTot;
    cin >> hRep >> hYem >> hTot;
    if (!cin)
    {
       return false;
    }
 
    // resolver el caso posiblemente llamando a otras funciones

    vector<pair<int, int>> hongos;
    hongos.push_back({ 1, hRep });
    int contador = 0;

    while (hongos[0].second + contador <= hTot) {
        int cant = hongos[0].first, tiempo = hongos[0].second;
        for (int i = 0; i < hongos.size(); ++i) {
            hongos[i].second -= tiempo;
        }
        for (int i = 0; i < hongos.size() - 1; ++i) {
            hongos[i] = hongos[i + 1];
        }
        hongos.pop_back();
        hongos.push_back({ cant, hYem });
        insertarOrdenado(hongos, { cant, hRep });
        contador += tiempo;
    }
 
    // escribir la solución
    int sol = 0;
    for (int i = 0; i < hongos.size(); ++i) {
        sol += hongos[i].first;
    }

    cout << sol << endl;
 
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
 