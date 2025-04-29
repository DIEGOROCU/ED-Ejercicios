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

#include "multiconjunto.h"

using namespace std;

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.
 Primero leemos los datos
 Luego recorremos los vectores buscando los numeros verdes
 Despues, recorremos el vector en busca de los numeros amarillos
 Constantemente si encontramos un numero lo eliminamos del multiconjunto

 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo
// ================================================================
//@ <answer>

bool resuelveCaso()
{

   // leer los datos de la entrada
   int tam;
   cin >> tam;

   if (tam == 0)
   {
      return false;
   }
   else
   {
      Multiconjunto solucion;
      vector<int> entrada(tam), dado(tam);
      for (int i = 0; i < tam; i++){
         int num;
         cin >> num;
         solucion.anyadir(num);
         entrada[i] = num;
      }
      for (int i = 0; i < tam; i++){
         cin >> dado[i];
      }
      vector<char> resultado(tam, '.');

      // resolver el caso posiblemente llamando a otras funciones

      // Comprobamos los numeros verdes
      for (int i = 0; i < tam; i++){
         if (entrada[i] == dado[i]){
            resultado[i] = '#';
            solucion.eliminar(entrada[i]);
         }
      }
      // Comprobamos los numeros amarillos
      for (int i = 0; i < tam; i++){
         if (resultado[i] == '.' && solucion.pertenece(dado[i])){
            resultado[i] = 'O';
            solucion.eliminar(dado[i]);
         }
      }

      // Imprimimos el resultado
      for (int i = 0; i < tam; i++){
         cout << resultado[i];
      }

      cout << '\n';
      
      return true;
   }
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
