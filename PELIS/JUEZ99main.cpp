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

// Estructura para representar una película
struct Pelicula {
    string titulo;
    int duracion; // Duración en minutos
    vector<pair<int, int>> horarios; // Horarios disponibles (hora, minuto)
};

// Convierte un horario (hora, minuto) a minutos desde las 00:00
int convertirAMinutos(int hora, int minuto) {
    return hora * 60 + minuto;
}

// Resuelve el caso
void resuelveCaso() {
    int numPeliculas;
    cin >> numPeliculas;

    vector<Pelicula> peliculas;

    // Leer las películas
    for (int i = 0; i < numPeliculas; ++i) {
        Pelicula peli;
        cin >> peli.titulo >> peli.duracion;

        int numHorarios;
        cin >> numHorarios;

        for (int j = 0; j < numHorarios; ++j) {
            int hora, minuto;
            char separador;
            cin >> hora >> separador >> minuto;
            peli.horarios.emplace_back(hora, minuto);
        }

        peliculas.push_back(peli);
    }

    // Crear una lista de todas las sesiones posibles (película, inicio, fin)
    vector<tuple<int, int, int>> sesiones; // (fin, inicio, índice de película)
    for (int i = 0; i < peliculas.size(); ++i) {
        for (auto& horario : peliculas[i].horarios) {
            int inicio = convertirAMinutos(horario.first, horario.second);
            int fin = inicio + peliculas[i].duracion;
            sesiones.emplace_back(fin, inicio, i);
        }
    }

    // Ordenar las sesiones por hora de finalización (primero `fin`, luego `inicio`)
    sort(sesiones.begin(), sesiones.end());

    // Seleccionar la combinación óptima de películas
    int ultimaHoraFin = 0;
    unordered_set<string> peliculasVistas; // Conjunto para registrar las películas vistas
    vector<tuple<string, int, int>> seleccionadas; // (título, inicio, fin)
    int tiempoEspera = INT_MAX; // Inicializar con un valor grande para minimizar

    for (size_t i = 0; i < sesiones.size(); ++i) {
        int tiempoEsperaActual = 0;
        int ultimaHoraFinActual = 0;
        unordered_set<string> peliculasVistasActual;
        vector<tuple<string, int, int>> seleccionadasActual;

        for (size_t j = i; j < sesiones.size(); ++j) {
            int fin = get<0>(sesiones[j]);
            int inicio = get<1>(sesiones[j]);
            int indicePelicula = get<2>(sesiones[j]);
            string titulo = peliculas[indicePelicula].titulo;

            // Verificar que la película no haya sido vista y que no haya solapamiento
            if (inicio >= ultimaHoraFinActual && peliculasVistasActual.find(titulo) == peliculasVistasActual.end()) {
                if (!seleccionadasActual.empty()) {
                    // Calcular el tiempo de espera entre la última película seleccionada y esta
                    tiempoEsperaActual += inicio - ultimaHoraFinActual;
                }
                seleccionadasActual.emplace_back(titulo, inicio, fin);
                ultimaHoraFinActual = fin;
                peliculasVistasActual.insert(titulo); // Marcar la película como vista
            }
        }

        // Actualizar si encontramos una mejor combinación
        if (seleccionadasActual.size() > seleccionadas.size() || 
            (seleccionadasActual.size() == seleccionadas.size() && tiempoEsperaActual < tiempoEspera)) {
            tiempoEspera = tiempoEsperaActual;
            ultimaHoraFin = ultimaHoraFinActual;
            peliculasVistas = peliculasVistasActual;
            seleccionadas = seleccionadasActual;
        }
    }

    // Imprimir el resultado
    cout << seleccionadas.size() << endl; // Número máximo de películas
    for (const auto& seleccion : seleccionadas) {
        string titulo = get<0>(seleccion);
        int inicio = get<1>(seleccion);
        int fin = get<2>(seleccion);

        // Convertir minutos a formato hora:minuto
        int inicioHora = inicio / 60, inicioMinuto = inicio % 60;
        int finHora = fin / 60, finMinuto = fin % 60;

        cout << titulo << " " 
             << setw(2) << setfill('0') << inicioHora << ":" 
             << setw(2) << setfill('0') << inicioMinuto << " - " 
             << setw(2) << setfill('0') << finHora << ":" 
             << setw(2) << setfill('0') << finMinuto << endl;
    }

    // Imprimir el tiempo total de espera
    cout << "Tiempo total de espera: " << tiempoEspera << " minutos" << endl;
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
