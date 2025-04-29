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

#include "BinTree.h"

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

template <typename T>
vector<T> getInOrden(BinTree<T> arbol)
{
    if (arbol.empty())
    {
        return {};
    }
    vector<T> res;
    vector<T> izq = getInOrden(arbol.left());
    vector<T> der = getInOrden(arbol.right());
    res.insert(res.end(), izq.begin(), izq.end());
    res.push_back(arbol.root());
    res.insert(res.end(), der.begin(), der.end());
    return res;
}

template <typename T>
bool is_sorted_no_duplicates(vector<T> &v)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] <= v[i - 1])
        {
            return false;
        }
    }
    return true;
}

bool es_busqueda(const BinTree<int> &arbol, int &mini, int &maxi){
    if (arbol.left().empty() && arbol.right().empty()){
        mini = arbol.root();
        maxi = arbol.root();
        return true;
    }
    bool iz = es_busqueda(arbol.left(), mini, maxi);
    int miniIz = mini;
    int maxiIz = maxi;
    bool dr = es_busqueda(arbol.right(), mini, maxi);
    int miniDer = mini;
    int maxiDer = maxi;
    if (arbol.root() > maxiIz && arbol.root() < miniDer){
        mini = miniIz;
        maxi = maxiDer;
        return true;
    } else {
        return false;
    }

}

bool resuelveCaso()
{

    // leer los datos de la entrada
    char tipo;
    cin >> tipo;

    // fin de la entrada
    if (!cin)
    {
        return false;
    }

    // resolver el caso posiblemente llamando a otras funciones
    if (tipo == 'N'){
        BinTree<int> arbol = read_tree<int>(cin);
        vector<int> inOrden = getInOrden(arbol);
        if (is_sorted_no_duplicates(inOrden)){
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
    } else if (tipo == 'P'){
        BinTree<string> arbol = read_tree<string>(cin);
        vector<string> inOrden = getInOrden(arbol);
        if (is_sorted_no_duplicates(inOrden)){
            cout << "SI\n";
        } else {
            cout << "NO\n";
        }
    }

        // escribir la solución

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
