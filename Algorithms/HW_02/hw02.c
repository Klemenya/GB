#include <stdio.h>

int PrimeNumber(int n)
{
    if (n > 1)
    {
        for(int i = 2; i < n ; i++)
        {
            if (n%i == 0)
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}



int main()
{
    int n;
    printf("Enter the number for check:\n");
    scanf("%d",&n);
    int res = PrimeNumber(n);
    if (res == 1){
        printf("Number %d is not prime\n",n);
    }
    else
    {
        printf("Number %d is prime\n",n);
    }

    return 0;
}
