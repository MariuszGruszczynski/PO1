#include <iostream>
#include <cstdlib>
#include <cstdio>

#define M_PI 3.14159265358979323846

using std::cout;
using std::endl;

class Bryla {
public:
    Bryla() {

    }
    virtual ~Bryla() {

    }

    virtual float Pole() {
        return 0;
    }
    virtual float Objetosc() {
        return 0;
    }
    virtual float Przekatna() {
        return 0;
    }
};

class Ostroslup: public Bryla { //zakladamy ze w podstawie jest wielokat foremny
private:
    int iloscKatowPodstawy;
    float dlugoscBokuPodstawy, promienOkreguWpisanego;
    float wysokoscOstroslupa, wysokoscScianyBocznej;
public:
    Ostroslup(int iloscKatowPodstawy, float dlugoscBokuPodstawy, float promienOkreguWpisanego, float wysokoscOstroslupa, float wysokoscScianyBocznej):
        Bryla(),
        iloscKatowPodstawy(iloscKatowPodstawy),
        dlugoscBokuPodstawy(dlugoscBokuPodstawy),
        promienOkreguWpisanego(promienOkreguWpisanego),
        wysokoscOstroslupa(wysokoscOstroslupa),
        wysokoscScianyBocznej(wysokoscScianyBocznej) {

    }

    virtual float Objetosc();
    virtual float Pole();
};

float Ostroslup::Objetosc() {
    float Pp = iloscKatowPodstawy * dlugoscBokuPodstawy * promienOkreguWpisanego / 2.0; // pole wielokata foremnego = nar/2

    return 1.0 / 3.0 * Pp * wysokoscOstroslupa;
}

float Ostroslup::Pole() {
    float Pp = iloscKatowPodstawy * dlugoscBokuPodstawy * promienOkreguWpisanego / 2.0; // pole wielokata foremnego = nar/2
    float poleScianyBocznej = dlugoscBokuPodstawy * wysokoscScianyBocznej / 2.0;
    float Pb = iloscKatowPodstawy * poleScianyBocznej;

    return Pp + Pb;
}


class Prostopadloscian: public Bryla {
private:
    float width, height, depth;

public:
    Prostopadloscian(float width, float height, float depth):
        Bryla(),
        width(width),
        height(height),
        depth(depth) {}

    virtual float Objetosc();
    virtual float Pole();
};

float Prostopadloscian::Objetosc() {
    return width * height * depth;
}

float Prostopadloscian::Pole() {
    return 2 * (width * height + width * depth + height * depth);
}


class Kula: public Bryla {
private:
    float r; //promien w cm

public:
    Kula(float r):
        Bryla(),
        r(r) {

    }

    virtual ~Kula() {

    }

    virtual float Pole();
    virtual float Objetosc();
};

float Kula::Pole() {
    return 4.0 * M_PI * r * r;
}

float Kula::Objetosc() {
    return 4.0 / 3.0 * M_PI * r * r * r;
}

int main() {
    Bryla *kula = new Kula(1);

    cout << "Kula: " << kula->Pole() << " cm^2 " << kula->Objetosc() << " cm^3" << endl;

    Bryla *prosto = new Prostopadloscian(5, 3, 4);

    cout << "Prostopadloscian: " << prosto->Pole() << " cm^2 " << prosto->Objetosc() << " cm^3" << endl;

    Bryla *ostro = new Ostroslup(5, 3.5, 8, 4, 3.5);

    cout << "Ostroslup: " << ostro->Pole() << " cm^2 " << ostro->Objetosc() << " cm^3" << endl;


    delete ostro;
    delete kula;
    delete prosto;

    return 0;
}
