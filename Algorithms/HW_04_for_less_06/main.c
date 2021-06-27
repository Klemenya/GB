#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void sortIntBubbleTd (int **arr, int cel, int row){     // Buble sort in Int Two Dimensional array
    int len = cel * row;
    for(int j = 0; j < len; j++){
        for (int i = 0; i < (len - 1 - j); i++){        // (len-j-1) - reduced the number of iterations by 2 times
            int y = i/cel;
            int x = i%cel;
            int y2 = (i+1)/cel, x2 = (i+1)%cel;
            if (arr[y][x] > arr[y2][x2]){
                swap(&arr[y][x], &arr[y2][x2]);
            }
        }
    }
}

int** initIntArray(int** array,const int row, const int col){    // create array Y * X CHAR
    array = (int**) calloc(sizeof(int*),row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int),col);
    }
    return array;
}

void fillIntArray(int** array, const int row, const int col){    //
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            *((*(array + i)) + j) = 0;
        }
    }
}

void printIntArray(int** array, const int row, const int col){    //
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("[%d]", *((*(array + i)) + j));
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    /*----------   buble sort  ---------------*/
    const int row =3;
    const int col =3;

    int ** arr = initIntArray(arr,row,col);

    //fillIntArray(arr,row,col);
    //printIntArray(arr,row,col);

    arr[0][0] = 1;
    arr[0][1] = 9;
    arr[0][2] = 2;
    arr[1][0] = 5;
    arr[1][1] = 7;
    arr[1][2] = 6;
    arr[2][0] = 4;
    arr[2][1] = 3;
    arr[2][2] = 8;
    printIntArray(arr,row,col);

    sortIntBubbleTd(arr,row,col);
    printIntArray(arr,row,col);

    /* ------------ TPK -------------------*/
    int array[11];
    printf("Enter 11 digit:\n");

    for(int i = 0; i < 11 ; i++){
        printf("%d:>",i+1);
        scanf("%d",&array[i]);
    }
    for(int i = 0; i < 11 ; i++){
        int temp = array[i];
        array[i] = array[10-i];
        array[10-i] = temp;
        }
    for(int i = 0; i < 11 ; i++){
        if( (sqrt(fabs(array[(10 - i)])) + 5 * pow(array[(10-i)], 3)) > 400){
            printf(" sqrt(fabs(%d) + 5 * pow(%d, 3)) > 400\n",array[10-i],array[10-i]);
        }
    }

    /*----------------------------------------*/
//    for(int i = 0; i < 11 ; i++){
//        printf("%d:>",i+1);
//        scanf("%d",&array[10-i]);
//        if( (sqrt(fabs(array[(10 - i)])) + 5 * pow(array[(10-i)], 3)) > 400){
//            printf(" sqrt(fabs(%d) + 5 * pow(%d, 3)) > 400\n",array[10-i],array[10-i]);
//        }
//    }

    return 0;
}
