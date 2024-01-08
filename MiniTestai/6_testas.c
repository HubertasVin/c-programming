#include <stdio.h>
#include <stdlib.h>

// struct Student{char name[30], surname[30]; int grades[10]; struct Student student};
// struct Student{char name[30], surname[30]; int grades[10]; Student *student};

// struct Student

//     {

//              char name[30], surname[30];

//              int grades[10];

//     }
// struct Student{char name[30], surname[30]; int grades[10] = {};};

int main()
{
    // int data[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    // printf("%d\n", **data + 2);

    // int b = 10;
    // int *c = &b;
    // printf("%d\n", *&**&c);
    // if (*&**&c == c)
    // {
    //     printf("Teisingai\n");
    // }
    
    // void *x();

    // int a[3][5];
    // int *p = a[3];
    // printf("%d\n", a[0][1]);

    // printf("%%%-8d%%", 54);

    // int i = 2, a[] = { 0, 1, 2, };
    // printf("%d\n", a[++i]);

    // enum e { A = 2, B, C, D, E, F, G, H, I, J, K, L };
    // printf("%d\n", B+D);

    // fprintf(stdout,"Hello");

    // int i, f(int);

    // int a = (i++) && (++i);
    // int b = (i < 4) ? ( f(++i) + i ) > 1 ) : (i--);
    // char c[i+1] = ++i;
    // int d[i] = ( i + (i++) ) || f(i) - i;

    // int f (int a []);
    // int * (*g) ( char [] ) = ( int *(char*[]) ) f;

    // const int YEAR = 2022;
    // ++*(int*)&YEAR;

    int input[9];
    scanf("%8[^?!]s", &input);
    printf("%s\n", input);


    return 0;
}