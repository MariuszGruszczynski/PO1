#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Pracownik {
protected:
    string imie;
    string nazwisko;
    string nip;
    string dataUr;
    string dzial;
    int pensja;

public:
    Pracownik() = delete;

    Pracownik(string imie, string nazwisko, string nip, string dataUr, string dzial, int pensja):
        imie(imie),
        nazwisko(nazwisko),
        nip(nip),
        dataUr(dataUr),
        dzial(dzial),
        pensja(pensja) {

    }

    virtual ~Pracownik() {

    }

    virtual void display();
};

void Pracownik::display() {
    cout << imie << " " << nazwisko << " nip: " << nip << " data: " << dataUr << " dzial: " << dzial << " pensja: " << pensja;
}

class Kierownik : public Pracownik {
protected:
    string typKierownictwa;
    int dodatek; //wyrazony w %
    int iloscPodwladnych;

public:
    Kierownik() = delete;

    Kierownik(string imie, string nazwisko, string nip, string dataUr, string dzial, int pensja, string typKierownictwa, int dodatek, int iloscPodwladnych):
        Pracownik(imie, nazwisko, nip, dataUr, dzial, pensja),
        typKierownictwa(typKierownictwa),
        dodatek(dodatek),
        iloscPodwladnych(iloscPodwladnych) {

    }

    virtual ~Kierownik() {

    }

    virtual void display() override;
};

void Kierownik::display() {
    Pracownik::display();
    cout << " typ kierownictwa: " << typKierownictwa << " dodatek: " << dodatek << " ilosc podwladnych: " << iloscPodwladnych;
}

class Resistor {
    double res;

public:
    Resistor():
        res(0) {

    }

    Resistor(double res):
        res(res) {

    }

    double r() const;
    void r(double);

    friend Resistor operator+(const Resistor&, const Resistor&);
    friend Resistor operator*(const Resistor&, const Resistor&);
    friend ostream& operator<<(ostream&, const Resistor&);
};

double Resistor::r() const {
    return res;
}

void Resistor::r(double r) {
    res = r;
}

Resistor operator+(const Resistor& r1, const Resistor& r2) {
    Resistor ret(r1.r() + r2.r());

    return ret;
}

Resistor operator*(const Resistor& r1, const Resistor& r2) {
    Resistor ret((r1.r() + r2.r()) / (r1.r() * r2.r()));

    return ret;
}

ostream& operator<<(ostream& os, const Resistor& res) {
    os << res.r();
    return os;
}

int main() {
    //zad 2



    //zad 3
    Resistor r1(5), r2(8);

    Resistor r3 = r1 + r2;

    cout << r3 << endl;

    r3 = r1 * r2;

    cout << r3 << endl;

    return 0;
}
