#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct LinkedList {
    int data;
    struct LinkedList *next;
};

typedef LinkedList Stack;

int isEmpty(Stack *st) {
    return st == NULL;
}

//Push element to stack
void push(Stack **st, int value) {
    Stack *newNode = (Stack *)malloc(sizeof(Stack));
    if (newNode == NULL) {
        printf("Memory allocation error");
        exit(1);
    }
    newNode->data = value;
    newNode->next = *st;
    *st = newNode;
}

//pop element out of stack
int pop(Stack **st) {
    if (isEmpty(*st)) {
        printf("Stack is empty");
        exit(1);
    }
    Stack *temp = *st;
    int poppedValue = temp->data;
    *st = (*st)->next;
    free(temp);
    return poppedValue;
}

//Look at first element of stack
int peek(Stack *st) {
    if (isEmpty(st)) {
        printf("Stack is empty");
        exit(1);
    }
    return st->data;
}

//print stack
void printStack(Stack *st) {
    while (st != NULL) {
        std::cout << st->data << " ";
        st = st->next;
    }
    std::cout << std::endl;
}