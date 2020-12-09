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

int congruencia(int a, int b, int m)
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
        
        int invers, k, sol1;

        invers = inverso(a, m);
        k = invers * b;
        sol1 = k % m;
        
        return sol1;
    }

}


int chines(int a1, int m1, int a2, int m2, int a3, int m3)
{
    if (euclides(m1, m2) == 1 && euclides(m1, m3) == 1 && euclides(m2, m3) == 1)
    {
        int M, M1, M2, M3, r1, r2, r3, s1, s2, s3, x;
        M = m1 * m2 * m3;
        
        M1 = M/m1;
        r1 = a1;
        s1 = congruencia(M1, 1, m1);
        
        M2 = M/m2;
        r2 = a2;
        s2 = congruencia(M2, 1, m2); 

        M3 = M/m3;
        r3 = a3;
        s3 = congruencia(M3, 1, m3);
        
        x = (M1 * r1 * s1) + (M2 * r2 * s2) + (M3 * r3 * s3);
        
        if (x > M)
        {
            x = x % M;
        }
        return x;

    }
    else
    {
        printf("Os pares não são primos entre si.\n");
        return 0;
    }
    
}


int main()
{
    printf("-- Teorema Chinês do Resto --\n");
    printf("X ≡ a1(mod m1), X ≡ a2(mod m2), X ≡ a3(mod m3)\n");
    
    int a1, a2, a3, m1, m2, m3;
    printf("Insira a1: ");
    scanf("%d", &a1);
    printf("Insira m1: ");
    scanf("%d", &m1);
    printf("Insira a2: ");
    scanf("%d", &a2);
    printf("Insira m2: ");
    scanf("%d", &m2);
    printf("Insira a3: ");
    scanf("%d", &a3);
    printf("Insira m3: ");
    scanf("%d", &m3);
    
    int result = chines(a1, m1, a2, m2, a3, m3);
    if (result != 0)
    {
       printf("x = %d\n", chines(a1, m1, a2, m2, a3, m3));
    }
    return 0;
}