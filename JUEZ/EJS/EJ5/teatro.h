const int MAX_RESERVAS = 50000;

#include <string>
#include <vector>

using namespace std;

class Teatro
{
public:

// Ambos costes son de O(log n) ya que se realizan búsquedas binarias en un vector ordenado

bool nueva_reserva(int inicio, int fin, string nombre){
    int ini = 0, fini = num_reservas - 1;
    while(ini <= fini){
        int mitad = (ini + fini) / 2;
        if((inicio >= reservas[mitad].inicio && inicio <= reservas[mitad].fin)
        || (fin >= reservas[mitad].inicio && fin <= reservas[mitad].fin)
        || (reservas[mitad].inicio >= inicio && reservas[mitad].inicio <= fin)
        || (reservas[mitad].fin >= inicio && reservas[mitad].fin <= fin)){
            return false;
        }
        if(reservas[mitad].inicio < inicio){
            ini = mitad + 1;
        }else{
            fini = mitad - 1;
        }
    }
    Reserva r;
    r.inicio = inicio;
    r.fin = fin;
    r.nombre = nombre;
    reservas.insert(reservas.begin() + ini, r);
    num_reservas++;
    return true;
}

string nombre_reserva(int num_butaca){
    int ini = 0, fini = num_reservas - 1;
    while(ini <= fini){
        int mitad = (ini + fini) / 2;
        if(num_butaca >= reservas[mitad].inicio && num_butaca <= reservas[mitad].fin){
            return reservas[mitad].nombre;
        }
        if(reservas[mitad].inicio < num_butaca){
            ini = mitad + 1;
        }else{
            fini = mitad - 1;
        }
    }
    // Prefiero devolver LIBRE para facilitar la implementación de la función principal
    return "LIBRE";
}


private:
    struct Reserva
    {
        int inicio;
        int fin;
        string nombre;
    };
    vector<Reserva> reservas;
    int num_reservas = 0;
};
