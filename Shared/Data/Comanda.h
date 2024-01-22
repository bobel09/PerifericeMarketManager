#ifndef _COMANDA_H_
#define _COMANDA_H_

#include "Comanda.h"
#include <bits/stdc++.h>
#include "Produs.h"
#include "Data.h"

class Comanda
{
    std::vector<Produs> produse;
    Data data;
public:
    Comanda(std::vector<Produs> produse = {}, Data data = Data());
    Comanda(const Comanda& other);
    Comanda& operator=(const Comanda& other);
    ~Comanda();

    std::vector<Produs> getProduse() const;
    Data getData() const;

    void setProduse(std::vector<Produs> produse);
    void setData(Data data);

    friend std::istream& operator>>(std::istream& in, Comanda& comanda);
    friend std::ostream& operator<<(std::ostream& out, const Comanda& comanda);
};
#endif