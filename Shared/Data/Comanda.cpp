#include <bits/stdc++.h>
#include "Comanda.h"
#include "Produs.h"
#include "Data.h"


Comanda::Comanda(std::vector<Produs> produse, Data data)
{
    this->produse = produse;
    this->data = data;
}

Comanda::Comanda(const Comanda& other)
{
    this->produse = other.produse;
    this->data = other.data;
}

Comanda& Comanda::operator=(const Comanda& other)
{
    if (this != &other)
    {
        this->produse = other.produse;
        this->data = other.data;
    }
    return *this;
}

Comanda::~Comanda()
{
    this->produse.clear();
}

std::vector<Produs> Comanda::getProduse() const
{
    return this->produse;
}

Data Comanda::getData() const
{
    return this->data;
}

void Comanda::setProduse(std::vector<Produs> produse)
{
    this->produse = produse;
}

void Comanda::setData(Data data)
{
    this->data = data;
}

std::istream& operator>>(std::istream& in, Comanda& comanda)
{
    std::vector<Produs> produse;
    Data data;
    in >> data;
    int n;
    in >> n;
    for (int i = 0; i < n; i++)
    {
        Produs produs;
        in >> produs;
        produse.push_back(produs);
    }
    comanda.setData(data);
    comanda.setProduse(produse);
    return in;
}

std::ostream& operator<<(std::ostream& out, const Comanda& comanda)
{
    
    // out << comanda.getProduse().size() << "\n";
    for (auto produs : comanda.getProduse())
    {
        out << produs << "\n";
    }
    out << comanda.getData() << "\n";
    return out;
}