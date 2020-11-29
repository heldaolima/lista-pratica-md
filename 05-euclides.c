#include <stdio.h>

int euclides(int a, int d)
{
    int resto = a % d;
    if (resto == 0)
    {
        return d;
    }
    else
    {
        return euclides(d, resto);
    }
}

int main()
{
    printf("-- Algoritmo de Euclides --\n");
    int n1, n2;
    printf("Insira o primeiro número: ");
    scanf("%d" ,&n1);
    
    printf("Insira o segundo número: ");
    scanf("%d", &n2);
    
    printf("MDC(%d, %d) = ", n1, n2);
    if (n1 > n2)
    {
        printf("%d\n", euclides(n1, n2));
    }
    else
    {
        printf("%d\n", euclides(n2, n1));
    }
    
    return 0;
}