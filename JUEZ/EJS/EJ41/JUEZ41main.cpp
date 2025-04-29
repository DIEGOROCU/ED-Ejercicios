
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
 
 void leerMapa(map<string, int>& mapa) {
    string linea;
    getline(cin, linea); // Leer la línea completa
    stringstream ss(linea);
    string clave;
    int valor;

    while (ss >> clave >> valor) {
        mapa[clave] = valor; // Insertar clave y valor en el mapa
    }
}

 void resuelveCaso()
 {
 
    // leer los datos de la entrada
    map<string, int> mapa1, mapa2;
    
    leerMapa(mapa1);

    leerMapa(mapa2);
 
    // resolver el caso posiblemente llamando a otras funciones

    auto it1 = mapa1.begin();
    auto it2 = mapa2.begin();

    vector<string> clavesSolo1, clavesSolo2, clavesDistintoValor;

    while (it1 != mapa1.end() && it2 != mapa2.end()) {
        if (it1->first == it2->first) {
            if (it1->second != it2->second) {
                clavesDistintoValor.push_back(it1->first);
            }
            ++it1;
            ++it2;
        }
        else if (it1->first < it2->first) {
            clavesSolo1.push_back(it1->first);
            ++it1;
        }
        else {
            clavesSolo2.push_back(it2->first);
            ++it2;
        }
        
    }
    while (it1 != mapa1.end()) {
        clavesSolo1.push_back(it1->first);
        ++it1;
    }
    while (it2 != mapa2.end()) {
        clavesSolo2.push_back(it2->first);
        ++it2;
    }
 
    // escribir la solución

    if (!clavesSolo2.empty()) {
        cout << "+ ";
        for (const auto& clave : clavesSolo2) {
            cout << clave << " ";
        }
        cout << endl;
    }
    if (!clavesSolo1.empty()) {
        cout << "- ";
        for (const auto& clave : clavesSolo1) {
            cout << clave << " ";
        }
        cout << endl;
    }
    if (!clavesDistintoValor.empty()) {
        cout << "* ";
        for (const auto& clave : clavesDistintoValor) {
            cout << clave << " ";
        }
        cout << endl;
    }

    if (clavesSolo1.empty() && clavesSolo2.empty() && clavesDistintoValor.empty()) {
        cout << "Sin cambios" << endl;
    }

    cout << "---" << endl;


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
    std::cin.ignore(); // Ignorar el salto de línea después del número de casos
    for (int i = 0; i < numCasos; ++i)
       resuelveCaso();
 
    // para dejar todo como estaba al principio
 #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
 #endif
    return 0;
 }
 