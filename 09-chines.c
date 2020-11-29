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


int chines(int a1, int m1, int a2, int m2, int a3, int m3)
{
    if (euclides(a1, m1) == euclides(a2, m2) == euclides(a3, m3) == 1)
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