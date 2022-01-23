#include <iostream>
#include <cstdlib>
#include <cstdio>

using std::cout;
using std::endl;
using std::ostream;

class Kondensator {
private:
    double poj;

public:
    Kondensator() : poj(0) {
    }

    Kondensator(double poj) : poj(poj) {
    }

    double pojemnosc() {
        return poj;
    }

    void pojemnosc(double p) {
        poj = p;
    }

    friend Kondensator operator+(const Kondensator &, const Kondensator &);
    friend Kondensator operator*(const Kondensator &, const Kondensator &);
    friend ostream &operator<<(ostream &, const Kondensator &);
};

ostream &operator<<(ostream &os, const Kondensator &k) {
    os << "Kondensator o pojemnosci: " << k.poj << endl;
    return os;
}

Kondensator operator+(const Kondensator &k1, const Kondensator &k2) { // + czyli szeregowy czyli dodawanie odwrotnosci
    double reverseC = (1.0 / k1.poj) + (1.0 / k2.poj);
    double C = 1.0 / reverseC;

    Kondensator k(C);

    return k;
}

Kondensator operator*(const Kondensator &k1, const Kondensator &k2) { // * czyli rownolegly czyli zwykle dodawanie
    Kondensator k(k1.poj + k2.poj);
    return k;
}

int main() {
    Kondensator k1(4), k2(5), k3(6), k4(7);
    Kondensator kMnozenie = k1 * k2 * k3 * k4;
    Kondensator kDodawanie = k1 + k2 + k3 + k4;

    cout << kMnozenie;  //mnozenie, laczenie rownolegle
    cout << kDodawanie; //dodawanie, laczenie szeregowe

    return 0;
}
