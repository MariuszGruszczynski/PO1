#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

template<class TYPE> class Fibonacci {
public:
    TYPE fib(const TYPE& nthElement) {
        if(nthElement < 3.0)
            return 1;

        return fib(nthElement - 1) + fib(nthElement - 2);
    }
};

template<class TYPE>
bool czyFib(TYPE liczba) {
    TYPE a = 1.0;
    TYPE b = 1.0;

    while (liczba != a && liczba != b) {
        a += b;
        b += a;
        if (b > liczba)
            break;
    }

    if(liczba == b || liczba == a)
        return true;

    return false;
}

int main() {
    Fibonacci<int> fib_int;
    Fibonacci<float> fib_float;
    Fibonacci<long long int> fib_lli;

    int i = 0;
    cout << "int: ";
    cin >> i;
    cout << "wynik ciagu fibonacciego dla int: " << fib_int.fib(i) << endl;

    float f = 0.0;
    cout << "float: ";
    cin >> f;
    cout << "wynik ciagu fibonacciego dla float: " << fib_float.fib(f) << endl;

    cout << "long long int: ";
    long long int lli = 0;
    cin >> lli;
    cout << "wynik ciagu fibonacciego dla long long int: " << fib_lli.fib(lli) <<  endl << endl;

    cout << "czy liczba 90 nalezy do ciagu? " << (czyFib(90) ? "tak" : "nie") << endl;
    cout << "czy liczba 18.0 nalezy do ciagu? " << (czyFib(18.0) ? "tak" : "nie") << endl;
    cout << "czy liczba 5555 nalezy do ciagu? " << (czyFib(832040) ? "tak" : "nie") << endl;

    return 0;
}
