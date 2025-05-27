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

class Hospital {
    private:

    struct tMedico {
        list<string> pacientes;
        unordered_map<string, set<string>::iterator> iteradores_pacientes;
    };

    struct tPaciente {
        unordered_map<string, list<string>::iterator> iteradores_medicos;
        set<string> medicos;
    };

    unordered_map<string, tMedico> medicos;
    unordered_map<string, tPaciente> pacientes;

    public:

    void altaMedico(string medico){
        auto it = medicos.find(medico);
        if (it != medicos.end()){
            throw domain_error("Medico existente");
        }
        tMedico m;
        medicos[medico] = m;
    }

    void pedirConsulta(string paciente, string medico){
        auto itM = medicos.find(medico);
        if (itM == medicos.end()){
            throw domain_error("Medico inexistente");
        }
        auto itP = pacientes[paciente].iteradores_medicos.find(medico);
        if (itP != pacientes[paciente].iteradores_medicos.end()){
            throw domain_error("Paciente ya esperando");
        }
        itM->second.pacientes.push_back(paciente);
        auto itAnadir = itM->second.pacientes.end();
        itAnadir--;
        pacientes[paciente].iteradores_medicos[medico] = itAnadir;
        auto itAnadirM = pacientes[paciente].medicos.insert(medico);
        itM->second.iteradores_pacientes[paciente] = itAnadirM.first;
    }

    string siguientePaciente(string medico){
        auto itM = medicos.find(medico);
        if (itM == medicos.end()){
            throw domain_error("Medico inexistente");
        }
        if (itM->second.pacientes.empty()){
            throw domain_error("Medico sin pacientes");
        }
        return itM->second.pacientes.front();
    }

    void atenderConsulta(string medico){
        auto itM = medicos.find(medico);
        if (itM == medicos.end()){
            throw domain_error("Medico inexistente");
        }
        if (itM->second.pacientes.empty()){
            throw domain_error("Medico sin pacientes");
        }
        string pac = itM->second.pacientes.front();
        itM->second.pacientes.pop_front();
        auto itSet = itM->second.iteradores_pacientes.find(pac);
        pacientes[pac].iteradores_medicos.erase(pac);
        pacientes[pac].medicos.erase(itSet->second);
        itM->second.iteradores_pacientes.erase(pac);
    }

    list<string> abandonarConsulta(string paciente){
        auto itP = pacientes.find(paciente);
        if (itP == pacientes.end()){
            throw domain_error("Pacientes inexistente");
        }
        list<string> dev;
        for (string m : itP->second.medicos){
            dev.push_back(m);
            medicos[m].iteradores_pacientes.erase(paciente);
            medicos[m].pacientes.erase(itP->second.iteradores_medicos[m]);
        }
        pacientes.erase(paciente);
        return dev;
    }

};