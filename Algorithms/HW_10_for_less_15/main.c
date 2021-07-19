#include <stdio.h>
#include <stdlib.h>

int simpleHashFunc(char* str) {
    int i = 0;
    int sum = 0;
    while (str[i] != 0) {
        printf("%d ", str[i]);
        sum += str[i++];
    }
    return sum;
}

void clearArr(char* str) {
    for(int i = 0; i < 100; i++) {
        str[i] = 0;
    }
}

void simpleHashPrint() {
    char arr[100];
    clearArr(arr);
    printf("---   HW 15 task 1   ---\n  Simple hash function \n");
    printf("------------------------\nEnter the string: ");
    scanf("%s", arr);
    printf("\n%d - sum of hashes", simpleHashFunc(arr));
}

/*---------------------------------------------------------*/

int greedyCoinsCount(int* coins, int amount) {
    int count = 0;
    while(amount > 0) {
        if(amount / coins[0] > 0) amount = amount - coins[0];
        else if (amount / coins[1] > 0) amount = amount - coins[1];
        else if (amount / coins[2] > 0) amount = amount - coins[2];
        else if (amount / coins[3] > 0) amount = amount - coins[3];
        else amount = amount - coins[4];
        count++;
    }
    return count;
}

void greedyAlg() {
    int coins[] = {50, 10, 5, 2, 1};
    int cents = 98;
    int res=greedyCoinsCount(coins,cents);
    printf("\n\n\n---   HW 15 task 2   ---\n    Greedy algorithm \n");
    printf("------------------------");
    printf("\nNeed %d coins for %d cents.\n", res, cents);
}

int main()
{
    simpleHashPrint();
    greedyAlg();
    return 0;
}
