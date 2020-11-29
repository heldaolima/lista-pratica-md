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

int quocientes(int a, int d, int cont) // tamanho da lista de quocientes
{
    int resto = a % d;
    int quo = a / d;
    cont = cont + 1;
    if (resto == 0){
        return cont;
    }
    else
    {
        return quocientes(d, resto, cont);
    }
}

int inverso(int a, int d)
{
    int maior, menor;
    if (a > d)
    {
        maior = a;
        menor = d;
    }
    else
    {
        maior = d;
        menor = a;
    }
    
    int tam = quocientes(maior, menor, 0);

    int resto, quoc;
    int arr[tam]; // declaro a lista de quocientes
    int i = 0;
    while (menor != 0) // usando euclides, faço lista de quocientes
    {
        resto = maior % menor;
        quoc = maior / menor;
        maior = menor;
        menor = resto;
        arr[i] = quoc;
        i++;
    }
    
    int len = sizeof(arr)/sizeof(arr[0]); //tamanho da lista de quocientes
    
    
    int lensem = len-1;

    int semultimo[lensem];
    for (int i = 0; i < lensem; i++) //lista de quocientes sem o último elemnto
    {
        semultimo[i] = arr[i];
    }
    
    int inversa[lensem];

    int c = 0;
    for (int i = lensem-1; i >=0; i--) //lista sem o último elemento inversa
    {
        
        inversa[c] = semultimo[i];
        c++;
    }

    int results[len]; //lista dos resultados, que se forma a partir da lista inversa
    for (int i = 0; i <= len; i++)
    {
        if (i == 0)
        {
            results[0] = 1; // o primeiro elemento é sempre 1
            results[i+1] = inversa[i] * 1; // o segundo é o primeiro da inversa vezes 1
        }
        else
        {
            results[i+1] = (inversa[i] * results[i]) + results[i-1]; // formando o resto da lista
        }

    }
    
    int len2 = sizeof(results)/sizeof(arr[0]); //tamanho da lista de resultados
    
    //interessam-nos o penúltimo e o último elementos
    int penultimo = results[len2-2];
    int ultimo = results[len2-1];
    

    int leninv = sizeof(inversa)/sizeof(inversa[0]); //tamanho da lista inversa dos quocientes
    

    int x, y;
    if (leninv % 2 == 0) // se o tamanho é par, temos penultimo *-1
    {
        x = ultimo;
        y = penultimo *-1;   
            
        if (a > d)
        {
            if (penultimo > ultimo)
            {
                return x;
            }
            else
            {
                return y;
            }
        }
        else if (a < d)
        {
            if (penultimo > ultimo)
            {
                return y;
            }
            else
            {
                return x;
            }
        }
    }
    else //ultimo * -1
    {
        y = penultimo;
        x = ultimo *-1;
        if (a > d)
        {
            if (penultimo > ultimo)
            {
                return x;
            }
            else
            {
                return y;
            }
        }
        else if (a < d)
        {
            if (penultimo > ultimo)
            {                
                return y;
            }
            else
            {
                return x;
            }
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
        
        int invers = inverso(a, m);
        
        
        while (invers < 0)
        {
            invers = invers + m;
        }
        
        int k = invers * b;
        

        int sol1 = k % m;
        return sol1;
    }
}

int chinesgeral(int qtd)
{
   int a[qtd], m[qtd];
   int M = 1;
   for (int i = 0; i < qtd; i++)
   {
        printf("Insira o valor de a%d: ", i+1);
        scanf("%d", &a[i]);
        printf("Insira o valor de m%d: ", i+1);
        scanf("%d", &m[i]);
        if (euclides(a[i], m[i]) == 1)
        {
            M = M * m[i];
        }
        else
        {
            printf("Os pares não são primos entre si.\n");
            return 0;
        }
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
    
    return 0;
}