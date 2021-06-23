
#include <stdio.h>
#include <stdlib.h>

int **pArr;

int decToBin(int n){

    if (n == 0)
        return 0;
    else
        return (n % 2 + 10 * decToBin(n / 2));
}

int degrNum(int n, int m){

    if(m == 0)
        return 1;
    else
        return ( n * degrNum(n,--m));
}

int degrNum2(int n, int m){
    if (m == 0)
        return 1;
    if (m == 1)
        return n;
    if (m % 2 == 0)
    {
        int res = degrNum2(n, m / 2);
        return res * res;
    }
    else
        return degrNum2(n, --m) * n;
}



void createArr(int Y, int X){               // create arr and alloc

    int y,x;
    pArr=(int**)malloc(Y*sizeof(int*));
    for (y=0;y<Y;y++){
        pArr[y] = (int*)malloc(X*sizeof(int));
        for(x=0;x<X;x++){
            pArr[y][x] = 0;
        }
    }
}

void printArr(int Y, int X){                // print arr
    for (int y = 0; y < Y; y++){
        for (int x = 0; x < X; x++){
            printf("%2d ", pArr[y][x]);
        }
        printf("\n");
    }
    printf("\n");

}

void freeArr(int Y){                        // freeing memory
    for (int y = 0; y < Y; y++){
            free(pArr[y]);
    }
    free(pArr);
}

int recChess(int y, int x){                 // counting paths
    if (y == 0 && x == 0)
        return 0;
    else if ( (y == 0 ^ x == 0) && pArr[y][x]!=1)
        return 1;
    else if(pArr[y][x] == 1)
        return 0;
    else if(pArr[y][x] != 1)
        return recChess(y, x - 1) + recChess(y - 1, x);
    else
        return 0;
}

void addStop(int Y,int X){                  // add obstacle
    for(int y=0;y<Y;y++)
        for(int x=0;x<X;x++){
            if(x > 0 && y == 0 && pArr[y][x-1] == 1){
                pArr[y][x]=1;
            }
            if(y > 0 && x == 0 && pArr[y-1][x] == 1){
                pArr[y][x]=1;
            }
        }
}






int main(){

    /*---------------------------------------------*/
    int n,m;
    printf("Enter a decimal number: ");
    scanf("%d",&n);
    printf("%d in binary = %d\n",n,decToBin(n));

    /*---------------------------------------------*/

    printf("Enter number: ");
    scanf("%d",&n);
    printf("Enter degree of number: ");
    scanf("%d",&m);
    printf("var 1 -> %d in %d degree = %d\n",n,m,degrNum(n,m));
    /*---------------------------------------------*/

    printf("var 2 -> %d in %d degree = %d\n",n,m,degrNum2(n,m));

    /*---------------------------------------------*/
    int Y = 3, X = 3, ways=0;

    printf("Enter the number of columns: ");
    scanf("%d",&Y);
    printf("Enter the number of lines  : ");
    scanf("%d",&X);

    createArr(Y,X);
    // printArr(Y,X);  // empty board

    /*------------- test values for 5 x 5-----------*/
    //pArr[0][2] = 1;
    //pArr[2][2] = 1;
    //pArr[4][3] = 1;
    //pArr[3][0] = 1;
    printArr(Y,X);
    /*--------------------------------------*/

    addStop(Y,X);

    for (int y = 0; y < Y; y++){
        for (int x = 0; x < X; x++){
            ways = recChess(y, x);
            printf("%3d",recChess(y, x));
        }
        printf("\n");
    }


     printf("Found %d possible ways!\n", ways  ); //did not complete the output of the result, I'm sorry

    freeArr(Y);

    return 0;
}
