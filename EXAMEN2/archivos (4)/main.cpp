/*@ <authors>
 * ED-DG 30: Diego Rodriguez Cubero
 *@ </authors> */

/*@ <answer>

  El planteamiento del algoritmo es el siguiente:
  La funcion devolvera una tupla que diga: Cuantos partidos se han jugado hasta ese nodo, la altura (desde abajo, en el sentido de las rondas del enunciado para que cada vez la funcion sepa en que ronda esta) y si hay algun jugador hasta ese nodo
  Primero debemos revisar que estemos en una hoja, para ello como el arbol es completo, nos basta con comprobar si su rama de la izquierda esta vacia (y por tanto la derecha tambien lo estara)
  Este es nuestro caso base, en el cual devolvemos que no hay partidos (haya o no un jugador no puede haber jugado con nadie), que la altura es 1 para que asi la funcion que llamo a este caso base sepa que esta en la ronda 1, 
  y si hay un jugador (se comprueba que el nodo tiene un 1, esto nunca fallara ya que al ser un arbol completo, si sus ramas son vacias, estaremos en una hoja y por tanto tendra algun numero en ella, y durante nuestras llamadas recursivas siempre nos pararemos en dichas hojas)
  Si no estamos en el caso base, llamaremos recursivamente a ambas ramas para calcular los datos necesarios sin pasar varias veces por un mismo nodo, ya que cada altura llamara a la siguiente, y ella misma solo hará calculos y comprobaciones en cantidades y costes constantes
  Tras estas llamadas, tendremos calculados los partidos que se jugaron en ambas ramas, la ronda en la que estamos (al ser un arbol completo ambas ramas devolveran la misma ronda y por tanto podemos usar cualquiera de las dos), y si hay algun jugador en cada rama
  Ahora tenemos que comprobar si en nuestro nodo habra un partido (entendiendose como que los nodos de sus dos ramas han llevado a algun jugador, uno de los cuales ganara y se pondra en nuestro nodo)
  Para ello comprobamos primero que la ronda no se haya pasado de la que nos habian indicado, ya que hay que calcular los partidos de las k primeras rondas, y despues comprobamos que en ambas ramas haya jugadores, si se cumplen ambas, hay un partido que se ha jugado y por tanto se contabilizara
  Tras todo esto, devolvemos los resultados, la cantidad de partidos totales es la suma de los de la rama izquierda, la derecha y si ha habido un partido en nuestro nodo, la ronda sera la actual + 1, y si hay un jugador se devolvera comprobando si hay alguno en cualquiera de las dos ramas.
  Asi acaamos calculando todos los partidos de manera recursiva

  La recursion es del tipo: T(n) = 2T(n/2) + k
  Siendo n el numero de nodos que tiene el arbol en el que se hace la llamada, este coste sale ya que hacen 2 llamadas, cada una a una rama y por tanto con la mitad de nodos (al ser un arbol completo ambas ramas tienen la misma cantidad de nodos)
  K es una constante ya que tras las llamadas recursivas solo se hacen comprobaciones y operaciones en cantidades y costes constantes
  Nuestro caso base es trivialmente de coste constante, al solo hacer 1 comprobacion al devolver sus valores.
  Finalmente y teniendo en cuenta, como se ha explicado antes, que solo pasamos por cada nodo 1 vez con operaciones y comprobaciones en cantidades y costes constantes (tambien se puede usar el teorema de la division), podemos deducir que el coste total es:
  O(n)
  Con n el numero de nodos de nuestro arbol


 *@ </answer> */

#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <utility>
#include <algorithm>

// Clase para representar árboles binarios.
// No es posible modificar esta clase para el problema de hoy

template <class T>
class BinTree
{
public:
  BinTree() : root_node(nullptr) {}

  BinTree(const T &elem)
      : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

  BinTree(const BinTree &left, const T &elem, const BinTree &right)
      : root_node(std::make_shared<TreeNode>(left.root_node, elem,
                                             right.root_node)) {}

  bool empty() const { return root_node == nullptr; }

  const T &root() const
  {
    assert(root_node != nullptr);
    return root_node->elem;
  }

  BinTree left() const
  {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->left;
    return result;
  }

  BinTree right() const
  {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->right;
    return result;
  }

  void display(std::ostream &out) const { display_node(root_node, out); }

private:
  struct TreeNode;
  using NodePointer = std::shared_ptr<TreeNode>;

  struct TreeNode
  {
    TreeNode(const NodePointer &left, const T &elem, const NodePointer &right)
        : elem(elem), left(left), right(right) {}

    T elem;
    NodePointer left, right;
  };

  NodePointer root_node;

  static void display_node(const NodePointer &root, std::ostream &out)
  {
    if (root == nullptr)
    {
      out << ".";
    }
    else
    {
      out << "(";
      display_node(root->left, out);
      out << " " << root->elem << " ";
      display_node(root->right, out);
      out << ")";
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree)
{
  tree.display(out);
  return out;
}

template <typename T>
BinTree<T> read_tree(std::istream &in)
{
  char c;
  in >> c;
  if (c == '.')
  {
    return BinTree<T>();
  }
  else
  {
    assert(c == '(');
    BinTree<T> left = read_tree<T>(in);
    T elem;
    in >> elem;
    BinTree<T> right = read_tree<T>(in);
    in >> c;
    assert(c == ')');
    BinTree<T> result(left, elem, right);
    return result;
  }
}

using namespace std;

// ----------------------------------------------------------------
// Define aquí la función pedida en el enunciado.
// Puedes definir las funciones auxiliares que necesites, pero siempre
// entre las marcas
//@ <answer>

// Esta funcion calcula recursivamente la cantidad de partidos jugados hasta el nodo dado, la ronda que representa el mismo y si hay algun jugador hasta el (es decir si en sus ramas hay alguno)
std::tuple<int, int, bool> cantidadPartidos(BinTree<int> const &arbol, int const &rondas)
{

  // Caso base, si estamos en una hoja (mirar los detalles de la explicacion inicial) devolvemos que trivialmente
  // Que no se ha jugado ningun partido, el siguiente nodo sera la ronda 1 y devolvemos si tenemos o no un jugador
  // Al ser completo, una hoja sera aquel nodo que tiene cualquiera de las dos ramas vacia, por lo que comprobamos la izquierda arbitrariamente (en la explicacion inicial se detalla mas esto)
  if (arbol.left().empty())
  {
    return {0, 1, arbol.root() == 1};
  }
  else
  {
    // Calculamos los datos de ambas ramas de manera recursiva
    auto [partidosIzq, alturaIzq, hayIzq] = cantidadPartidos(arbol.left(), rondas);
    auto [partidosDer, alturaDer, hayDer] = cantidadPartidos(arbol.right(), rondas);
    // Creamos las variables auxiliares
    bool hayJugador = hayIzq || hayDer;
    bool hayPartido = hayIzq && hayDer;
    // Comprobamos si estamos en una ronda que queramos contabilizar, y si tenemos un partido (hay jugadores en ambas ramas), en ese caso sumaremos el partido que se juega en nuestro nodo a la cuenta total
    // Al ser un arbol completo ambas alturas seran iguales, por lo que usamos la de la izquierda arbitrariamente
    bool jugado = (alturaIzq <= rondas && hayPartido);
    // Devolvemos la cantidad de partidos jugados (los de ambas ramas y si ha habido uno en esta), que la ronda sera la siguiente para nuestro nodo padre, y si ha habido un jugador en cualquier rama
    return {partidosIzq + partidosDer + jugado, alturaIzq + 1, hayJugador};
  }
}

int partidos(BinTree<int> const &arbol, int rondas)
{
  // Llamada a mi funcion recursiva, y devolvemos los partidos jugados hasta el nodo inicial, es decir, los partidos en todo nuestro arbol (teniendo en cuenta la ronda maxima)
  auto [partidos, altura, hay] = cantidadPartidos(arbol, rondas);
  return partidos;

}

//@ </answer>
// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

bool resuelveCaso()
{
  auto arbol = read_tree<int>(cin);
  int rondas;
  cin >> rondas;
  cout << partidos(arbol, rondas) << "\n";
  return true;
}

int main()
{
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  int num_casos;
  cin >> num_casos;

  for (int i = 0; i < num_casos; ++i)
    resuelveCaso();

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif

  return 0;
}
