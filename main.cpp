#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;

//indeksy liczone od 1
class Macierz final {
    int width, height;
    std::vector<float> data;

public:
    Macierz(int _width, int _height):
        width(_width),
        height(_height) {
        data.reserve(width * height);

        for(int i = 0; i < width * height; i++)
            data[i] = i + 1 + i / 10.0;
    }

    ~Macierz() {
        data.clear();
    }

    float& operator()(int i, int j) throw(std::out_of_range) { //wyrzuca std::out_of_range
        if(i - 1 >= width || i < 1 || j - 1 >= height || j < 1) {
            string exception_str = "parametry i: " + to_string(i) + " oraz j: " + to_string(j) + " przy szerokosci: "  + to_string(width) + " oraz wysokosci: " + to_string(height);
            throw std::out_of_range(exception_str);
        }

        return data[(j - 1) * width + i - 1];
    }

    void print() {
        for(int i = 0; i < height ; i++) {
            for(int j = 0; j < width; j++) {
                cout << data[width * i + j] << " ";
            }
            cout << endl;
        }
    }
};

int main(void) {
    Macierz m(3, 4);
    m.print();

    cout << endl;

    m(2,2) = 5.42;
    m(1,1) = 78.12;
    m(3,4) = 1005.22;
    m.print();

    return 0;
}
