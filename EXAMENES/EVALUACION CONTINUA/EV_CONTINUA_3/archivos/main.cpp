/*@ <authors>
 *
 * ED-DG30 Diego Rodríguez
 * ED-DG26 Pablo Pardo
 *
 *@ </authors> */

/*@ <answer>

Nuestra implementación se basa en tener 3 mapas y una lista. 
Hemos usado unordered_maps para que el coste en promedio sea menor. 
El primero de los mapas guarda los alumnos por su dni y el grupo al que pertenecen, ordenada esta lista por el orden de insercion en la misma, luego está uno que es inverso al anterior en el que se guarda por cada grupo la lista de alumnos que pertenecen a dicho grupo. 
Debido a la función promocionar que elimina los alumnos de un grupo, hemos usado un tercer mapa para guardar por cada alumno un iterador que apunte a la posición en la lista de su grupo, para que así, al llamar a la función erase, el coste de la misma sea constante. 
Por último, hemos usado una lista llamada _graduados para almacenar los graduados, de manera que se actualiza cada vez que se promociona a alguien para saber si alguien ha superado el grupo 6 y por tanto se ha actualizado.

 @ </answer> */

#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <list>
#include <unordered_map>
#include <set>

// añade las librerías de la STL que necesites

using namespace std;

// Elige el tipo representante adecuado para el TAD AcademiaChino e
// implementa sus operaciones. Puedes añadir métodos o funciones privadas
// si lo consideras conveniente.
//@ <answer>

using dni = string;
using grupo = int;

class academia_chino
{
private:
   unordered_map<string, int> estudiante_grupo;
   unordered_map<int, list<string>> grupo_alumnos;
   list<string> _graduados;
   unordered_map<string, list<string>::iterator> alumnos_iterador;

   //unordered_map<int, list<string>> grupo_novato;

   // escribe aquí los atributos privados

public:
   academia_chino() {}

   void nuevo_estudiante(dni e, grupo g)
   {
      // Buscamos y revisamos excepciones
      if (g < 1 || g > 6)
      {
         throw domain_error("Grupo incorrecto");
      }
      auto it = estudiante_grupo.find(e);
      if (it != estudiante_grupo.end())
      {
         throw domain_error("Estudiante existente");
      }
      // Añadimos a nuestros conjuntos
      estudiante_grupo[e] = g;
      grupo_alumnos[g].push_back(e);
      alumnos_iterador[e] = --grupo_alumnos[g].end();
   }

   void promocionar(dni e)
   {
      // Buscamos y revisamos excepciones
      auto it = estudiante_grupo.find(e);
      if (it == estudiante_grupo.end()){
         throw domain_error("Estudiante no existente");
      }
      else if (it->second == 7){
         throw domain_error("Estudiante ya graduado");
      }
      else {
         it->second++;
         if (it->second == 7){
            auto it2 = std::lower_bound(_graduados.begin(), _graduados.end(), e);
            _graduados.insert(it2, e);
         }
         int aux = it->second - 1;
          grupo_alumnos[aux].erase(alumnos_iterador[e]);
          alumnos_iterador.erase(e);
          grupo_alumnos[aux + 1].push_back(e);
          alumnos_iterador[e] = --grupo_alumnos[aux + 1].end();

      }
   }

   int grupo_estudiante(dni e) const
   {
      // Buscamos y revisamos excepciones
      auto it = estudiante_grupo.find(e);
      if (it == estudiante_grupo.end()){
         throw domain_error("Estudiante no existente");
      }
      else if (it->second == 7){
         throw domain_error("Estudiante ya graduado");
      }
      else {
         // Devolvemos el grupo correspondiente
         return it->second;
      } 
   }

   list<dni> graduados() const
   {
      // Devolvemos la lista ya ordenada de graduados
      return _graduados;      
   }

   dni novato(grupo g) const
      {
         // Buscamos y revisamos excepciones
         auto it = grupo_alumnos.find(g);
         if (it == grupo_alumnos.end() || it->second.empty())
         {
            throw domain_error("Grupo sin novatos");
         }
         // Devolvemos el novato (esta al final de la lista)
         auto it2 = it->second.end();
         --it2;
         string _dni = *it2;
         return _dni;
      }
};

//@ </answer>
// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

bool resuelveCaso()
{
   string orden;
   cin >> orden;
   if (!cin)
      return false;

   string dni;
   int grupo;

   academia_chino ac;

   while (orden != "FIN")
   {
      try
      {
         if (orden == "nuevo_estudiante")
         {
            cin >> dni >> grupo;
            ac.nuevo_estudiante(dni, grupo);
         }
         else if (orden == "grupo_estudiante")
         {
            cin >> dni;
            int grupo = ac.grupo_estudiante(dni);
            cout << dni << " esta en el grupo " << grupo << '\n';
         }
         else if (orden == "promocionar")
         {
            cin >> dni;
            ac.promocionar(dni);
         }
         else if (orden == "graduados")
         {
            auto graduados = ac.graduados();
            cout << "Lista de graduados:";
            for (string const &s : graduados)
            {
               cout << ' ' << s;
            }
            cout << '\n';
         }
         else if (orden == "novato")
         {
            cin >> grupo;
            string novato = ac.novato(grupo);
            cout << "Novato de " << grupo << ": " << novato << '\n';
         }
      }
      catch (std::domain_error &e)
      {
         cout << "ERROR: " << e.what() << '\n';
      }

      cin >> orden;
   }
   cout << "---\n";

   return true;
}

int main()
{
#ifndef DOMJUDGE
   std::ifstream in("casos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso())
   {
   }

#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
#endif
   return 0;
}
