
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
 
 using namespace std;

class tPersona {
    public:

    tPersona(string nombre, int edad) : nombreCompleto(nombre), edad(edad) {}
    tPersona(): nombreCompleto(""), edad(0) {}

    int getEdad() const {return edad;}
    string getNombre() const {return nombreCompleto;}
    
    private:
        string nombreCompleto;
        int edad;
};

class estaEntreXeY {
    public:
    estaEntreXeY(int x, int y) : x(x), y(y) {}

    bool operator()(const tPersona &persona) const {
        return persona.getEdad() >= x && persona.getEdad() <= y;
    }

    private:
        int x, y;
};

template <typename T, typename U>
    void eliminarElementos(vector<T> &elems, U fun) {
        auto it = elems.begin();
        while (it != elems.end()) {
            if (fun(*it)) {
                it = elems.erase(it);
            }
            else {
                ++it;
            }
        }
    }
 
 /*@ <answer>
 
  Escribe aquí un comentario general sobre la solución, explicando cómo
  se resuelve el problema y cuál es el coste de la solución, en función
  del tamaño del problema.
  
  @ </answer> */
 
 
 // ================================================================
 // Escribe el código completo de tu solución aquí debajo
 // ================================================================
 //@ <answer>

 
 bool resuelveCaso() {
    
    // leer los datos de la entrada

    int tam, mini, maxi;
    cin >> tam >> mini >> maxi;
    if (tam == 0) return false;
    vector<tPersona> personas(tam);

    for (int i = 0; i < tam; ++i) {
        int edad;
        cin >> edad;
        string nombreCompleto;
        cin.ignore();
        getline(cin, nombreCompleto);
        tPersona persona(nombreCompleto, edad);
        personas[i] = persona;
    }
    
    // resolver el caso posiblemente llamando a otras funciones
    //estaEntreXeY fun(mini, maxi);
    //eliminarElementos(personas, fun);

    vector<tPersona> personasDev;
    copy_if(personas.begin(), personas.end(), back_inserter(personasDev), estaEntreXeY(mini, maxi));
    
    // escribir la solución
    for (int i = 0; i < personasDev.size(); ++i) {
        cout << personasDev[i].getNombre() << endl;
    }
    cout << "---" << endl;
    return true;
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
 