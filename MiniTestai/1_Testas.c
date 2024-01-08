#include <stdio.h>

int main()
{
    
    
    int i = 10, sum = 0; 
    do
    { 
        if (i < 1) 
        {
            break; 
        }
        sum = i + sum - 1; 
    } 
    while(1);
    printf("Sum: %d\n", sum);

    return 0;
}