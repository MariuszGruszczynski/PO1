#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;

template <class T>
class Ciag {
public:
    T fibonacci(T t) {
        if(t < 3)
            return 1.0;
        return fibonacci(t - 2.0) + fibonacci(t - 1.0);
    }
};

int main() {
    Ciag<int> ciag_intow;
    Ciag<float> ciag_floatow;
    Ciag<long> ciag_longow;

    cout << ciag_intow.fibonacci(5) << endl;
    cout << ciag_floatow.fibonacci(9) << endl;
    cout << ciag_longow.fibonacci(14) << endl;

    return 0;
}
