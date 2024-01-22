#include "Produs.h"

Produs::Produs(std::string codDeBare, std::string denumire, int cantitate, double pret)
{
    this->codDeBare = codDeBare;
    this->denumire = denumire;
    this->cantitate = cantitate;
    this->pret = pret;
}

Produs::Produs(const Produs& other)
{
    this->codDeBare = other.codDeBare;
    this->denumire = other.denumire;
    this->cantitate = other.cantitate;
    this->pret = other.pret;
}

Produs& Produs::operator=(const Produs& other)
{
    if (this != &other)
    {
        this->codDeBare = other.codDeBare;
        this->denumire = other.denumire;
        this->cantitate = other.cantitate;
        this->pret = other.pret;
    }
    return *this;
}

std::string Produs::getCodDeBare() const
{
    return this->codDeBare;
}

std::string Produs::getDenumire() const
{
    return this->denumire;
}

int Produs::getCantitate() const
{
    return this->cantitate;
}

double Produs::getPret() const
{
    return this->pret;
}

void Produs::setCodDeBare(std::string codDeBare)
{
    this->codDeBare = codDeBare;
}

void Produs::setDenumire(std::string denumire)
{
    this->denumire = denumire;
}

void Produs::setCantitate(int cantitate)
{
    this->cantitate = cantitate;
}

void Produs::setPret(double pret)
{
    this->pret = pret;
}

std::istream& operator>>(std::istream& in, Produs& produs)
{
    std::string codDeBare;
    std::string denumire;
    int cantitate;
    double pret;
    std::cout << "Cod de bare: ";
    in >> codDeBare;
    std::cout << "Denumire: ";
    std::getline(in >> std::ws, denumire);
    std::cout << "Cantitate: ";
    in >> cantitate;
    std::cout << "Pret: ";
    in >> pret;  

    produs.setCodDeBare(codDeBare);
    produs.setDenumire(denumire);
    produs.setCantitate(cantitate);
    produs.setPret(pret);

    return in;
}

std::ostream& operator<<(std::ostream& out, const Produs& produs)
{
    out << produs.codDeBare << "\n" << produs.denumire << "\n" << produs.cantitate << "\n" << produs.pret;
    return out;
}
