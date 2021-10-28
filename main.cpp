#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

class Klasa {
private:
    int x;
    int y;
    int z;

public:
    Klasa() {
        setX(0);
        setY(0);
        setZ(0);
        puts("konstruktor domyslny");
    }

    Klasa(int x) {
        setX(x);
        setY(0);
        setZ(0);
        printf("konstruktor z jednym argumentem x = %d\n", getX());
    }

    Klasa(int x, int y) {
        setX(x);
        setY(y);
        setZ(0);
        printf("konstruktor z dwoma argumentami x = %d y = %d\n", getX(), getY());
    }

    Klasa(int x, int y, int z) {
        setX(x);
        setY(y);
        setZ(z);
        printf("konstruktor z trzema argumentami x = %d y = %d z = %d\n", getX(), getY(), getZ());
    }

    Klasa(const Klasa& k) {
        puts("konstruktor kopiujacy");
        setX(k.getX());
        setY(k.getY());
        setZ(k.getZ());
    }

    int getX() const;
    int getY() const;
    int getZ() const;
    void setX(int x);
    void setY(int y);
    void setZ(int z);
};

void Klasa::setX(int x) {
    this->x = x;
}

void Klasa::setY(int y) {
    this->y = y;
}

void Klasa::setZ(int z) {
    this->z = z;
}


int Klasa::getX() const {
    return x;
}


int Klasa::getY() const {
    return y;
}


int Klasa::getZ() const {
    return z;
}


class Pkt {
public:
    int x;
    int y;

    Pkt():
        x(0),
        y(0) {

    }

    Pkt(int x, int y):
        x(x),
        y(y) {

    }

    void set(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

class Wektor {
private:
    static int count;

public:
    Pkt pocz, kon;

    Wektor() {
        count++;
    }

    Wektor(Pkt pocz, Pkt kon):
        pocz(pocz),
        kon(kon) {
        count++;
    }

    Wektor(int poczX, int poczY, int konX, int konY) {
        pocz.x = poczX;
        pocz.y = poczY;
        kon.x = konX;
        kon.y = konY;
        count++;
    }

    ~Wektor() {
        puts("zadanie wykonane");
    }

    void dodaj(const Wektor&);
    void odejmij(const Wektor&);
    static int mnozenieSkalarne(const Wektor&, const Wektor&);
    static int getCount();
    void display();
};

void Wektor::display() {
    printf("PoczatekX: %d, PoczatekY: %d, KoniecX: %d, KoniecY: %d\n", pocz.x, pocz.y, kon.x, kon.y);
}

void Wektor::dodaj(const Wektor& w) {
    this->pocz.x += w.pocz.x;
    this->pocz.y += w.pocz.y;
    this->kon.x += w.kon.x;
    this->kon.y += w.kon.y;
}

void Wektor::odejmij(const Wektor& w) {
    this->pocz.x -= w.pocz.x;
    this->pocz.y -= w.pocz.y;
    this->kon.x -= w.kon.x;
    this->kon.y -= w.kon.y;
}

int Wektor::mnozenieSkalarne(const Wektor &a, const Wektor &b) {
    int aDlugoscX = a.kon.x - a.pocz.x;
    int aDlugoscY = a.kon.y - a.pocz.y;
    int bDlugoscX = b.kon.x - b.pocz.x;
    int bDlugoscY = b.kon.y - b.pocz.y;

    return aDlugoscX * bDlugoscX + aDlugoscY * bDlugoscY;
}

int Wektor::getCount() {
    return count;
}

int Wektor::count = 0;

int main() {
    Wektor a(2, 1, 3, 4);
    Wektor b(5, 2, 7, 5);

    a.display();
    b.display();
    a.dodaj(b);
    a.display();
    a.odejmij(b);
    a.display();
    puts("");
    printf("mnozenie skalarne: %d\n", Wektor::mnozenieSkalarne(a, b));
    printf("ile wektorow?: %d\n", Wektor::getCount());
    puts("");

    Klasa q, w(4), e(1, 4), r(5, 2, 1);
    puts("");

    Klasa t(r);
    printf("skopiowana klasa: %d %d %d\n", t.getX(), t.getY(), t.getZ());
    puts("");

    return 0;
}
