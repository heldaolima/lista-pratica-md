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

int decompor(int num)
{
    int ref = 2;

    printf("Decomposto: ");
    while (ref <= num)
    {
        int result = primo(ref);
        if (result == 1)
        {
            while (num % ref == 0)
            {
                if (num != ref)
                {
                    printf("%d x ", ref);
                }
                else
                {
                    printf("%d\n", ref);
                }
                
                num = num / ref;
            }
        }
        
    ref++;
    }
}

int main()
{
    printf("-- Fatoração em números primos --\n");
    int num;
    printf("Insira o número: ");
    scanf("%d", &num);

    decompor(num);
    
    return 0;
}