#include <stdio.h>
//#include <stdlib.h>
#include <stddef.h>

#define T char
#define SIZE 1000
#define true 1 == 1
#define false 1 != 1

#define SZ 10

typedef int boolean;

int cursor = -1;
T Stack[SIZE];


typedef struct {
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int tail;
int items;

void init() {
	for (int i = 0; i < SZ; ++i)
	{
		arr[i] = NULL;
	}
	tail = 0;
	items = 0;
}

void ins(int pr, int dat) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;

	if (items == SZ)
	{
		printf("Queue is full") ;
	}
	else
	{
		arr[tail] = node;
		items++;
		tail++;
	}
}

Node* rem() {
	if (items == 0)
	{
		return NULL;
	}
	else
	{
		int i;
		int maxPos = 0;
		Node* max = arr[0];
		for (i = 1; i < tail; i++)
		{
			if (arr[i]->pr > max->pr)
			{
				max = arr[i];
				maxPos = i;
			}
		}
		for (int j = maxPos; j < tail; j++)
		{
			arr[j] = arr[j + 1];
		}
		items--;
		tail--;
		return max;
	}
}

void printQueue() {
	for (int i = 0; i < tail; ++i)
	{
		if (arr[i] == NULL)
			printf("[ *, *]") ;
		else
			printf("%2d-> [%2d, %3d]\n",i+1 , arr[i]->pr,arr[i]->dat );
	}
	printf("\n");
}

boolean pushToStack(T data) {
    if(cursor < SIZE)
    {
        Stack[++cursor] = data;
        return true;
    }
    else
    {
        printf("%s\n", "stack overflow");
        return false;
    }
}

T popFromStack() {
    if(cursor != -1)
    {
        return Stack[cursor--];
    }
	else
    {
        printf("%s\n", "Stack is empty");
        return -1;
    }

}

void decToBinStack(int num) {
    if (num % 2 == 0)
    {
        pushToStack(0);
    }
	else
    {
        pushToStack(1);
    }

    if ((num / 2) != 0)
    {
        decToBinStack(num / 2);
    }
	else
    {
        return;
    }
}


int main()
{

    /* ------------------ task 1 (priority exception queue) ------------ */

	init();
	ins(10, 1);
	ins( 2, 2);
	ins( 5, 3);
	ins(10, 4);
	ins( 2, 5);
	ins( 4, 6);
	ins(10, 7);
	ins( 3, 8);
	ins( 1, 9);
	ins( 7,10);
	printQueue();

	for (int i = 0; i < 5; i++)
	{
		Node* n = rem();
		printf("priority = %2d, dat = %3d\n",n->pr, n->dat );
	}
	printf("\n");
	printQueue();

    /* ------------------ task 2 (convert decimal to binary using stack) ------------ */

    int n;
	printf("%s", "Enter number for convert to dec: ");
	scanf("%d", &n);
	decToBinStack(n);
	while (cursor != -1)
	{
		printf("%d", popFromStack()) ;
	}
    return 0;
}
