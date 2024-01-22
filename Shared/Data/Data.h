#ifndef _DATA_H_
#define _DATA_H_

#include <bits/stdc++.h>

class Data {
private:
    int zi;
    int luna;
    int an;

    int compareDates(const Data&, const Data&) const;

public:
    Data();
    Data(const int&, const int&, const int&);
    Data(const char*);
    Data(const Data&);
    ~Data() {};

    int getZi() const;
    int getLuna() const;
    int getAn() const;
    char* getData() const;

    int operator[](const int&) const;
    void operator+=(const int&);
    void operator-=(const int&);
    void operator=(const Data&);
    void operator=(const char*);
    bool operator==(const Data&) const;
    bool operator!=(const Data&) const;
    bool operator<(const Data&) const;
    bool operator>(const Data&) const;

    friend std::ostream& operator<<(std::ostream&, const Data&);
    friend std::istream& operator>>(std::istream&, Data&);

    operator char*();
};

#endif