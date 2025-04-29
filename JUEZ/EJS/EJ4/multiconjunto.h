const int MAX_ELEMS = 2000;
class Multiconjunto
{
public:
    Multiconjunto() : num_elems(0) {}
    void anyadir(int num){
        int ini = 0, fin = num_elems - 1;
        while (ini <= fin) {
            int mitad = (ini + fin) / 2;
            if (elems[mitad].valor < num) ini = mitad + 1;
            else if (elems[mitad].valor > num) fin = mitad - 1;
            else {
                elems[mitad].multiplicidad++;
                return;
            }
        }
        for (int i = num_elems - 1; i >= ini; i--) elems[i + 1] = elems[i];
        elems[ini].valor = num;
        elems[ini].multiplicidad = 1;
        num_elems++;
    }
    void eliminar(int num){
        int ini = 0, fin = num_elems - 1;
        while (ini <= fin) {
            int mitad = (ini + fin) / 2;
            if (elems[mitad].valor < num) ini = mitad + 1;
            else if (elems[mitad].valor > num) fin = mitad - 1;
            else {
                elems[mitad].multiplicidad--;
                if (elems[mitad].multiplicidad == 0) {
                    for (int i = mitad; i < num_elems - 1; i++) elems[i] = elems[i + 1];
                    num_elems--;
                }
                return;
            }
        }
    }
    bool pertenece(int num) const{
        int ini = 0, fin = num_elems - 1;
        while (ini <= fin) {
            int mitad = (ini + fin) / 2;
            if (elems[mitad].valor < num) ini = mitad + 1;
            else if (elems[mitad].valor > num) fin = mitad - 1;
            else return true;
        }
        return false;
    }

private:
    struct Elem
    {
        int valor;
        int multiplicidad;
    };
    Elem elems[MAX_ELEMS];
    int num_elems;
};