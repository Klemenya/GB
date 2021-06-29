#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int medianOfThree(int a, int b, int c){

	if ((a >= b && b >= c) || (c >= b && b >= a)) {
            return b;
    }
	if ((a <= b && a >= c) || (a <= c && a >= b)) {
	    return a;
    }
	return c;

    /*   ternary operator works too - tested */
    // return (a >= b ? ( b >= c  ? b : ( a >= c ) ? c : a ) : ( c >= b ? b : ( a >= c ? a : c )));
}

void sortInserts(int* arr, int len){
	int temp, pos;
	for(int i = 1; i < len; ++i){
		temp = arr[i];
		pos = i - 1;
		while (pos >= 0 && arr[pos] > temp){
			arr[pos + 1] = arr[pos];
			pos--;
		}
		arr[pos + 1] = temp;
	}
}

void swapInt(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void fillIntRandom(int* array, int size, int border) {
    for (int i = 0; i < size; ++i)
        *(array + i) = rand() % border;
}

void printIntArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%3d", array[i]);
        if (i != size - 1)
            printf(",");
    }
    printf("\n");
}

void QiuckSort(int* arr, int first, int last){
	int i = first;
	int j = last;
	int x = arr[(first + last)/2];
	do {
		while (arr[i]<x) i++;
		while (arr[j]>x) j--;
		if(i <= j){
			swapInt(&arr[i], &arr[j]);
			i++;
			j--;}
	}while (i <= j);
	if (i < last) QiuckSort(arr, i, last);
	if (j > first) QiuckSort(arr, first, j);
}

void BlockSort(int* arr, int len){
	const int max = len;
	const int b = 10;

	int blocks[b][max + 1];
	for (int i = 0; i < b; i++){
		blocks[i][max] = 0;
	}

	for(int digit = 1; digit < 100; digit*=10) {
		for(int i =0; i < max; i++){
			if(arr[i]%2 == 0) {
                int d = (arr[i] / digit)%b;
                int counter = blocks[d][max];
                blocks[d][counter] = arr[i];
                counter++;
                blocks[d][max] = counter;
                arr[i]= -1;
			}
		}
		int idx = 0;
		for(int i =0; i < b; ++i){
			for(int j = 0; j < blocks[i][max]; ++j){
				while (arr[idx] != -1)
				idx++;
				arr[idx++] = blocks[i][j];
			}
			blocks[i][max]=0;
		}
	}
}

int main(){

	const int SIZE = 40;
	int array[SIZE];
	int a;
	fillIntRandom(array, SIZE, 100);
	printIntArray(array, SIZE);

	if(SIZE<=10) {
		sortInserts(array, SIZE);
	}
	else {
		a = medianOfThree(array[0], array[SIZE/2], array[SIZE-1]);
		swapInt(&a, &array[SIZE/2]);
		QiuckSort(array, 0, SIZE-1);
	}
	printIntArray(array, SIZE);
	printf("\n");

	int arr2[12] = {0, 2, 8, 3, 4, 6, 5, 9, 8, 2, 7, 3};
	printIntArray(arr2, 12);
	BlockSort(arr2, 12);
	printIntArray(arr2, 12);

	return 0;
}
