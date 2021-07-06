#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct Node {
    T dat;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    int size;
} Stack;

void init(Stack *stack) {
    stack->head = NULL;
    stack->size = 0;
}

boolean push(Stack *stack, T value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}

T pop(Stack *stack) {
    if (stack->size == 0)
    {
        return -1;
    }
    Node *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

T read(Stack *stack) {
    if (stack->size == 0) {
        return -1;
    }
    T data = stack->head->dat;
    return data;
}

boolean checkSymbolOpen (char a) {
    if(a == '(' || a == '[' || a == '{' )
        return true;
    return false;
}

boolean checkSymbolClose (char a) {
    if(a == ')' || a == ']' || a == '}' )
        return true;
    return false;
}

char checkRevP(char c) {
    switch(c)
    {
    case ')':
        return '(';
    case ']':
        return '[';
    case '}':
        return '{';
    }
}

int main() {

    { /* ------------  task 10.1 -------------------*/
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);

    char str[100];
    fgets(str, 100, stdin);
    int n = strlen(str)-1;

    for (int i = 0; i < n ; i++) {
        if(checkSymbolOpen(str[i]))
        {
            push(st,str[i]);
        }

        if(checkSymbolClose(str[i]))
        {
            if(st == NULL || read(st) != checkRevP(str[i]) )
            {
                printf("Bracket sequence is NO CORRECT\n");
                return 0;
            }
            else
            {
                pop(st);
            }

        }
    }
    printf("Bracket sequence is CORRECT\n");
    }

    return 0;
}
