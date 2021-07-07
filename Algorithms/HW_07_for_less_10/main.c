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
    return c;
}



/*--------------------- singly linked list -------------------*/
typedef struct {
    Node *head;
    int size;
} List;

void ins(List *lst, T data) {
    Node *new = (Node*) malloc(sizeof(Node*));
    new->dat = data;
    new->next = NULL;

    Node *current = lst->head;
    if (current == NULL) {
        lst->head = new;
        lst->size++;
        return;
    } else
    {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new;
        lst->size++;
    }
}

Node* rm(List *lst, T data) {
    Node *current = lst->head;
    Node *parrent = NULL;

    if (current == NULL) {
        return NULL;
    }

    while (current->next != NULL && current->dat != data) {
        parrent = current;
        current = current->next;
    }

    if (current->dat != data) {
        return NULL;
    }

    if (current == lst->head) {
        lst->head = current->next;
        lst->size--;
        return current;
    }

    parrent->next = current->next;
    lst->size--;
    return current;
}

void printNode(Node *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d] ", n->dat);
}

void printList(List *lst) {
    Node *current = lst->head;
    if (current == NULL) {
        printNode(current);
    } else
    {
        do {
            printNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf("\n");
}

List* list_copy(List *lst) {
    List *tmp = (List*) malloc(sizeof(List*));
    Node *current_node = (Node*) malloc(sizeof(Node*));

    if (lst->size == 0) {
        init_list(tmp);
        return tmp;
    }

    current_node = lst->head;

    for (int i = 0; i < lst->size; ++i) {
        ins(tmp, current_node->dat);
        current_node = current_node->next;
    }
    free(current_node);

    return tmp;
}

boolean isSorted(List *lst) {
    if (lst->size == 0) {
        return -1;
    }

    Node *current_node = (Node*) malloc(sizeof(Node*));
    current_node = lst->head;

    if (current_node->next == NULL) {
        free(current_node);
        return true;
    }

    for (int i = 0; i < lst->size - 1; ++i) {
        if (current_node->dat > current_node->next->dat) {
            free(current_node);
            return false;
        }
    }
    free(current_node);
    return true;
}

void init_list(List* lst) {
    lst->head = NULL;
    lst->size =0;
}



int main() {

     /* ------------  task 10.1 -------------------*/
    Stack *st = (Stack*) malloc(sizeof(Stack));
    init(st);

    char str[100];
    int balance = 0;
    printf("Enter sequence: ");
    fgets(str, 100, stdin);
    int n = strlen(str)-1;

    for (int i = 0; i < n ; i++) {
        if(checkSymbolOpen(str[i]))
        {
            push(st,str[i]);
            balance++;
        }

        if(checkSymbolClose(str[i]))
        {
            if(st == NULL || read(st) != checkRevP(str[i]) )
            {
                balance = -1;
                break;
            }
            else
            {
                pop(st);
                balance--;
            }

        }
    }
    if(balance !=0){
        printf("Bracket sequence is NO CORRECT\n\n");
    } else
    {
    printf("Bracket sequence is CORRECT\n\n");
    }

     /* ------------  task 10.2 -------------------*/
    List *lst = (List*) malloc(sizeof(List*));
    List *lst_copy;

    init_list(lst);
    //ins(lst, 1);
    //ins(lst, 22);
    //ins(lst, 10);
    //ins(lst, 12);

    ins(lst, 1);
    ins(lst, 2);
    ins(lst, 3);
    ins(lst, 4);

    printf("Original singly linked list:\n");
    printList(lst);

    lst_copy = list_copy(lst);
    printf("Copied singly linked list:\n");
    printList(lst_copy);

    rm(lst_copy, 1);
    printf("Modifying the copied singly linked list:\n");
    printf("Original:\n");
    printList(lst);
    printf("Copied:\n");
    printList(lst_copy);

    /* ------------  task 10.3 -------------------*/
    printf("This list is%ssorted\n", isSorted(lst) == 1 ? " " : " NOT ");
    free(lst);
    free(lst_copy);

    return 0;
}
