#include <stdio.h>
#include <stdlib.h>

int czyPierwsza(int n);
void clearInput();
unsigned long long silnia(int n);

struct List {
    struct Node *head;
    struct Node *tail;
};

struct Node {
    int age;
    struct Node *prev;;
    struct Node *next;
};

struct List* createList();
void destroyList(struct List **lista);

int size(struct List *lista);
void printList(struct List *lista);
struct Node *node_at(struct List *lista, int index);

void push_back(struct List *lista, int wiek);
void push_front(struct List* lista, int wiek);
int pop_back(struct List* lista);
int pop_front(struct List* lista);

int main() {
    puts("PART 1: SILNIA\n");

    int n = 0;

    while(1) {
        printf("Z jakies liczby chcesz silnie? ");
        if(!scanf("%d", &n) || n < 0) {
            printf("podales zla liczbe\n");
            clearInput();
        } else
            break;
    }

    printf("Silnia z %d = %llu\n\n", n, silnia(n));

    puts("PART 2: LICZBY PIERWSZE\n");

    while(1) {
        printf("Ile wypisac liczb pierwszych? ");
        if(!scanf("%d", &n) || n < 0) {
            printf("podales zla liczbe\n");
            clearInput();
        } else
            break;
    }

    for(int i = 0, counter = 0;;) {
        if(counter >= n)
            break;
        if(czyPierwsza(i)) {
            printf("%d\n", i);
            counter++;
        }

        i++;
    }

    puts("\nPART 3: LISTA DWUKIERUNKOWA CYKLICZNA\n");

    struct List *lista = createList();

    push_back(lista, 20);
    push_back(lista, 30);
    push_back(lista, 40);
    puts("");

    printf("pop_front: %d\n", pop_front(lista));
    printList(lista);
    puts("");

    push_front(lista, 10);
    printList(lista);
    puts("");

    printf("pop_back: %d\n\n", pop_back(lista));

    struct Node *node_at_one = node_at(lista, 1);
    if(node_at_one)
        printf("node at 1: %d\n\n", node_at_one->age);

    destroyList(&lista);

    return 0;
}

struct Node *node_at(struct List *lista, int index) {
    if(!lista || index < 0 || index >= size(lista))
        return NULL;

    struct Node *poprzednio = lista->head;

    for(int i = 0; i < index; i++) {
        poprzednio = poprzednio->next;
    }

    return poprzednio;
};

void printList(struct List *lista) {
    if(!lista || size(lista) < 1)
        return;

    printf("Printing list...\n");

    struct Node* poprzednio = lista->head;

    do {
        printf("%d\n", poprzednio->age);
        poprzednio = poprzednio->next;
    } while(poprzednio != lista->head);
}

struct List* createList() {
    struct List *temp = malloc(sizeof(struct List));

    temp->tail = NULL;
    temp->head = NULL;

    return temp;
}

void destroyList(struct List **lista) {
    if(!lista)
        return;

    puts("destroying Lista...");
    while(size(*lista) > 0) {
        printf("pop_back: %d\n", pop_back(*lista));
    }

    free(*lista);
    *lista = NULL;
    puts("Lista freed");
}

int pop_back(struct List* lista) {
    if(!lista)
        return -1;

    int sizeOfLista = size(lista);

    if(sizeOfLista == 0)
        return -1;

    int value = lista->tail->age;

    struct Node *nodeToFree = lista->tail;

    if(sizeOfLista == 1) {
        lista->head = NULL;
        lista->tail = NULL;
    } else {
        lista->tail->prev->next = lista->head;
        lista->head->prev = lista->tail->prev;
        lista->tail = lista->tail->prev;
    }

    free(nodeToFree);
    return value;
}

int pop_front(struct List* lista) {
    if(!lista)
        return -1;

    int sizeOfLista = size(lista);

    if(sizeOfLista == 0)
        return -1;

    int value = lista->head->age;

    struct Node *nodeToFree = lista->head;

    if(sizeOfLista == 1) {
        lista->head = NULL;
        lista->tail = NULL;
    } else    {
        lista->tail->next = lista->head->next;
        lista->head->next->prev = lista->tail;
        lista->head = lista->head->next;
    }

    free(nodeToFree);
    return value;
}

void push_back(struct List* lista, int wiek) {
    if(!lista || wiek < 1) {
        printf("Nieprawidlowe argumenty\n");
        return;
    }

    printf("dodaje %d na koniec listy...\n", wiek);

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->age = wiek;

    if(size(lista) == 0) {
        newNode->next = newNode;
        newNode->prev = newNode;
        lista->tail = newNode;
        lista->head = newNode;
    } else {
        lista->head->prev = newNode;
        lista->tail->next = newNode;

        newNode->prev = lista->tail;
        newNode->next = lista->head;

        lista->tail = newNode;
    }
}

void push_front(struct List* lista, int wiek) {
    if(!lista || wiek < 1) {
        printf("Nieprawidlowe argumenty\n");
        return;
    }

    printf("dodaje %d na poczatek listy...\n", wiek);

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->age = wiek;

    if(size(lista) == 0) {
        newNode->next = newNode;
        newNode->prev = newNode;
        lista->tail = newNode;
        lista->head = newNode;
    } else {
        lista->head->prev = newNode;
        lista->tail->next = newNode;

        newNode->next = lista->head;
        newNode->prev = lista->tail;

        lista->head = newNode;
    }
}

int size(struct List *lista) {
    if(!lista)
        return -1;

    if(lista->tail == NULL && lista->head == NULL)
        return 0;
    if(lista->tail == lista->head)
        return 1;

    int size = 0;
    struct Node *poprzednio = lista->head;

    do {
        poprzednio = poprzednio->next;
        size++;
    } while(poprzednio != lista->head);

    return size;
}

int czyPierwsza(int n) {
    if(n < 2)
        return 0;

    for(int i = 2; i < n; i++) {
        if(n % i == 0)
            return 0;
    }

    return 1;
}

void clearInput() {
    char c = 0;

    do {
        scanf("%c", &c);
    } while(c != '\n' && c != EOF);
}

unsigned long long silnia(int n) {
    if(n <= 1)
        return 1;
    return n * silnia(n - 1);
}
