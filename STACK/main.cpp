#include <iostream>
#include <cstdlib>
#include "overView_Stack.cpp"

void inputArrValue(int *Arr, unsigned int& sizeArr) {
    std::cout << "Enter array elements: ";
    for (int i = 0; i < sizeArr; i++) {
        std::cin >> Arr[i];
    }
}

int main() {
    Stack *st = NULL;
    unsigned int sizeArr;

    std::cout << "Enter size of array: ";
    std::cin >> sizeArr;

    int *Arr = (int *)malloc(sizeArr * sizeof(int));
    if (Arr == NULL) {
        std::cerr << "Memory allocation failed!" << std::endl;
        exit(1);
    }

    inputArrValue(Arr, sizeArr);

    for (int i = 0; i < sizeArr; i++) {
        push(&st, Arr[i]);
    }

    std::cout << "Stack elements: ";
    printStack(st);

    return 0;
}

