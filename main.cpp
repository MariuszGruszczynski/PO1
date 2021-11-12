#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Pracownik {
protected:
    string imie;
    string nazwisko;
    string nip;
    string dataZatr;
    string dzial;
    int pensja;

public:
    Pracownik() = delete;

    Pracownik(string imie, string nazwisko, string nip, string dataZatr, string dzial, int pensja):
        imie(imie),
        nazwisko(nazwisko),
        nip(nip),
        dataZatr(dataZatr),
        dzial(dzial),
        pensja(pensja) {

    }

    virtual ~Pracownik() {

    }

    virtual void infoPracownika();
};

void Pracownik::infoPracownika() {
    printf("%s %s, nip: %s, data zatrudnienia: %s, pensja: %d, dzial: %s", imie.c_str(), nazwisko.c_str(), nip.c_str(), dataZatr.c_str(), pensja, dzial.c_str());
}

class Kierownik : public Pracownik {
protected:
    string typKierownictwa;
    int dodatek; //wyrazony w %
    int iloscPodwladnych;

public:
    Kierownik() = delete;

    Kierownik(string imie, string nazwisko, string nip, string dataZatr, string dzial, int pensja, string typKierownictwa, int dodatek, int iloscPodwladnych):
        Pracownik(imie, nazwisko, nip, dataZatr, dzial, pensja),
        typKierownictwa(typKierownictwa),
        dodatek(dodatek),
        iloscPodwladnych(iloscPodwladnych) {

    }

    virtual ~Kierownik() {

    }

    void przyjmijPracownika(string, string, string, string, string, int);
    virtual void infoPracownika() override;
};

void Kierownik::przyjmijPracownika(string imie, string nazwisko, string nip, string dataZatr, string dzial, int pensja){
    Pracownik nowy(imie,nazwisko,nip,dataZatr,dzial,pensja);
    puts("przyjeto pracownika:");
    nowy.infoPracownika();
}

void Kierownik::infoPracownika() {
    printf("kierownik: ");
    Pracownik::infoPracownika();
    printf(", ilosc podwladnych: %d, dodatek funkcyjny: %d %%, typ kierownictwa: %s", iloscPodwladnych, dodatek, typKierownictwa.c_str());
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
