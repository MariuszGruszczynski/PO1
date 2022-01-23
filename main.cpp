#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::exception;

//u¿ycie w³asnej klasy wyj¹tku

class MojWyjatek: public exception {
public:
    virtual const char* what() const throw() {
        return "Moj wyjatek";
    }
};

int main () {
    MojWyjatek myex;

    try {
        int x = 0, z = 0;

        cout << "podaj x, z: ";
        cin >> x >> z;

        if(!cin.good())
            throw myex;

        if(x * x - z * z < 0)
            throw myex;

        if(x - z <= 0)
            throw myex;

        float y = sqrt(x * x - z * z) / sqrt(x - z);

        printf("wynik: %f", y);
    }

    catch (const exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
