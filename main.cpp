#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>

using std::cout;
using std::endl;
using std::string;

void fun() {
    string str = "";

    std::getline(std::cin, str);

    int a = 0;

    try {
        a = std::stoi(str);
        printf("%d\n", a);
    } catch(std::invalid_argument e) {
        cout << "invalid argument exception" << endl;
    } catch(std::out_of_range e) {
        throw e;
    }

}

int main() {
    try {
        fun();
    } catch(std::out_of_range e) {
        cout << "out of range exception\n";
    }

    return 0;
}
