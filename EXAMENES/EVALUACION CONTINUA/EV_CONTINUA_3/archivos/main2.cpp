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
 del problema (que debes elegir correctamente).

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
    unordered_map <string, pair<int, list<string>::iterator>> alumnos;
    unordered_map <int, list<string>> grupos;

    public:

    academia_chino()
    {
    }

    void nuevo_estudiante(dni e, grupo g)
    {
        if (g < 1 || g > 6){
            throw domain_error("Grupo incorrecto");
        }
        auto it = alumnos.find(e);
        if (it != alumnos.end()){
            throw domain_error("Estudiante existente");
        }
        else {
            // Añadimos el alumno al grupo
            grupos[g].push_back(e);
            auto nuevo_al = grupos[g].end();
            nuevo_al--;
            // Lo añadimos al listado
            alumnos[e] = pair{g, nuevo_al};
        }
    }

    void promocionar(dni e)
    {
        auto it = alumnos.find(e);
        if (it == alumnos.end()){
            throw domain_error("Estudiante no existente");
        }
        else if (it->second.first == 7){
            throw domain_error("Estudiante ya graduado");
        }
        else {
            // Alumno
            auto _alumno = it->second;
            // Borramos del grupo
            grupos[_alumno.first].erase(_alumno.second);
            // Añadimos al nuevo grupo
            grupos[_alumno.first + 1].push_back(e);
            // Ajustamos el iterador
            auto nuevo_al = grupos[_alumno.first + 1].end();
            nuevo_al--;
            it->second.first++;
            it->second.second = nuevo_al;
        }
    }

    int grupo_estudiante(dni e) const
    {
        auto it = alumnos.find(e);
        if (it == alumnos.end()){
            throw domain_error("Estudiante no existente");
        }
        else if (it->second.first == 7){
            throw domain_error("Estudiante ya graduado");
        }
        else {
            return it->second.first;
        }
    }

    list<dni> graduados() const
    {
        auto it = grupos.find(7);
        return it->second;
    }

    dni novato(grupo g) const
    {
        if (g < 1 || g > 6){
            throw domain_error("Grupo incorrecto");
        }
        auto it = grupos.find(g);
        if (it == grupos.end() || it->second.empty()){
            throw domain_error("Grupo vacio");
        }
        else {
            return it->second.back();
        }
        
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
