
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

 Leemos el numero complejo, y durante las n veces pedidas se hace la operacion c = c^2 + c, si en algun momento el modulo del complejo supera 2, se imprime NO, en caso contrario SI.
 
 @ </answer> */


// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

// Clase Numero Complejo
class Complejo {
    public:
        Complejo() : real(0), imag(0) {}
        Complejo(double r, double i) : real(r), imag(i) {}
        double getReal() const { return real; }
        double getImag() const { return imag; }
        Complejo operator+(const Complejo & c) const {
            return Complejo(real + c.getReal(), imag + c.getImag());
        }
        Complejo operator*(const Complejo & c) const {
            return Complejo(real * c.getReal() - imag * c.getImag(), real * c.getImag() + imag * c.getReal());
        }
        double modulo() const {
            return sqrt(real * real + imag * imag);
        }

    private:
        double real, imag;
};

// Sobrecarga de operadores de lectura
istream & operator>>(istream & in, Complejo & c) {
    double r, i;
    in >> r >> i;
    c = Complejo(r, i);
    return in;
}

// Revisamos que el modulo del complejo sea menor o igual a 2
bool convergiendo(const Complejo & c) {
    return c.modulo() <= 2;
}

void resuelveCaso() {
   
   // leer los datos de la entrada
    Complejo c, sucesion (0, 0);
    cin >> c;

    int iteraciones;
    cin >> iteraciones;

    // resolver el caso posiblemente llamando a otras funciones
    bool converge = true;
    int i = 0;

    while (converge && i < iteraciones) {
        sucesion = sucesion * sucesion + c;
        if (!convergiendo(sucesion)) {
            converge = false;
        }
        i++;
    }

    if (!convergiendo(sucesion)) {
        converge = false;
    }

   // escribir la solución

    if (converge) cout << "SI" << endl;
    else cout << "NO" << endl;
   
   
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
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
