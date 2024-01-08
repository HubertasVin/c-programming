#include <stdio.h>
#include <ctype.h>

int main()
{
    int G;
    int seka;
    int sk = 0;
    int tsk = 0, nsk = 0, nsuma = 0, nsand = 1;
    int baigta = 0;
    int abc = 0;
    int i = 0;

    /* Ivedama G */
    printf("Iveskite G: ");
    
    /* Ciklas sukamas tol, kol patikrintas skaicius is tikruju yra skaicius */
    while ((scanf("%d", &G) != 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis, Iveskite skaiciu: ");

        while(getchar() != '\n')
            ;
    }
    
    printf("Iveskite skaiciu seka: ");
    while ((scanf("%d", &seka) != 1) || (getchar() != '\n'))
    {
        printf("Netinkama ivestis, Iveskite skaiciu: ");

        while(getchar() != '\n')
            ;
    }
    /* Irasomas pirmasis sekos narys ir tikrinama ar jis yra skaicius*/
    

    /* While ciklas sukamas iki kol ivestas skaicius neatitinka G (Sekos pabaigos indikatoriui) */
    while (seka != G) 
    {
        /* Atliekami sekos skaiciavimai */
        baigta = 0;
        sk++;
        if (seka > 0)
        {
            tsk++;
        }
        if (seka < 0)
        {
            nsuma += seka;
            nsand *= seka;
            nsk++;
        }

        /* Ivedama seka */
        while ((scanf("%d", &seka) != 1) || (getchar() != '\n'))
        {
            printf("Netinkama ivestis, Iveskite skaiciu: ");

            while(getchar() != '\n')
                ;
        }
    }

    /* Isvedami skaiciavimu rezultatai terminale */
    printf("Viso skaiciu yra: %d", sk);
    printf("\n");
    printf("Teigiamu skaiciu yra: %d", tsk);
    printf("\n");
    if (nsk == 0)
    {
        printf("Nera neigiamu skaiciu");
        printf("\n");
    }
    else
    {
        printf("Neigiamu nariu suma: %d", nsuma);
        printf("\n");
        printf("Neigiamu nariu sandauga: %d", nsand);
        printf("\n");
    }
    return 0;
}