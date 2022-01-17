#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <fstream>
#include <string>
#include <time.h>

#define M_PI 3.14159265358979323846

using std::cout;
using std::endl;
using std::string;
using std::fstream;

class TestTime {
private:
    string path;

public:
    TestTime(string path):
        path(path) {

    }

    virtual ~TestTime() {

    }

    int odczyt();
    virtual int odczytVirtual();
};

class TestTime2: public TestTime {
public:
    TestTime2(string path):
        TestTime(path) {

    }

    virtual ~TestTime2() {

    }
};


int TestTime::odczyt() {
    fstream plik;
    plik.open(path.c_str(), std::ios::in);

    if(!plik.is_open())
        return 0;

    string napis;

    while(!plik.eof()) {
        getline( plik, napis );
        cout << napis << endl;
    }

    plik.close();

    return 1;
}

int TestTime::odczytVirtual() {
    fstream plik;
    plik.open(path.c_str(), std::ios::in);

    if(!plik.is_open())
        return 0;

    string napis;

    while(!plik.eof()) {
        getline( plik, napis );
        cout << napis << endl;
    }

    plik.close();

    return 1;
}


int main() {
    TestTime2 t("input.txt");

    clock_t start, end;
    clock_t startVirtual, endVirtual;
    double cpu_time_used, cpu_time_used_virtual;

    start = clock();
    t.odczyt();
    end = clock();

    startVirtual = clock();
    t.odczytVirtual();
    endVirtual = clock();

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    cout << endl << "czas potrzebny dla funkcji niewirtualnej: " << cpu_time_used << endl;

    cpu_time_used_virtual = ((double) (endVirtual - startVirtual)) / CLOCKS_PER_SEC;
    cout << "czas potrzebny dla funkcji wirtualnej: " << cpu_time_used_virtual << endl << endl;

    if(cpu_time_used < cpu_time_used_virtual)
        puts("wiecej czasu zajela funkcja wirtualna");
    else
        puts("wiecej czasu zajela funkcja niewirtualna");

    return 0;
}
