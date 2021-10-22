#include <iostream>
#include <string>

using namespace std;

class Osoby {
private:
    string imie;
    string nazwisko;
    string PESEL;
    string adres;

    int size;
    Osoby **baza;

public:
    Osoby():
        imie(""),
        nazwisko(""),
        PESEL(""),
        adres(""),
        size(0),
        baza(NULL) {

    }

    ~Osoby() {
        for(int i = 0; i < size; i++) {
            Osoby *currOsoba = *(baza + i);
            if(currOsoba != NULL) {
                *(baza + i) = NULL;
                delete currOsoba;
            }
        }
        if(baza != NULL)
            free(baza);
    }

    void add(string imie, string nazwisko, string PESEL, string adres);
    void remove(string PESEL);
    void display();
};

void Osoby::display() {
    puts("");
    for(int i = 0; i < size; i++) {
        Osoby *currentNode = *(baza + i);

        if(currentNode != NULL)
            cout << currentNode->imie << " " << currentNode->nazwisko << ", " << currentNode->adres << ", PESEL: " << currentNode->PESEL << endl;
    }
    puts("");
}

void Osoby::add(string imie, string nazwisko, string PESEL, string adres) {
    baza = (Osoby**) realloc(baza, sizeof(Osoby*) * (size + 1));
    size++;

    Osoby *newOsoba = new Osoby();
    newOsoba->imie = imie;
    newOsoba->nazwisko = nazwisko;
    newOsoba->PESEL = PESEL;
    newOsoba->adres = adres;

    *(baza + size - 1) = newOsoba;
}

void Osoby::remove(string PESEL) {
    for(int i = 0; i < size; i++) {
        Osoby *currOsoba = *(baza + i);

        if(PESEL == currOsoba->PESEL) {
            *(baza + i) = NULL;
            delete currOsoba;
            return;
        }
    }
}

class Lista {
private:
    unsigned int ID;
    Lista *prev;
    Lista *next;

public:
    Lista(unsigned int ID):
        ID(ID),
        prev(NULL),
        next(NULL) {

    }

    ~Lista() {
        printf("deleting node with ID: %d...\n", this->ID);

        if(next)
            delete next;
    }

    int add_after(unsigned int, unsigned int); //dodanie elementu za elementem o indeksie arg1, zwraca -1 jesli jest juz element o podanym ID, -2 w razie duplikatu, 0 gdy sukces
    int remove(unsigned int); //usuwa (i zwraca) element od podanym ID, -1 jesli nie go znajdzie
    void display();
    void sort();
    Lista* get_node(unsigned int); //zwraca element listy o zadanym ID

private:
    static int swap(Lista*, Lista*); //zwraca -1 w przypadku bledu, 0 jesli sukces
    static int compare(Lista*, Lista*); //zwraca 0 jesli node'y sa rowne, -1 jesli node1 jest wiekszy, 1 jesli node2 jest wiekszy, -2 jesli ktorys jest NULLem
};

void Lista::sort() {
    printf("sorting...\n");
    int sorted = 0;

    while(sorted == 0) {
        int swapped = 0;

        Lista* currNode = this;
        Lista* nextNode = this->next;

        while(nextNode != NULL) {
            if(compare(currNode, nextNode) == -1) {
                swap(currNode, nextNode);
                swapped = 1;
            }

            currNode = currNode->next;
            nextNode = nextNode->next;


        }
        if(swapped == 0)
            sorted = 1;
    }
}

int Lista::swap(Lista* node1, Lista* node2) {
    if(!node1 || !node2)
        return -1;

    if(node1 == node2)
        return -1;

    unsigned int tempID = node1->ID;
    node1->ID = node2->ID;
    node2->ID = tempID;

    return 0;
}

int Lista::compare(Lista* node1, Lista* node2) {
    if(node1 != NULL && node2 != NULL) {
        if(node1->ID > node2->ID)
            return -1;
        if(node1->ID < node2->ID)
            return 1;
        if(node1->ID == node2->ID)
            return 0;
    }

    return -2;
}

int Lista::remove(unsigned int ID) {
    Lista* found = get_node(ID);

    if(!found)
        return -1;

    if(found->next)
        found->next->prev = found->prev;
    found->prev->next = found->next;

    //NULLowanie zeby nie zniszczyc calej listy zaczynajac od "found"
    found->prev = NULL;
    found->next = NULL;

    int value = found->ID;

    delete found;

    return value;
}

void Lista::display() {
    Lista* temp = this;

    puts("\ndisplaying list...");
    do {
        printf("%d\n", temp->ID);
        temp = temp->next;
    } while(temp != NULL);

    puts("");
}

Lista* Lista::get_node(unsigned int ID) {
    Lista *temp = this;

    do {
        if(temp->ID == ID)
            return temp;
        temp = temp->next;
    } while(temp != NULL);

    return NULL;
}

int Lista::add_after(unsigned int ID, unsigned int newNodeID) {
    Lista* found = get_node(newNodeID); //ochrona przed duplikatem

    if(found)
        return -2;

    found = get_node(ID); //sprawdzanie czy jest istnieje z ID = arg1

    if(!found)
        return -1;

    Lista* newNode = new Lista(newNodeID);

    printf("adding list with ID: %d\n", newNodeID);

    if(found->next != NULL) {
        found->next->prev = newNode; //kolejnosc jest wazna, nie wyciagam przed nawias
        newNode->prev = found;
        newNode->next = found->next;
        found->next = newNode;
    } else {
        found->next = newNode;
        newNode->prev = found;
    }

    return 0;
}

class Zesp {
public:
    int real;
    int imag;

    Zesp():
        real(1),
        imag(1) {

    }

    void dodaj(Zesp);
    void odejmij(Zesp);
    void pomnoz(Zesp);
    void podziel(Zesp);
    void print();
    void set(int, int);
};

void Zesp::set(int real, int imag) {
    this->real = real;
    this->imag = imag;
}

void Zesp::print() {
    printf("%d + %di\n", real, imag);
}

void Zesp::dodaj(Zesp z) {
    this->real += z.real;
    this->imag += z.imag;
}

void Zesp::odejmij(Zesp z) {
    this->real -= z.real;
    this->imag -= z.imag;
}

void Zesp::pomnoz(Zesp z) {
    Zesp z3;
    z3.real = this->real * z.real - this->imag * z.imag;
    z3.imag = this->real * z.imag + this->imag * z.real;
    this->real = z3.real;
    this->imag = z3.imag;
}

void Zesp::podziel(Zesp z) {
    Zesp z3;
    double w = z.real * z.real + z.imag * z.imag;

    if (w > 0) {
        z3.real = (this->real * z.real + this->imag * z.imag) / w;
        z3.imag = (z.real * this->imag - this->real * z.imag) / w;
        this->real = z3.real;
        this->imag = z3.imag;
    } else {
        printf("Blad dzielenia\n");
    }
}

int main() {
    Zesp z1, z2;

    z1.print();

    z1.dodaj(z2);
    z1.print();

    z1.odejmij(z2);
    z1.print();

    z2.set(4, 7);

    z1.dodaj(z2);
    z1.print();

    z1.pomnoz(z2);
    z1.print();

    z1.podziel(z2);
    z1.print();

    puts("");

    Lista* lista = new Lista(5);

    lista->add_after(5, 4);
    lista->add_after(4, 10);
    lista->add_after(10, 1);
    lista->add_after(1, 8);
    lista->add_after(4, 5); //nie doda sie, bo duplikat
    lista->add_after(4, 13); //dodawanie w srodek listy
    lista->display();

    lista->remove(10);
    lista->remove(8);
    lista->add_after(4, 18);
    lista->display();

    lista->sort();
    lista->display();

    delete lista;

    Osoby *osoby = new Osoby();

    osoby->add("Mariusz", "Gruszczynski", "51248753897", "ULICA SIAKA OWAKA");
    osoby->add("Maciek", "Wisniewski", "21374201234", "ULICA MAKAO");
    osoby->add("Jacek", "Placek", "14893654791", "ULICA KOPERKOWA");
    osoby->display();

    osoby->remove("21374201234");
    osoby->display();

    delete osoby;

    return 0;
}
