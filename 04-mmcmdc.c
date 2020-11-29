#include <stdio.h>

int primo(int num)
{
    int cont = 0;
    for (int i = 1; i <= num; i++)
    {
        if (num % i == 0)
        {
            cont++;
        }
    }
    if (cont > 2)
    {
        return 0;
    }
    else
    {
        return 1;
    }

}

int mmc(int num1, int num2)
{
    int maior;
    if (num1 > num2)
    {
        maior = num1;
    }
    else 
    {
        maior = num2;
    }

    int resposta = 1;
    int ref = 1;
    

    while (ref <= maior)
    {
        ref++;
        int result = primo(ref);
        if (result == 1)
        {
            while (num1 % ref == 0 || num2 % ref == 0)
            {
                resposta = resposta * ref;         
                if (num1 % ref == 0)
                {
                    num1 = num1 / ref;
                }
                if (num2 % ref == 0)
                {
                    num2 = num2 / ref;
                }
            }
        }

    }
    return resposta;
}

int mdc(int num1, int num2)
{
    int maior;
    if (num1 > num2) {maior = num1;}
    else {maior = num2;}

    int resposta = 1;
    int ref = 1;

    while (ref <= maior)
    {
        ref++;
        int result = primo(ref);
        if (result == 1)
        {
            while (num1 % ref == 0 || num2 % ref == 0)
            {
                if (num1 % ref == 0 && num2 % ref == 0)
                {
                    resposta = resposta * ref;
                }        
                if (num1 % ref == 0)
                {
                    num1 = num1 / ref;
                }
                if (num2 % ref == 0)
                {
                    num2 = num2 / ref;
                }
            }
        }

    }
    return resposta;
}


int main()
{
    printf("-- MDC e MMC por fatoração --\n");
    int n1, n2, minimo, maximo;
    printf("Insira o primeiro número: ");
    scanf("%d", &n1);
    printf("Insira o segundo número: ");
    scanf("%d", &n2);

    printf("MMC(%d, %d) = %d\n", n1, n2, mmc(n1, n2));
    printf("MDC(%d, %d) = %d\n", n1, n2, mdc(n1, n2));
    return 0;
}