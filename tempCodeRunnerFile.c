#include <stdio.h>

int g(int n, int rekAufruf)
{

    if (n > 1)
    {
        rekAufruf++;
        printf("%d  : %d. RekAufruf \n", n, rekAufruf);

        int res = 2 * g(n - 1, rekAufruf) + n * g(n - 2, rekAufruf);

        printf("%d: %d. result nach RekAufruf \n", n, rekAufruf);
        return res;
    }
    else
    {
        printf("%d  : n\t %d. RekAufruf \n", n, rekAufruf);
        return 1;
    }
}

int gIterativ(int n)
{
    printf("In gIterativ\nMit n:%d\n", n);

    if (n == 1)
    {
        return 1;
    }

    int erg = 0;
    int it = 0;
    int nI = 3;
    int iteration[n + 3];
    int g1Last = 4;
    int g2Last = 1;

    iteration[it] = g1Last;
    int g1 = n;
    int g2 = n;

    while (nI <= n)
    {
        printf("erg: %d\tg1Last:%d\tg2Last:%d\n", erg, g1Last, g2Last);

        erg = 2 * g1Last + nI * g2Last;
        iteration[nI] = erg;
        g2Last = g1Last;
        g1Last = iteration[nI];
        nI++;
    }
    for (int i = 0; i < n+1 ; i++)
    {
        printf("Iteration[%d]: %d\n", i, iteration[i]);
    }

    return iteration[n];
}

int g_help(int n, int i, int g1, int g2)
{
    if (n <= 1)
    {
        return g1;
    }
    
    int help = (2 * g1) + (i * g2);
    i++;
    return g_help(n - 1, i, help, g1);
}

int gEndrekursiv(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    int g1 = 4;
    int g2 = 1;
    return g_help(n - 1, 3, g1, g2);
}

int main()
{

    printf("%d  \n", g(5, 0));
    printf("%d  \n", gIterativ(5));
    printf("%d  gEndrekursiv\n", gEndrekursiv(5));

    return 0;
}

//c. Der Java-Compiler kann keine Rekursion eliminieren
