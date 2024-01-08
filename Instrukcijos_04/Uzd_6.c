#include <stdio.h>

int main()
{
    int a;
    int temp;
    int sk = 0;
    int ats, atssk;

    printf("Iveskite skaicius: ");
    scanf("%d", &a); // Ivedamas pirmasis skaicius

    do // do-while ciklas sukasi tol, kol ivestyje nera atrandamas neteigiamas skaicius
    {
        temp = a;
        for (sk = 0; temp > 0; ++sk) // Skaiciuojama kiek skaitmenu turi ivestasis skaicius
            temp /= 10;
        if (atssk < sk) // Tikrinama ar ivestasis skaicius turi daugiausiai skaitmenu
        {
            atssk = sk;
            ats = a;
        }
        scanf("%d", &a);
    } while (a > 0);
    
    // Spausdinami rezultatai
    printf("Spausdinami rezultatai\n");
    printf("Daugiausiai skaitmenu turi skaicius: %d\n", ats);
    printf("Skaitmenu skaicius: %d\n", sk);

    return 0;
}