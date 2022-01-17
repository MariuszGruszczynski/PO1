#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <bitset>

using std::cout;
using std::cin;
using std::endl;
using std::string;

char znakSzesnastkowy(int liczba);

class Liczba {
protected:
    string liczba;
    class WrongCharacterEntered {} wrongCharacterEntered;
public:
    Liczba() {
        liczba = "0";
    }
    virtual ~Liczba() {}

    virtual void wyswietl() = 0;
    virtual int pobierz() = 0;

    friend class LiczbaDwojkowa;
    friend class LiczbaOsemkowa;
    friend class LiczbaSzesnastkowa;
};

class LiczbaDziesietna: public Liczba {
public:
    LiczbaDziesietna() {}
    virtual ~LiczbaDziesietna() {}

    virtual void wyswietl();
    virtual int pobierz();
    string naDwojkowy();
    string naOsemkowy();
    string naSzesnastkowy();

    static LiczbaDziesietna dodaj(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2);
    static LiczbaDziesietna odejmij(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2);
    static LiczbaDziesietna pomnoz(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2);
    static LiczbaDziesietna podziel(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2);
};

class LiczbaDwojkowa: public Liczba {
public:
    LiczbaDwojkowa() {}
    virtual ~LiczbaDwojkowa() {}

    virtual void wyswietl();
    virtual int pobierz();
    string naDziesietny();
    string naOsemkowy();
    string naSzesnastkowy();

    static LiczbaDwojkowa dodaj(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2);
    static LiczbaDwojkowa odejmij(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2);
    static LiczbaDwojkowa pomnoz(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2);
    static LiczbaDwojkowa podziel(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2);
};

class LiczbaOsemkowa: public Liczba {
public:
    LiczbaOsemkowa() {}
    virtual ~LiczbaOsemkowa() {}

    virtual void wyswietl();
    virtual int pobierz();
    string naDziesietny();
    string naDwojkowy();
    string naSzesnastkowy();

    static LiczbaOsemkowa dodaj(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2);
    static LiczbaOsemkowa odejmij(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2);
    static LiczbaOsemkowa pomnoz(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2);
    static LiczbaOsemkowa podziel(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2);
};

class LiczbaSzesnastkowa: public Liczba {
public:
    LiczbaSzesnastkowa() {}
    virtual ~LiczbaSzesnastkowa() {}

    virtual void wyswietl();
    virtual int pobierz();
    string naDziesietny();
    string naDwojkowy();
    string naOsemkowy();

    static LiczbaSzesnastkowa dodaj(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2);
    static LiczbaSzesnastkowa odejmij(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2);
    static LiczbaSzesnastkowa pomnoz(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2);
    static LiczbaSzesnastkowa podziel(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2);
};

int main() {
    cout << "SYSTEM BINARNY" << endl;
    LiczbaDwojkowa dwojkowa;
    dwojkowa.pobierz();
    dwojkowa.wyswietl();

    cout << "dwojkowa -> dziesietna: " << dwojkowa.naDziesietny() << endl << endl;
    cout << "dwojkowa -> osemkowa: " << dwojkowa.naOsemkowy() << endl << endl;
    cout << "dwojkowa -> szesnastkowa: " << dwojkowa.naSzesnastkowy() << endl << endl;

    LiczbaDziesietna dziesietna1;
    dziesietna1.pobierz();
    dziesietna1.wyswietl();

    cout << "dziesietna -> dwojkowa: " << dziesietna1.naDwojkowy() << endl;

    cout << endl << "SYSTEM OSEMKOWY" << endl;

    LiczbaOsemkowa osemkowa;
    osemkowa.pobierz();
    osemkowa.wyswietl();

    cout << "osemkowa -> dziesietna: " << osemkowa.naDziesietny() << endl << endl;
    cout << "osemkowa -> dwojkowa: " << osemkowa.naDwojkowy() << endl << endl;
    cout << "osemkowa -> szesnastkowa: " << osemkowa.naSzesnastkowy() << endl << endl;

    LiczbaDziesietna dziesietna2;
    dziesietna2.pobierz();
    dziesietna2.wyswietl();

    cout << "dziesietna -> osemkowa: " << dziesietna2.naOsemkowy() << endl;

    cout << endl << "SYSTEM SZESNASTKOWY" << endl;

    LiczbaSzesnastkowa szesnastkowa;
    szesnastkowa.pobierz();
    szesnastkowa.wyswietl();

    cout << "szesnastkowa -> dziesietna: " << szesnastkowa.naDziesietny() << endl << endl;
    cout << "szesnastkowa -> dwojkowa: " << szesnastkowa.naDwojkowy() << endl << endl;
    cout << "szesnastkowa -> osemkowa: " << szesnastkowa.naOsemkowy() << endl << endl;

    LiczbaDziesietna dziesietna3;
    dziesietna3.pobierz();
    dziesietna3.wyswietl();

    cout << "dziesietna -> szesnastkowa: " << dziesietna3.naSzesnastkowy() << endl;

    cout << endl << "TEST OPERACJI ARYTMETYCZNYCH" << endl << endl;

    {
        LiczbaDziesietna l1, l2;
        l1.pobierz();
        l2.pobierz();
        cout << endl;
        cout << "SUMA: ";
        LiczbaDziesietna::dodaj(l1, l2).wyswietl();
        cout << "ROZNICA: ";
        LiczbaDziesietna::odejmij(l1, l2).wyswietl();
        cout << "ILOCZYN: ";
        LiczbaDziesietna::pomnoz(l1, l2).wyswietl();
        cout << "ILORAZ: ";
        LiczbaDziesietna::podziel(l1, l2).wyswietl();
    }

    cout << endl;

    {
        LiczbaDwojkowa l1, l2;
        l1.pobierz();
        l2.pobierz();
        cout << endl;
        cout << "SUMA: ";
        LiczbaDwojkowa::dodaj(l1, l2).wyswietl();
        cout << "ROZNICA: ";
        LiczbaDwojkowa::odejmij(l1, l2).wyswietl();
        cout << "ILOCZYN: ";
        LiczbaDwojkowa::pomnoz(l1, l2).wyswietl();
        cout << "ILORAZ: ";
        LiczbaDwojkowa::podziel(l1, l2).wyswietl();
    }

    cout << endl;

    {
        LiczbaOsemkowa l1, l2;
        l1.pobierz();
        l2.pobierz();
        cout << endl;
        cout << "SUMA: ";
        LiczbaOsemkowa::dodaj(l1, l2).wyswietl();
        cout << "ROZNICA: ";
        LiczbaOsemkowa::odejmij(l1, l2).wyswietl();
        cout << "ILOCZYN: ";
        LiczbaOsemkowa::pomnoz(l1, l2).wyswietl();
        cout << "ILORAZ: ";
        LiczbaOsemkowa::podziel(l1, l2).wyswietl();
    }

    cout << endl;

    {
        LiczbaSzesnastkowa l1, l2;
        l1.pobierz();
        l2.pobierz();
        cout << endl;
        cout << "SUMA: ";
        LiczbaSzesnastkowa::dodaj(l1, l2).wyswietl();
        cout << "ROZNICA: ";
        LiczbaSzesnastkowa::odejmij(l1, l2).wyswietl();
        cout << "ILOCZYN: ";
        LiczbaSzesnastkowa::pomnoz(l1, l2).wyswietl();
        cout << "ILORAZ: ";
        LiczbaSzesnastkowa::podziel(l1, l2).wyswietl();
    }

    return 0;
}

string LiczbaDwojkowa::naOsemkowy()
{
    LiczbaDziesietna ldz;
    ldz.liczba = naDziesietny();
    return ldz.naOsemkowy();
}

string LiczbaDwojkowa::naSzesnastkowy()
{
    LiczbaDziesietna ldz;
    ldz.liczba = naDziesietny();
    return ldz.naSzesnastkowy();
}

string LiczbaOsemkowa::naDwojkowy()
{
    LiczbaDziesietna ldz;
    ldz.liczba = naDziesietny();
    return ldz.naDwojkowy();
}

string LiczbaOsemkowa::naSzesnastkowy()
{
    LiczbaDziesietna ldz;
    ldz.liczba = naDziesietny();
    return ldz.naSzesnastkowy();
}

string LiczbaSzesnastkowa::naDwojkowy()
{
    LiczbaDziesietna ldz;
    ldz.liczba = naDziesietny();
    return ldz.naDwojkowy();
}

string LiczbaSzesnastkowa::naOsemkowy()
{
    LiczbaDziesietna ldz;
    ldz.liczba = naDziesietny();
    return ldz.naOsemkowy();
}


LiczbaOsemkowa LiczbaOsemkowa::dodaj(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::dodaj(_l1, _l2);
    LiczbaOsemkowa ret;
    ret.liczba = _l.naOsemkowy();

    return ret;
}

LiczbaOsemkowa LiczbaOsemkowa::odejmij(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::odejmij(_l1, _l2);
    LiczbaOsemkowa ret;
    ret.liczba = _l.naOsemkowy();

    return ret;
}

LiczbaOsemkowa LiczbaOsemkowa::pomnoz(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::pomnoz(_l1, _l2);
    LiczbaOsemkowa ret;
    ret.liczba = _l.naOsemkowy();

    return ret;
}

LiczbaOsemkowa LiczbaOsemkowa::podziel(LiczbaOsemkowa& l1, LiczbaOsemkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::podziel(_l1, _l2);
    LiczbaOsemkowa ret;
    ret.liczba = _l.naOsemkowy();

    return ret;
}

LiczbaSzesnastkowa LiczbaSzesnastkowa::dodaj(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::dodaj(_l1, _l2);
    LiczbaSzesnastkowa ret;
    ret.liczba = _l.naSzesnastkowy();

    return ret;
}

LiczbaSzesnastkowa LiczbaSzesnastkowa::odejmij(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::odejmij(_l1, _l2);
    LiczbaSzesnastkowa ret;
    ret.liczba = _l.naSzesnastkowy();

    return ret;
}

LiczbaSzesnastkowa LiczbaSzesnastkowa::pomnoz(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::pomnoz(_l1, _l2);
    LiczbaSzesnastkowa ret;
    ret.liczba = _l.naSzesnastkowy();

    return ret;
}

LiczbaSzesnastkowa LiczbaSzesnastkowa::podziel(LiczbaSzesnastkowa& l1, LiczbaSzesnastkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::podziel(_l1, _l2);
    LiczbaSzesnastkowa ret;
    ret.liczba = _l.naSzesnastkowy();

    return ret;
}


LiczbaDwojkowa LiczbaDwojkowa::dodaj(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::dodaj(_l1, _l2);
    LiczbaDwojkowa ret;
    ret.liczba = _l.naDwojkowy();

    return ret;
}

LiczbaDwojkowa LiczbaDwojkowa::odejmij(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::odejmij(_l1, _l2);
    LiczbaDwojkowa ret;
    ret.liczba = _l.naDwojkowy();

    return ret;
}

LiczbaDwojkowa LiczbaDwojkowa::pomnoz(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::pomnoz(_l1, _l2);
    LiczbaDwojkowa ret;
    ret.liczba = _l.naDwojkowy();

    return ret;
}

LiczbaDwojkowa LiczbaDwojkowa::podziel(LiczbaDwojkowa& l1, LiczbaDwojkowa& l2) {
    LiczbaDziesietna _l1, _l2;
    _l1.liczba = l1.naDziesietny();
    _l2.liczba = l2.naDziesietny();

    LiczbaDziesietna _l = LiczbaDziesietna::podziel(_l1, _l2);
    LiczbaDwojkowa ret;
    ret.liczba = _l.naDwojkowy();

    return ret;
}


LiczbaDziesietna LiczbaDziesietna::dodaj(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2) {
    LiczbaDziesietna ret;

    long long _l1 = stoll(l1.liczba);
    long long _l2 = stoll(l2.liczba);
    ret.liczba = std::to_string(_l1 + _l2);
    return ret;
}

LiczbaDziesietna LiczbaDziesietna::odejmij(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2) {
    LiczbaDziesietna ret;

    long long _l1 = stoll(l1.liczba);
    long long _l2 = stoll(l2.liczba);
    ret.liczba = std::to_string(_l1 - _l2);
    return ret;
}

LiczbaDziesietna LiczbaDziesietna::pomnoz(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2) {
    LiczbaDziesietna ret;

    long long _l1 = stoll(l1.liczba);
    long long _l2 = stoll(l2.liczba);
    ret.liczba = std::to_string(_l1 * _l2);
    return ret;
}

LiczbaDziesietna LiczbaDziesietna::podziel(const LiczbaDziesietna& l1, const LiczbaDziesietna& l2) {
    LiczbaDziesietna ret;

    long long _l1 = stoll(l1.liczba);
    long long _l2 = stoll(l2.liczba);
    ret.liczba = std::to_string(_l1 / _l2);
    return ret;
}

string LiczbaDziesietna::naSzesnastkowy() {
    long long _liczba = std::stoll(liczba);

    int _znakSzesnastkowy = _liczba % 16;
    long long wynikDziel = _liczba / 16;

    string ret = "";
    ret = znakSzesnastkowy(_znakSzesnastkowy);

    while(wynikDziel > 0) {
        int reszta = wynikDziel % 16;
        ret = znakSzesnastkowy(reszta) + ret;
        wynikDziel = wynikDziel / 16;
    }

    return ret;
}


void LiczbaSzesnastkowa::wyswietl() {
    cout << "Liczba szesnastkowa o wartosci: " << liczba << endl;
}

int LiczbaSzesnastkowa::pobierz() {
    while(1) {
        try {
            cout << "Wprowadz liczbe szesnastkowa: ";
            cin >> liczba;

            for(char c : liczba) {
                if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7'
                        || c == '8' || c == '9' || c == 'A' || c == 'a' || c == 'B' || c == 'b' || c == 'C' || c == 'c'
                        || c == 'D' || c == 'd' || c == 'E' || c == 'e' || c == 'F' || c == 'f') { //OK

                } else { //nie OK
                    liczba = "0";
                    throw wrongCharacterEntered;
                }
            }

            break;
        } catch(WrongCharacterEntered& e) {
            cout << "zle podano liczbe, sprobuj ponownie" << endl;
        }
    }

    return 1;
}

string LiczbaSzesnastkowa::naDziesietny() {
    long long _liczba = 0;

    for(unsigned int i = 0; i < liczba.length(); i++) {
        int zeroDoPietnascie = 0;

        switch(liczba[liczba.length() - 1 - i]) {
        case '0':
            zeroDoPietnascie = 0;
            break;
        case '1':
            zeroDoPietnascie = 1;
            break;
        case '2':
            zeroDoPietnascie = 2;
            break;
        case '3':
            zeroDoPietnascie = 3;
            break;
        case '4':
            zeroDoPietnascie = 4;
            break;
        case '5':
            zeroDoPietnascie = 5;
            break;
        case '6':
            zeroDoPietnascie = 6;
            break;
        case '7':
            zeroDoPietnascie = 7;
            break;
        case '8':
            zeroDoPietnascie = 8;
            break;
        case '9':
            zeroDoPietnascie = 9;
            break;
        case 'A':
            zeroDoPietnascie = 10;
            break;
        case 'a':
            zeroDoPietnascie = 10;
            break;
        case 'B':
            zeroDoPietnascie = 11;
            break;
        case 'b':
            zeroDoPietnascie = 11;
            break;
        case 'C':
            zeroDoPietnascie = 12;
            break;
        case 'c':
            zeroDoPietnascie = 12;
            break;
        case 'D':
            zeroDoPietnascie = 13;
            break;
        case 'd':
            zeroDoPietnascie = 13;
            break;
        case 'E':
            zeroDoPietnascie = 14;
            break;
        case 'e':
            zeroDoPietnascie = 14;
            break;
        case 'F':
            zeroDoPietnascie = 15;
            break;
        case 'f':
            zeroDoPietnascie = 15;
            break;
        }

        _liczba += zeroDoPietnascie * pow(16, i);
    }

    return std::to_string(_liczba);
}


string LiczbaDziesietna::naOsemkowy() {
    long long _liczba = std::stoll(liczba);

    string ret = std::to_string(_liczba % 8);
    long long wynikDziel = _liczba / 8;

    while(wynikDziel > 0) {
        int reszta = wynikDziel % 8;
        ret = std::to_string(reszta) + ret;
        wynikDziel = wynikDziel / 8;
    }

    return ret;
}

void LiczbaOsemkowa::wyswietl() {
    cout << "Liczba osemkowa o wartosci: " << liczba << endl;
}

int LiczbaOsemkowa::pobierz() {
    while(1) {
        try {
            cout << "Wprowadz liczbe osemkowa: ";
            cin >> liczba;

            for(char c : liczba) {
                if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7') { //OK

                } else { //nie OK
                    liczba = "0";
                    throw wrongCharacterEntered;
                }
            }

            break;
        } catch(WrongCharacterEntered& e) {
            cout << "zle podano liczbe, sprobuj ponownie" << endl;
        }
    }

    return 1;
}

string LiczbaOsemkowa::naDziesietny() {
    long long _liczba = 0;

    for(unsigned int i = 0; i < liczba.length(); i++) {
        int zeroDoOsiem = liczba[liczba.length() - 1 - i] - '0';
        _liczba += zeroDoOsiem * pow(8, i);
    }

    return std::to_string(_liczba);
}


void LiczbaDziesietna::wyswietl() {
    cout << "Liczba dziesietna o wartosci: " << liczba << endl;
}

int LiczbaDziesietna::pobierz() {
    while(1) {
        try {
            cout << "Wprowadz liczbe dziesietna: ";
            cin >> liczba;

            for(char c : liczba) {
                if(c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9') { //OK

                } else { //nie OK
                    liczba = "0";
                    throw wrongCharacterEntered;
                }
            }

            break;
        } catch(WrongCharacterEntered& e) {
            cout << "zle podano liczbe, sprobuj ponownie" << endl;
        }
    }

    return 1;
}

string LiczbaDziesietna::naDwojkowy() {
    string str = std::bitset<64>(stoll(liczba)).to_string();

    str.erase(0, str.find_first_not_of('0'));

    return str;
}


string LiczbaDwojkowa::naDziesietny() {
    long long _liczba = 0;

    for(unsigned int i = 0; i < liczba.length(); i++) {
        int zeroCzyJeden = liczba[liczba.length() - 1 - i] - '0';
        _liczba += zeroCzyJeden * pow(2, i);
    }

    return std::to_string(_liczba);
}


void LiczbaDwojkowa::wyswietl() {
    cout << "Liczba dwojkowa o wartosci: " << liczba << endl;
}

int LiczbaDwojkowa::pobierz() {
    while(1) {
        try {
            cout << "Wprowadz liczbe binarna: ";
            cin >> liczba;

            for(char c : liczba) {
                if(c == '0' || c == '1') { //OK

                } else { //nie OK
                    liczba = "0";
                    throw wrongCharacterEntered;
                }
            }

            break;
        } catch(WrongCharacterEntered& e) {
            cout << "zle podano liczbe, sprobuj ponownie" << endl;
        }
    }

    return 1;
}

char znakSzesnastkowy(int liczba) {
    switch(liczba) {
    case 0:
        return '0';
    case 1:
        return '1';
    case 2:
        return '2';
    case 3:
        return '3';
    case 4:
        return '4';
    case 5:
        return '5';
    case 6:
        return '6';
    case 7:
        return '7';
    case 8:
        return '8';
    case 9:
        return '9';
    case 10:
        return 'A';
    case 11:
        return 'B';
    case 12:
        return 'C';
    case 13:
        return 'D';
    case 14:
        return 'E';
    case 15:
        return 'F';
    }

    return '0';
}
