#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void fun() {
    float a = 0, b = 0, c = 0;
    int type = 0; //(1) - rzeczywiste, (2) - zespolone

    cout << "(1) - rzeczywiste, (2) - zespolone\n";

    while(1) {
        int temp = scanf("%d", &type);

        if(temp == 0 || (type != 1 && type != 2)) {
            char c = 0;
            scanf("%c", &c);
            cout << "error! try again: ";
        } else
            break;
    }

    cout << "podaj parametry a, b i c: ";
    do {
        cin >> a >> b >> c;

        if(cin.good())
            break;
        else {
            cout << "error! try again: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }
    } while(1);

    if(type == 1) {
        try {
            float delta = b * b - 4 * a * c;

            if(delta < 0)
                throw std::logic_error("delta mniejsza od zera");

            float sqrtDelta = sqrt(delta);

            if(a == 0)
                throw std::logic_error("dzielenie przez zero (a=0)");

            if(delta > 0) {
                float x1 = (-b - sqrtDelta) / (2 * a);
                float x2 = (-b + sqrtDelta) / (2 * a);
                printf("dwa rozwiazania rzeczywiste: %f %f\n", x1, x2);
            } else if(delta == 0) {
                float x0 = -b / (2 * a);
                printf("jedno rozwiazanie rzeczywiste: %f\n", x0);
            }
        } catch(const std::logic_error &e) {
            cout << "error: " << e.what() << endl;
        }
    } else if(type == 2) {
        try {
            float delta = b * b - 4 * a * c;

            if(a == 0)
                throw std::logic_error("dzielenie przez 0 (a=0)");
            if(delta >= 0)
                throw std::logic_error("delta nieujemna");

            delta = -delta;
            float sqrtDelta = sqrt(delta);

            float real = -b / (2 * a);
            float imag = sqrtDelta / (2 * a);

            printf("dwa pierwiastki zespolone: %f + %fi oraz %f - %fi\n", real, imag, real, imag);

        } catch(const std::logic_error &e) {
            cout << "error: " << e.what() << endl;
        }
    }
}

int main() {
    fun();

    return 0;
}
