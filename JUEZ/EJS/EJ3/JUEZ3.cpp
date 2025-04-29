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
#include <cassert>

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
    Fecha operator+(const Fecha& f) const {
        int h = hora + f.hora;
        int m = minuto + f.minuto;
        int s = segundo + f.segundo;
        if (s >= 60) {
            s -= 60;
            m++;
        }
        if (m >= 60) {
            m -= 60;
            h++;
        }
        assert (h < 24);
        return Fecha(h, m, s);
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

// Sobrecaarga del operador de entrada
istream& operator>>(istream& entrada, Fecha& f) {
    char aux;
    int hora, minuto, segundo;
    entrada >> hora >> aux >> minuto >> aux >> segundo;
    f = Fecha(hora, minuto, segundo);
    return entrada;
}

// Clase Peli
class Peli {
    public:
        Peli() {}
        Peli(Fecha f, string n) : fin(f), nombre(n) {}
        bool operator<(const Peli& p) const {
            return fin < p.fin || (fin == p.fin && nombre < p.nombre);
        }
        void print(ostream& salida) const {
            salida << fin << nombre;
        }
    private:
        Fecha fin;
        string nombre;
};

// Sobrecaarga del operador de salida
ostream& operator<<(ostream& salida, const Peli& p) {
    p.print(salida);
    return salida;
}

// Sobrecaarga del operador de entrada
istream& operator>>(istream& entrada, Peli& p) {
    Fecha inicio, duracion;
    string nombre;
    entrada >> inicio >> duracion;
    getline(entrada, nombre);
    p = Peli(inicio + duracion, nombre);
    return entrada;
}



bool resuelveCaso() {
   
   // leer los datos de la entrada

   int numPelis;
    cin >> numPelis;

   
   if (numPelis == 0){
         return false;
   }
   else {

        vector<Peli> pelis(numPelis);
        for (int i = 0; i < numPelis; i++) {
            cin >> pelis[i];
        }
           // resolver el caso posiblemente llamando a otras funciones

        sort(pelis.begin(), pelis.end());
        for (int i = 0; i < numPelis; i++) {
            cout << pelis[i] << endl;
        }

            // escribir la solución

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
