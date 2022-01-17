#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <iomanip>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

#include <iostream>
#include <ostream>
using namespace std;

template<class T>
class MyVector {
private:
    int size;
    int capacity;
    T* data;

    int swap(int pos1, int pos2); //1 on success
    int compare(int pos1, int pos2); //po lewo wieksze: -1, po prawo wieksze: 1, gdy blad: -2, gdy rowne: 0

public:
    MyVector():
        size(0),
        capacity(1) {
        data = (T*) malloc(sizeof(T));
    }

    MyVector(T var):
        size(1),
        capacity(1) {
        data = (T*) malloc(sizeof(T));
        *data = var;
    }

    ~MyVector() {
        destroy();
    }

    int at(const T& var); //zwraca pozycje, -1 gdy nie znajdzie
    int push(T var); //1 on success
    void print();
    void destroy();
    T min();
    T max();
    void sort();
};

template<class T>
void MyVector<T>::sort() {
    if(size <= 1)
        return;

    puts("sortowanie...");

    while(1) {
        int ifSwapped = 0;

        for(int i = 0; i < size - 1; i++) {
            if(compare(i, i + 1) == -1) {
                swap(i, i + 1);
                ifSwapped = 1;
            }
        }

        if(ifSwapped == 0)
            break;
    }
}

template<class T>
int MyVector<T>::at(const T& var) {
    for(int i = 0; i < size; i++) {
        T var2 = *(data + i);
        if(var == var2)
            return i + 1;
    }

    cout << "brak" << endl;
    return -1;
}

template<class T>
int MyVector<T>::swap(int pos1, int pos2) {
    if(pos1 >= size || pos2 >= size || pos1 < 0 || pos2 < 0 || pos1 == pos2)
        return 0;

    T temp = *(data + pos1);
    *(data + pos1) = *(data + pos2);
    *(data + pos2) = temp;

    return 1;
}

template<class T>
int MyVector<T>::compare(int pos1, int pos2) {
    if(pos1 < 0 || pos2 < 0 || pos1 >= size || pos2 >= size)
        return -2;
    if(pos1 == pos2)
        return 0;

    T var1 = *(data + pos1);
    T var2 = *(data + pos2);

    if(var1 > var2)
        return -1;
    if(var1 < var2)
        return 1;
    return 0;
}

template<class T>
T MyVector<T>::min() {
    T _min = *data;

    for(int i = 1; i < size; i++) {
        if(*(data + i) < _min)
            _min = *(data + i);
    }

    return _min;
}

template<class T>
T MyVector<T>::max() {
    T _max = *data;

    for(int i = 1; i < size; i++) {
        if(*(data + i) > _max)
            _max = *(data + i);
    }

    return _max;
}

template<class T>
void MyVector<T>::destroy() {
    if(data)
        free(data);
    data = NULL;
    size = 0;
    capacity = 0;
}

template<class T>
void MyVector<T>::print() {
    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << std::fixed <<  std::setprecision(3) <<  *(data + i) << " ";
    }
    cout << endl << endl;
}

template<class T>
int MyVector<T>::push(T var) {
    if(size == capacity) {
        puts("rozszerzam tablice...");
        data = (T*) realloc(data, sizeof(T) * capacity * 2);
        capacity *= 2;
    }

    *(data + size) = var;
    size++;

    return 1;
}

int main() {
    cout << "-----pierwszy wektor (inty)-----" << endl << endl;

    MyVector<int> myvec(5);
    myvec.push(2);
    myvec.push(3);
    myvec.push(1);
    myvec.push(7);
    myvec.push(6);

    myvec.print();

    cout << "minimum: " << myvec.min() << endl;
    cout << "maximum: " << myvec.max() << endl;

    int poz = myvec.at(1);
    if(poz != -1)
        cout << "wartosc 1 na pozycji: " << poz << endl;
    poz = myvec.at(11);
    if(poz != -1)
        cout << "wartosc 11 na pozycji: " << poz << endl;

    myvec.sort();
    myvec.print();


    cout << "-----drugi wektor (wieksze inty)-----" << endl << endl;

    MyVector<int> myvec2;
    myvec2.push(4523);
    myvec2.push(214);
    myvec2.push(16447);
    myvec2.push(142164);
    myvec2.push(124);
    myvec2.push(-6334);
    myvec2.push(-235);
    myvec2.push(764);
    myvec2.push(851);
    myvec2.push(23);
    myvec2.push(-754);
    myvec2.push(742367);
    myvec2.push(14668);
    myvec2.push(89265);
    myvec2.push(28752);
    myvec2.push(11325);
    myvec2.push(678882);
    myvec2.push(199632);
    myvec2.push(-146262);

    myvec2.print();

    cout << "minimum: " << myvec2.min() << endl;
    cout << "maximum: " << myvec2.max() << endl;

    myvec2.sort();
    myvec2.print();

    cout << "-----trzeci wektor (floaty)-----" << endl << endl;

    MyVector<float> myvec3;
    myvec3.push(325.124);
    myvec3.push(2.952);
    myvec3.push(67.423);
    myvec3.push(-23.352);
    myvec3.push(-32523.121);
    myvec3.push(421.523);
    myvec3.push(16841.84);
    myvec3.push(7.188);
    myvec3.push(84.218);
    myvec3.push(23.862);
    myvec3.push(86741.182);
    myvec3.push(4820.832);
    myvec3.push(14.763);
    myvec3.push(89.187);
    myvec3.push(268.18);
    myvec3.push(-1871.704);
    myvec3.push(8671.117);
    myvec3.push(1115.184);
    myvec3.push(-0.481);

    myvec3.print();

    cout << "minimum: " << myvec3.min() << endl;
    cout << "maximum: " << myvec3.max() << endl;

    myvec3.sort();
    myvec3.print();

    return 0;
}
