#include "Data.h"
#include <bits/stdc++.h>


Data::Data() {
    zi = 1;
    luna = 1;
    an = 2003;
}

Data::Data(const int& zi, const int& luna, const int& an) {
    this->zi = zi;
    this->luna = luna;
    this->an = an;
}

Data::Data(const char* data) {
    char temp[11];
    strcpy(temp, data);
    char* token = strtok(temp, "/");
    this->zi = atoi(token);
    token = strtok(NULL, "/");
    this->luna = atoi(token);
    token = strtok(NULL, "/");
    this->an = atoi(token);
}

Data::Data(const Data& data) {
    this->zi = data.zi;
    this->luna = data.luna;
    this->an = data.an;
}

int Data::getZi() const { return zi; }

int Data::getLuna() const { return luna; }

int Data::getAn() const { return an; }

char* Data::getData() const {
    char* data = new char[11];
    sprintf(data, "%02d/%02d/%04d", zi, luna, an);
    return data;
}

int Data::compareDates(const Data& data1, const Data& data2) const {
    int result = 1;

    if (data1.an < data2.an)
        result = -1;
    else if (data1.an == data2.an) {
        if (data1.luna < data2.luna)
            result = -1;
        else if (data1.luna == data2.luna) {
            if (data1.zi < data2.zi)
                result = -1;
            else if (data1.zi == data2.zi) 
                result = 0;
        }
    }

    return result;
}

int Data::operator[](const int& index) const {
    switch (index) {
        case 0:
            return zi;
        case 1:
            return luna;
        case 2:
            return an;
        default:
            return -1;
    }
}

void Data::operator+=(const int& nrZile) {
    zi += nrZile;
    while (zi > 31) {
        zi -= 31;
        ++luna;
        if (luna > 12) {
            luna -= 12;
            ++an;
        }
    }
}

void Data::operator-=(const int& nrZile) {
    zi -= nrZile;
    while (zi < 1) {
        zi += 31;
        --luna;
        if (luna < 1) {
            luna += 12;
            --an;
        }
    }
}

void Data::operator=(const Data& data) {
    this->zi = data.zi;
    this->luna = data.luna;
    this->an = data.an;
}

void Data::operator=(const char* data) {
    char temp[11];
    strcpy(temp, data);
    char* token = strtok(temp, "/");
    this->zi = atoi(token);
    token = strtok(NULL, "/");
    this->luna = atoi(token);
    token = strtok(NULL, "/");
    this->an = atoi(token);
}

std::ostream& operator<<(std::ostream& out, const Data& data) {
    char buffer[11];
    sprintf(buffer, "%02d/%02d/%04d", data.zi, data.luna, data.an);
    out << buffer;
    return out;
}

std::istream& operator>>(std::istream& in, Data& data) {
    char* buffer = new char[11];
    in >> buffer;
    data = buffer;
    delete[] buffer;
    return in;
}

bool Data::operator==(const Data& data) const {
    return (zi == data.zi && luna == data.luna && an == data.an);
}

bool Data::operator!=(const Data& data) const {
    return (zi != data.zi || luna != data.luna || an != data.an);
}

bool Data::operator<(const Data& data) const {
    return (compareDates(*this, data) == -1);
}

bool Data::operator>(const Data& data) const {
    return (compareDates(*this, data) == 1);
}

Data::operator char*() {
    char* data = new char[11];
    sprintf(data, "%02d/%02d/%04d", zi, luna, an);
    return data;
}