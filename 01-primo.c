#include <stdio.h>



int main()
{
    int n;
    int cont = 0; 
    printf("-- O número é primo? --\n");
    printf("Insira o número: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cont++;
        }
    }
    if (cont > 2)
    {
        printf("Composto\n");
    }
    else
    {
        printf("Primo\n");
    }

    return 0;
}