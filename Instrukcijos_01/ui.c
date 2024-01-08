#include <stdio.h>
#include <stdlib.h>
 
#define SIZE 10          // data size
#define FREQ_SIZE 1000   // upper bound for values
 
// input: 
//    user enters 10 non-negative integers
// output: 
//    report how many times each unique value occured,
//    display values and occurence times in ascending order
 
int main() {
   
   int inputArray[SIZE] = { 0 };
   int frequency[FREQ_SIZE] = { 0 };
   int diffNums[SIZE] = { 0 };
   int num, counter = 0;
 
   printf("Programa pateikia kiek kartu kiekvienas skaicius pasikartojo\n");

   printf("Iveskite 10 skaiciu\n");
 
   while(counter < SIZE){
      printf("\nIveskite %d sekos skaiciu: ", counter + 1);
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <= FREQ_SIZE)){
            inputArray[counter++] = num;
            printf("Skaicius ivestas sekmingai\n");
         } else {
            printf("Skaicius netelpa i ribas ir turi priklausyti rezyje [0; %d]\n", FREQ_SIZE);
         }
      } else {
         printf("Netinkama ivestis\n");
         printf("Iveskite neneigiama skaiciu is naujo\n");

         while(getchar() != '\n')
            ;
      }
   }
   
   printf("Duomenys buvo ivesti sekmingai\n");
   
   // proceeding to computations...
   
   for(int i=0; i<SIZE; i++){
        frequency[ inputArray[i] ]++;
   }
 
   int flag;
   int diffNumsCounter = 0;
 
   for(int i=0; i<SIZE; i++){
      flag=1;
      for(int j=0; j<i; j++){
         if(inputArray[i] == inputArray[j]){
            flag=0;
         }        
      }       
      if(flag){
         diffNums[diffNumsCounter] = inputArray[i];
         diffNumsCounter++;
      }
   }
 
   int temp;
 
   for(int j=0; j<diffNumsCounter-1; j++){
      for(int i=0; i<diffNumsCounter-j-1; i++){
         if(diffNums[i] > diffNums[i+1]){
            temp = diffNums[i];
            diffNums[i] = diffNums[i+1];
            diffNums[i+1] = temp;
         }
      }
   }
 
   printf("\nRezultatai bus atspausdinti\n");
   printf("\nSkaicius              daznis\n");
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){
         printf("%8d ____________ %d\n", diffNums[i], frequency[diffNums[i]]);
      }
   }
 
   return 0;
}