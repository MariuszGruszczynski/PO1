#include <iostream>
#include <list>

using std::cout;
using std::cin;
using std::endl;

int main(void) {
    int n_liczb = -1;

    cout << "Wczytywanie ilosci liczb..." << endl;
    do {
        cout << "podaj liczbe dodatnia: ";
        cin >> n_liczb;

        if(cin.fail()) {
            cout << "podano bledne dane, sprobuj ponownie" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if(n_liczb <= 0) {
            cout << "podano bledne dane, sprobuj ponownie" << endl << endl;
            continue;
        }

        break;
    } while(1);

    std::list<int> Lista;

    cout << endl << "Wczytywanie kolejnych liczb..." << endl;

    for(int i = 0; i < n_liczb; i++) {
        int temp = 0, temp2 = 0;

        cout << "podaj pare liczb: ";
        cin >> temp >> temp2;

        if(cin.fail()) {
            cout << "podano bledne dane, sprobuj ponownie" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            i--;
            continue;
        }

        if(temp < 0)
            Lista.push_front(temp);
        else
            Lista.push_back(temp);
        if(temp2 < 0)
            Lista.push_front(temp2);
        else
            Lista.push_back(temp2);
    }

    cout << endl;
    for(auto &a : Lista){
        cout << a << endl;
    }

    return 0;
}
