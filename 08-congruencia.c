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

int inverso(int a, int m) 
{
    for (int i = 1; i < m; i++)
    {
        if ((i * a) % m == 1)
        {
            return i;
        }
    }
}
void congruencia(int a, int b, int m)
{
    int nsolucoes;
    if (a > m)
    {
        nsolucoes = euclides(a, m);
    }
    else
    {
        nsolucoes = euclides(m, a);
    }
        
    if (b % nsolucoes == 0)
    {
        a = a/nsolucoes;
        b = b/nsolucoes;
        m = m/nsolucoes;
        
        int invers = inverso(a, m);
        int k = invers * b;

        printf("Número de soluções: %d\n", nsolucoes);

        int sol1 = k % m;
        printf("Solução 1: %d\n", sol1);
        
        for (int i = 2; i <= nsolucoes; i++)
        {
            printf("Solução %d: ", i);
            int soln = sol1 + (m * (i-1));
            printf("%d\n", soln);
        }
    }
    else
    {
        printf("Não há soluções possíves\n");
    }

}


int main()
{
    printf("-- Congruências Lineares --\n");
    printf("aX ≡ b (mod m)\n");
    
    int a, b, m;
    printf("Insira o valor de a: ");
    scanf("%d", &a);
    printf("Insira o valor de b: ");
    scanf("%d", &b);
    printf("Insira o valor de m: ");
    scanf("%d", &m);
    
    congruencia(a, b, m);
    return 0;
}