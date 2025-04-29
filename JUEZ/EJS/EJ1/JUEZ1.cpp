
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

// Clase Fecha
class Fecha {
public:

    Fecha() : hora(0), minuto(0), segundo(0) {}
    Fecha(int h, int m, int s) : hora(h), minuto(m), segundo(s) {}
    int getHora() const { return hora; }
    int getMinuto() const { return minuto; }
    int getSegundo() const { return segundo; }
    bool operator<(const Fecha& f) const {
        if (hora < f.hora) return true;
        if (hora > f.hora) return false;
        if (minuto < f.minuto) return true;
        if (minuto > f.minuto) return false;
        return segundo < f.segundo;
    }
    bool operator==(const Fecha& f) const {
        return hora == f.hora && minuto == f.minuto && segundo == f.segundo;
    }
    bool operator<=(const Fecha& f) const {
        return *this < f || *this == f;
    }
    void print(ostream& salida) const {
        salida << setfill('0') << setw(2) << hora << ':' << setfill('0') << setw(2) << minuto << ':' << setfill('0') << setw(2) << segundo;
    }   
   
private:
    int hora, minuto, segundo;
};

// Sobrecarga del operador de salida
ostream& operator<<(ostream& salida, const Fecha& f) {
    f.print(salida);
    return salida;
}

// Función que realiza la búsqueda binaria
int busquedaBinaria(const vector<Fecha>& v, const Fecha& f, int ini, int fin) {
    if (ini >= fin) return ini;
    int m = (ini + fin) / 2;
    if (v[m] < f) return busquedaBinaria(v, f, m + 1, fin);
    else return busquedaBinaria(v, f, ini, m);
}

// Función que realiza la consulta
void realizarConsulta(const vector<Fecha>& v){
    // Leemos la hora de la consulta
    int hora, minuto, segundo;
    char aux;
    cin >> hora >> aux >> minuto >> aux >> segundo;
    Fecha f(hora, minuto, segundo);
    // Buscamos el primer tren que sale después de la hora de la consulta
    int indi = busquedaBinaria(v, f, 0, v.size());
    // Devolvemos el resultado
    if (indi == v.size()) cout << "NO" << endl;
    else {
        cout << v[indi] << endl;
    }

}

bool resuelveCaso() {
    
    // Leemos el número de trenes y consultas
    int numTrenes, consultas;
    vector <Fecha> trenes;

    cin >> numTrenes >> consultas;
    
    if (numTrenes == 0 && consultas == 0) {
        return false;
    }
    
    else{
        // Leemos los trenes
        for (int i = 0; i < numTrenes; i++) {
            int hora, minuto, segundo;
            char aux;
            cin >> hora >> aux >> minuto >> aux >> segundo;
        Fecha f(hora, minuto, segundo);
            trenes.push_back(f);
        }
        // Realizamos las consultas
        for (int i = 0; i < consultas; i++) {
            realizarConsulta(trenes);
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
   ifstream in("casos.txt");
   auto cinbuf = cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());
   
   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
