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

int chinesgeral(int qtd)
{
   int a[qtd], m[qtd];
   int M = 1;
   for (int i = 0; i < qtd; i++) //pegando os valores
   {
        printf("Insira o valor de a%d: ", i+1);
        scanf("%d", &a[i]);
        printf("Insira o valor de m%d: ", i+1);
        scanf("%d", &m[i]);
   }
    int result;
    for (int i = 0; i < qtd; i++) //checando a validade
    {
        for (int c = 0; c < qtd; c++)
        {
            if (i != c)
            {
               //printf("mdc(%d, %d) = %d\n", m[i], m[c], euclides(m[i], m[c]));
               result = euclides(m[i], m[c]);
               if (result != 1)
                {
                    return 0;
                }
            }
        }
        
        M = M * m[i];
    }
   int x = 0;
   int Mx[qtd], Sx[qtd];;
   for (int c = 0; c < qtd; c++)
   {
       Mx[c] = M/m[c];
       Sx[c] = congruencia(Mx[c], 1, m[c]);
       x = x + (Mx[c] * a[c] * Sx[c]);
   }

   if (x > M)
   {
       x = x % M;
   }

   return x;


}


int main()
{
    printf("-- Teorema Chinês do Resto --\n");
    printf("X ≡ a1(mod m1), X ≡ a2(mod m2), ..., X ≡ aN(mod mN)\n");
    
    int n;
    printf("Insira o número de congruências: ");
    scanf("%d", &n);    
    int result = chinesgeral(n);
    if (result != 0)
    {
        printf("X = %d\n", result);
    }
    else
    {
        printf("Não há resultados possíveis\n");
    }
    
    return 0;
}