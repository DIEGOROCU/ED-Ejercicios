/*@ <authors>
 *
 * ED-DG88 Zipi Zapatilla
 * ED-DG89 Zape Zapatilla
 *
 *@ </authors> */

/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando qué tipos has elegido
 para guardar la información y poder tratarla de forma eficiente, y cuáles son las
 razones de esa elección. Indica al lado de cada operación su coste en función del tamaño
 del problema.

 @ </answer> */

// Añade los include que necesites
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

// Tipo de datos para representar direcciones
// Para hacer referencia a los elementos de este tipo enumerado se utiliza:
//   Direccion::Norte, Direccion::Sur, etc.
enum class Direccion
{
  Norte,
  Sur,
  Este,
  Oeste
};

// Operador para leer una dirección desde un flujo de entrada.
// Ejemplo de uso:
//
// Direccion dir;
// cin >> dir;
//
istream &operator>>(istream &is, Direccion &dir)
{
  string palabra;
  is >> palabra;
  if (palabra == "Norte")
    dir = Direccion::Norte;
  else if (palabra == "Sur")
    dir = Direccion::Sur;
  else if (palabra == "Este")
    dir = Direccion::Este;
  else if (palabra == "Oeste")
    dir = Direccion::Oeste;
  else
    throw std::domain_error("Lectura de direccion incorrecta");
  return is;
}

// Implementa a continuación la clase Desierto.
//@ <answer>

/*
Explicacion de la solución:
Las funciones son autodescriptivas, y esta comentado su funcionamiento en cda una.
Los costes son en el caso peor (usamos n como el numero de torres):
  - anyadir_torre: O(n)
  Se buscan en ambos mapas si existe el nombre y la posición, y se añade a ambos mapas, ambos de tamano n.
  Ademas se añade a la matriz, algo que en el caso peor de redimensionar la matriz es O(n), por tanto O(n+n)=O(n).
  Entre medias se hacen comprobaciones y operaciones de coste O(1), en cantidades constantes, por lo que no afectan al coste.
  - eliminar_torre: O(n)
  Se busca el nombre en el mapa de nombres, y se busca la posición en el mapa de torres, ambos de tamaño n.
  Se eliminan de ambos mapas, y se elimina de la matriz, O(n) en el caso peor.
  Entre medias se hacen comprobaciones y operaciones de coste O(1), en cantidades constantes, por lo que no afectan al coste.
  - posicion: O(n)
  Se busca el nombre en el mapa de nombres, y se devuelve la posición, O(n).
  Entrre medias se hacen comprobaciones y operaciones de coste O(1), en cantidades constantes, por lo que no afectan al coste.
  - torre_en_posicion: O(n)
  Se busca la posición en el mapa de torres, y se devuelve el nombre, O(n).
  Entre medias se hacen comprobaciones y operaciones de coste O(1), en cantidades constantes, por lo que no afectan al coste.
  - torre_mas_cercana: O(n)
  Se busca el nombre en el mapa de nombres, y se obtiene la posición, O(n).
  Se busca la torre en la dirección indicada, O(n) en el caso peor (si las torres estan en fila).
  Entre medias se hacen comprobaciones y operaciones de coste O(1), en cantidades constantes, por lo que no afectan al coste.
  En total, el coste es O(n*m), donde n es el numero de torres y m la cantidad de operaciones a realizar.
*/

class Desierto
{
public:
  Desierto() {}

  void anyadir_torre(const string &nombre, int x, int y)
  {

    // Comprobamos si el nombre ya existe
    if (nombres.find(nombre) != nombres.end())
    {
      throw domain_error("Torre ya existente");
    }
    // Comprobamos si la posición ya está ocupada
    if (torres.find({x, y}) != torres.end())
    {
      throw domain_error("Posicion ocupada");
    }
    torres[{x, y}] = nombre;
    nombres[nombre] = {x, y};
    // Añadimos la torre a la matriz
    if (x >= matriz.size())
    {
      matriz.resize(x + 1);
    }
    if (y >= matriz[x].size())
    {
      matriz[x].resize(y + 1);
    }
    matriz[x][y] = nombre;
  }

  void eliminar_torre(const string &nombre)
  {
    // Comprobamos si el nombre existe
    if (nombres.find(nombre) == nombres.end())
    {
      throw domain_error("Torre no existente");
    }
    // Buscamos la torre por su nombre
    auto it = torres.begin();
    while (it != torres.end() && it->second != nombre)
    {
      ++it;
    }
    if (it != torres.end())
    {
      // Buscamos la posición de la torre en la matriz
      auto pos = nombres[nombre];
      // La eliminamos de la matriz
      matriz[pos.first][pos.second] = "";
      // Si la torre existe, la eliminamos
      torres.erase(it);
      nombres.erase(nombre);
    }
    // No deberia llegar aquí, ya que hemos comprobado que el nombre existe
    else
    {
      throw domain_error("Torre no existente");
    }
  }

  pair<bool, string> torre_en_posicion(int x, int y) const
  {
    if (torres.find({x, y}) != torres.end())
    {
      return {true, torres.at({x, y})};
    }
    else
    {
      return {false, ""};
    }
  }

  pair<int, int> posicion(const string &nombre) const
  {
    // Comprobamos si el nombre existe
    if (nombres.find(nombre) != nombres.end())
    {
      return nombres.at(nombre);
    }
    else
    {
      throw domain_error("Torre no existente");
    }
    
  }

  string torre_mas_cercana(const string &nombre, const Direccion &dir) const
  {
    // Comprobamos si el nombre existe
    auto it = nombres.find(nombre);
    if (it == nombres.end())
    {
      throw domain_error("Torre no existente");
    }
    else {
      // Cogemos las coordenadas de la torre
      auto pos = it->second;
      int x = pos.first;
      int y = pos.second;

      switch(dir)
      {
        // Caso Norte/Sur
        // Se recorre el vector x de la matriz en el sentido de la dirección, buscando la primera torre
        // Se devuelve el nombre de la torre, o se lanza una excepción si no hay torres
        case Direccion::Norte:
          y++;
          while (y < matriz[x].size() && matriz[x][y] == "")
          {
            y++;
          }
          if (y < matriz[x].size())
          {
            return matriz[x][y];
          }
          else
          {
            throw domain_error("No hay torres en esa direccion");
          }
        case Direccion::Sur:
          y--;
          while (y >= 0 && matriz[x][y] == "")
          {
            y--;
          }
          if (y >= 0)
          {
            return matriz[x][y];
          }
          else
          {
            throw domain_error("No hay torres en esa direccion");
          }
        // Caso Este/Oeste
        // Se recorren los vectores desde x, manteniendo la posición de y constante, revisando que no accedamos a una posición fuera de la matriz
        // Se devuelve el nombre de la torre, o se lanza una excepción si no hay torres
        case Direccion::Este:
          x++;
          while (x < matriz.size())
          {
            if (y >= matriz[x].size() || matriz[x][y] == "")
            {
              x++;
            }
            else
            {
              break;
            }
          }
          if (x < matriz.size())
          {
            return matriz[x][y];
          }
          else
          {
            throw domain_error("No hay torres en esa direccion");
          }
        case Direccion::Oeste:
          x--;
          while (x >= 0)
          {
            if (y >= matriz[x].size() || matriz[x][y] == "")
            {
              x--;
            }
            else
            {
              break;
            }
          }
          if (x >= 0)
          {
            return matriz[x][y];
          }
          else
          {
            throw domain_error("No hay torres en esa direccion");
          }
        default:
          throw domain_error("Direccion no valida");
      }
      
    }
  }

private:
  map<pair<int, int>, string> torres; // Mapa de coordenadas a nombres de torres
  map<string, pair<int, int>> nombres;      // Conjunto de nombres de torres
  // Matriz de coordenadas a nombres de torres
  vector<vector<string>> matriz;
};

//@ </answer>
// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

bool resuelveCaso()
{
  string inst, nombre;
  int x, y;
  Direccion dir;
  cin >> inst;
  if (!cin)
    return false;
  Desierto desierto;
  while (inst != "FIN")
  {
    try
    {
      if (inst == "anyadir_torre")
      {
        cin >> nombre >> x >> y;
        desierto.anyadir_torre(nombre, x, y);
      }
      else if (inst == "eliminar_torre")
      {
        cin >> nombre;
        desierto.eliminar_torre(nombre);
      }
      else if (inst == "posicion")
      {
        cin >> nombre;
        auto [x, y] = desierto.posicion(nombre);
        cout << x << ' ' << y << '\n';
      }
      else if (inst == "torre_en_posicion")
      {
        cin >> x >> y;
        auto [hay, nombre] = desierto.torre_en_posicion(x, y);
        if (hay)
          cout << "SI " << nombre << '\n';
        else
          cout << "NO\n";
      }
      else
      {
        cin >> nombre >> dir;
        nombre = desierto.torre_mas_cercana(nombre, dir);
        cout << nombre << '\n';
      }
    }
    catch (domain_error &e)
    {
      cout << e.what() << '\n';
    }
    cin >> inst;
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
