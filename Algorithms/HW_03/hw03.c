#include <stdio.h>

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

int degrNum2(int n, int m)
{
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






int main()
{

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









    return 0;
}






