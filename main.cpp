#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Osoba {
protected:
    string imie, nazwisko, dataUr;

public:
    Osoba() = delete;

    Osoba(string imie, string nazwisko, string dataUr):
        imie(imie),
        nazwisko(nazwisko),
        dataUr(dataUr) {

    }

    virtual void wypiszInfo() {
        printf("%s %s, urodzony/a: %s", imie.c_str(), nazwisko.c_str(), dataUr.c_str());
    }

    virtual ~Osoba() {

    }
};

class Student : public Osoba {
protected:
    unsigned int rok, grupa, nrIndeksu;

public:
    Student() = delete;

    Student(string imie, string nazwisko, string dataUr, unsigned int rok, unsigned int grupa, unsigned int nrIndeksu):
        Osoba(imie, nazwisko, dataUr),
        rok(rok),
        grupa(grupa),
        nrIndeksu(nrIndeksu) {

    }

    virtual void wypiszInfo() {
        Osoba::wypiszInfo();
        printf(", student, rok studiow: %d, grupa: %d, numer indeksu: %d\n", rok, grupa, nrIndeksu);
    }
};

class Pilkarz : public Osoba {
protected:
    string pozycja, klub;
    unsigned int liczbaGoli;
public:
    Pilkarz() = delete;

    Pilkarz(string imie, string nazwisko, string dataUr, string pozycja, string klub):
        Osoba(imie, nazwisko, dataUr),
        pozycja(pozycja),
        klub(klub),
        liczbaGoli(0) {

    }

    virtual void wypiszInfo() {
        Osoba::wypiszInfo();
        printf(", pilkarz, klub: %s, pozycja: %s, liczba goli: %u\n", klub.c_str(), pozycja.c_str(), liczbaGoli);
    }

    void strzelGola() {
        liczbaGoli++;
    }
};

class Pracownik {
protected:
    string imie, nazwisko, nip, dataZatr, dzial;
    int pensja;

public:
    Pracownik(string imie, string nazwisko, string nip, string dataZatr, string dzial, int pensja) : imie(imie),
        nazwisko(nazwisko),
        nip(nip),
        dataZatr(dataZatr),
        dzial(dzial),
        pensja(pensja) {
    }

    virtual void display() const {
        printf("%s %s, nip: %s, data zatrudnienia %s, dzial: %s, pensja: %d", imie.c_str(), nazwisko.c_str(), nip.c_str(), dataZatr.c_str(), dzial.c_str(), pensja);
    }
};

class Kierownik : public Pracownik {
protected:
    string typKier;
    int iloscPodw, dodFunk /*wyrazony w % */;

public:
    Kierownik(string imie, string nazwisko, string nip, string dataZatr, string dzial, string typKier, int pensja, int iloscPodw, int dodFunk) : Pracownik(imie, nazwisko, nip, dataZatr, dzial, pensja),
        typKier(typKier),
        iloscPodw(iloscPodw),
        dodFunk(dodFunk) {
    }

    virtual void display() const {
        Pracownik::display();
        printf(" + dodatek funkcyjny %d%%, typ kierownictwa: %s, ilosc podwladnych: %d", dodFunk, typKier.c_str(), iloscPodw);
    }

    void przyjmijPracownika(const Pracownik &prac) {
        printf("Przyjeto pracownika! Dane pracownika: ");
        prac.display();
    }
};

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
    //zad 1
    puts("ZADANIE 1 ZADANIE 1 ZADANIE 1 ZADANIE 1 ZADANIE 1");
    Pracownik prac("Maciej", "Iksinski", "825962398562", "10.10.2020", "marketing", 1800);
    prac.display();

    puts("\n");
    Kierownik kier("Filip", "Matusiak", "962598525", "20.09.2018", "marketing", "kierownik marketingu", 2300, 4, 10);
    kier.display();

    puts("\n");
    kier.przyjmijPracownika(prac);
    puts("");

    //zad 2
    puts("\nZADANIE 2 ZADANIE 2 ZADANIE 2 ZADANIE 2 ZADANIE 2");
    Osoba *student = new Student("Zbigniew", "Mach", "20.10.1998", 3, 2, 214523);
    Osoba *pilkarz = new Pilkarz("Marcin", "Zuch", "19.11.1996", "obronca", "Pisia Zygry");

    student->wypiszInfo();
    pilkarz->wypiszInfo();

    Pilkarz *pilkarz_cast = (Pilkarz*) pilkarz;
    pilkarz_cast->strzelGola();

    pilkarz->wypiszInfo();

    delete student;
    delete pilkarz;
    //zad 3
    puts("\n\nZADANIE 3 ZADANIE 3 ZADANIE 3 ZADANIE 3 ZADANIE 3");
    Resistor r1(5), r2(8);

    Resistor r3 = r1 + r2;

    cout << r3 << endl;

    r3 = r1 * r2;

    cout << r3 << endl;

    return 0;
}
