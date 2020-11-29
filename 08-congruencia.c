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
        
        int invers2;
        while (invers < 0)
        {
            invers = invers + m;
        }
        
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
    printf("-- Congruências Lienares --\n");
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