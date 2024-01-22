#ifndef _PRODUS_H_
#define _PRODUS_H_

#include <string>
#include <iostream>

class Produs
{
    std::string codDeBare;
    std::string denumire;
    int cantitate;
    double pret;
public:
    Produs(std::string codDeBare = "", std::string denumire = "", int cantitate = 0, double pret = 0);
    Produs(const Produs& other);
    Produs& operator=(const Produs& other);

    std::string getCodDeBare() const;
    std::string getDenumire() const;
    int getCantitate() const;
    double getPret() const;

    void setCodDeBare(std::string codDeBare);
    void setDenumire(std::string denumire);
    void setCantitate(int cantitate);
    void setPret(double pret);

    friend std::istream& operator>>(std::istream& in, Produs& produs);
    friend std::ostream& operator<<(std::ostream& out, const Produs& produs);
};

#endif // _PRODUS_H_
