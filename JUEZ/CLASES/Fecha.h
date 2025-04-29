#include <iostream>
#include <string>

using namespace std;

class Fecha {
    private:
        int dia;
        int mes;
        int anio;
    public:
        Fecha(int dia, int mes, int anio);
        Fecha(const Fecha &f);
        Fecha &operator=(const Fecha &f);
        bool operator<(const Fecha &f) const;
        bool operator>(const Fecha &f) const;
        bool operator==(const Fecha &f) const;
        bool operator<=(const Fecha &f) const;
        bool operator>=(const Fecha &f) const;
        int getDia() const;
        int getMes() const;
        int getAnio() const;
        void setDia(int dia);
        void setMes(int mes);
        void setAnio(int anio);
        void print() const;
};

Fecha::Fecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

Fecha::Fecha(const Fecha &f) {
    this->dia = f.dia;
    this->mes = f.mes;
    this->anio = f.anio;
}

Fecha &Fecha::operator=(const Fecha &f) {
    if (this != &f) {
        this->dia = f.dia;
        this->mes = f.mes;
        this->anio = f.anio;
    }
    return *this;
}

bool Fecha::operator<(const Fecha &f) const {
    if (this->anio < f.anio) {
        return true;
    } else if (this->anio == f.anio) {
        if (this->mes < f.mes) {
            return true;
        } else if (this->mes == f.mes) {
            if (this->dia < f.dia) {
                return true;
            }
        }
    }
    return false;
}

bool Fecha::operator>(const Fecha &f) const {
    if (this->anio > f.anio) {
        return true;
    } else if (this->anio == f.anio) {
        if (this->mes > f.mes) {
            return true;
        } else if (this->mes == f.mes) {
            if (this->dia > f.dia) {
                return true;
            }
        }
    }
    return false;
}

bool Fecha::operator==(const Fecha &f) const {
    return this->anio == f.anio && this->mes == f.mes && this->dia == f.dia;
}

bool Fecha::operator<=(const Fecha &f) const {
    return *this < f || *this == f;
}

bool Fecha::operator>=(const Fecha &f) const {
    return *this > f || *this == f;
}

int Fecha::getDia() const {
    return this->dia;
}

int Fecha::getMes() const {
    return this->mes;
}

int Fecha::getAnio() const {
    return this->anio;
}

void Fecha::setDia(int dia) {
    this->dia = dia;
}

void Fecha::setMes(int mes) {
    this->mes = mes;
}

void Fecha::setAnio(int anio) {
    this->anio = anio;
}

void Fecha::print() const {
    cout << this->dia << "/" << this->mes << "/" << this->anio << endl;
}

// Operadores << y >>

ostream &operator<<(ostream &os, const Fecha &f) {
    os << f.getDia() << "/" << f.getMes() << "/" << f.getAnio();
    return os;
}

istream &operator>>(istream &is, Fecha &f) {
    int dia, mes, anio;
    is >> dia >> mes >> anio;
    f.setDia(dia);
    f.setMes(mes);
    f.setAnio(anio);
    return is;
}