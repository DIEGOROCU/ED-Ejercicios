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

 struct tDeporte
{
    string nombre;
    int cantidad = 0;
    tDeporte(string nombre) : nombre(nombre) {}
};

struct tAlumno
{
    string nombre;
    int cantidad = 0;
    set<tDeporte*> deportes;
    tAlumno(string nombre) : nombre(nombre) {}
};
 
 bool resuelveCaso()
 {
 
    // leer los datos de la entrada
    // completar
    string nombre;
    cin >> nombre;
 
    // fin de la entrada
    if (!cin)
    {
       return false;
    }
 
    set<tAlumno*> alumnos;
    while (nombre != "_FIN_")
    {
        tDeporte* deporte = new tDeporte(nombre);
        cin >> nombre;
        while (!isupper(nombre[0]) && nombre != "_FIN_")
        {
            tAlumno* alumno = new tAlumno(nombre);
            if (alumnos.find(alumno) == alumnos.end())
            {
                alumnos.insert(alumno);
                alumno->deportes.insert(deporte);
                deporte->cantidad++;
            }
            else
            {
                auto it = alumnos.find(alumno);
                if (it != alumnos.end())
                {
                    (*it)->deportes.insert(deporte);
                    for (auto d : (*it)->deportes)
                    {
                        d->cantidad--;
                    }
                }
                (*it)->deportes.insert(deporte);
            }
            cin >> nombre;
        }        
    }

    // Recorramos todos los alumnos para obtener un vector de deportes ordenados, primero según la cantidad de alumnos que lo practican y luego por el nombre del deporte
    vector<tDeporte*> deportes;
    for (auto it : alumnos)
    {
        for (auto d : it->deportes)
        {
            // Realizamos una búsqueda binaria para ver si el deporte ya está en el vector
            auto it = lower_bound(deportes.begin(), deportes.end(), d, [](tDeporte* d1, tDeporte* d2) {
                return d1->nombre < d2->nombre;
            });
            if (it == deportes.end() || (*it)->nombre != d->nombre)
            {
                deportes.insert(it, d);
            }
        }
    }
    sort(deportes.begin(), deportes.end(), [](tDeporte* d1, tDeporte* d2) {
        if (d1->cantidad == d2->cantidad)
            return d1->nombre < d2->nombre;
        return d1->cantidad > d2->cantidad;
    });

    // Imprimimos los deportes
    for (auto d : deportes)
    {
        cout << d->nombre << " " << d->cantidad - 1 << endl;
    }

    cout << "---" << endl;

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
 