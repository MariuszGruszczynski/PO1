#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define M_PI 3.14159265358979323846

using std::cout;
using std::endl;
using std::ostream;

class Wektor3D {
private:
    double x, y, z;

public:
    Wektor3D(): x(0),
        y(0),
        z(0) {
    }

    Wektor3D(double x, double y, double z):
        x(x),
        y(y),
        z(z) {

    }

    Wektor3D operator-() const {
        Wektor3D w(-x, -y, -z);

        return w;
    }

    Wektor3D operator*(const double &a) {
        Wektor3D w(x * a, y * a, z * a);

        return w;
    }

    friend Wektor3D operator*(const double &a, Wektor3D &w);

    void print() {
        cout << "x: " << x << ", y: " << y << ", z: " << z << endl;
    }

    friend double katPomiedzyWektorami(const Wektor3D &w1, const Wektor3D &w2);
    friend Wektor3D operator+(const Wektor3D &w1, const Wektor3D &w2);
    friend Wektor3D operator-(const Wektor3D &w1, const Wektor3D &w2);
    friend double operator*(const Wektor3D &w1, const Wektor3D &w2);
    friend Wektor3D operator/(const Wektor3D &w1, const Wektor3D &w2);
    friend ostream& operator<<(ostream& os, const Wektor3D &w);



private:
    double dlugoscWektora() const {
        double _dlugoscKwadrat = x * x + y * y + z * z;
        double _dlugosc = sqrt(_dlugoscKwadrat);

        return _dlugosc;
    }

    static double iloczynSkalarny(const Wektor3D &w1, const Wektor3D &w2) {
        double _iloczyn = w1.x * w2.x + w1.y * w2.y + w1.z * w2.z;

        return _iloczyn;
    }
};

ostream& operator<<(ostream& os, const Wektor3D &w) {
    cout << "x: " << w.x << ", y: " << w.y << ", z: " << w.z;
    return os;
}

double katPomiedzyWektorami(const Wektor3D &w1, const Wektor3D &w2) {
    double _katRadiany = acos(Wektor3D::iloczynSkalarny(w1, w2) / (w1.dlugoscWektora() * w2.dlugoscWektora()));
    double _katStopnie = _katRadiany * 180.0 / M_PI;

    return _katStopnie;
}

Wektor3D operator*(const double &a, Wektor3D &w) {
    Wektor3D newWektor = w * a;

    return newWektor;
}

Wektor3D operator+(const Wektor3D &w1, const Wektor3D &w2) {
    Wektor3D w(w1.x + w2.x, w1.y + w2.y, w1.z + w2.z);

    return w;
}

double operator*(const Wektor3D &w1, const Wektor3D &w2) {
    double w = Wektor3D::iloczynSkalarny(w1, w2);

    return w;
}

Wektor3D operator-(const Wektor3D &w1, const Wektor3D &w2) {
    Wektor3D w(w1.x - w2.x, w1.y - w2.y, w1.z - w2.z);

    return w;
}

Wektor3D operator/(const Wektor3D &w1, const Wektor3D &w2) {
    Wektor3D w;

    w.x = w1.y * w2.z - w2.y * w1.z;
    w.y = w2.x * w1.z - w1.x * w1.z;
    w.z = w1.x * w2.y - w2.x * w1.y;

    return w;
}

int main() {
    Wektor3D w(1.23, 2.42, 3.63465);
    Wektor3D minusw = -w;

    minusw.print();

    Wektor3D multiply = 2.42 * w;
    multiply.print();

    Wektor3D aaa(-2, 1, 2);
    Wektor3D bbb(0, 1, 1);

    cout << "kat pomiedzy wektorami: " << katPomiedzyWektorami(aaa, bbb) << " stopni" << endl;
    cout << "iloczyn skalarny: " << aaa*bbb << endl;
    cout << "iloczyn skalarny (2): " << w*multiply << endl;

    printf("iloczyn wektorowy: ");
    (aaa / bbb).print();
    printf("iloczyn wektorowy (2): ");
    (bbb / aaa).print();

    cout << aaa << endl << bbb << endl;

    return 0;
}
