#include <stdio.h>
#include <time.h>

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

int main()
{    
    time_t start = time(NULL);
    int i = 0;
    int prim; 
    long long int result;

    start = time(NULL);
    while (time(NULL) - start <= 60)
    {
        
        if (i <= 40)
        {
            if (primo(i) == 1)
            {
                printf("%d\n", i);
            }
        }
        else
        {
            result = (i*i) - i + 41;
            
            if (primo(result) == 1)
            {
                printf("%lli\n", result);
            }

        }
        i++;
    }
    return 0;
}
