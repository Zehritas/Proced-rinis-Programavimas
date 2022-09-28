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

   // report what the program does
   printf("Si programa surenka is vartotojo 10 skaiciu, kurie turi atitkti tam tikrus reikalavimus. Toliau programa juos surikiuoja pagal dydi ir nurodo ju dazni\n");

   // ask to enter 10 numbers
   printf("Iveskite seka is 10 nariu(-io)\n");
   while(counter < SIZE){
      // ask to enter the following number
      printf("Iveskite %d sekos elementa: ", counter+1);
      if((scanf("%d", &num) == 1) && (getchar() == '\n')){
         if ((num >= 0) && (num <= FREQ_SIZE)){
            inputArray[counter++] = num;
            // report that number entered successfully
            printf("Numeris buvo ivestas sekmingai!\n");
         } else {
            // report that value exceeds bounds and has to belong to [0; FREQ-SIZE]
            printf("Numeris nepriklauso masyvo reziai [0; %d]\n", FREQ_SIZE);
         }
      } else {
         // report invalid input, ask to enter whole non-negative number again
         printf("Netinkama ivestis! Prasome ivesti ne neigiama, o sveika skaiciu!\n");
         while(getchar() != '\n')
         {
           //nieko
         }
      }
   }

   // report that data has been entered correctly
   printf("Duomenys buvo suvesti teisingai!\n");

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

   // report that results will be reported
   printf("Skaiciai        Daznis\n");
   for(int i=0; i<diffNumsCounter; i++){
      if( frequency[ diffNums[i] ] != 0 ){
         // report the value of diffNums[i] and the value of frequency[diffNums[i]]
         printf("%8d", diffNums[i]);
         printf("%14d\n", frequency[diffNums[i]]);
      }
   }

   return 0;
}
