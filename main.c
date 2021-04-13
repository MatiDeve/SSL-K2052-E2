#include <stdio.h>
#include <stdlib.h>
#include "string.h"

char * analize(char * inputNumber);
void append(char * s, char c);

int main (int argc, char *argv[]) {
   FILE * inputFile = fopen("entrada.txt", "r");
   if (inputFile == NULL){
       printf("Error opening input file");
       exit(1);
   }

   FILE * outputFile = fopen("salida.txt", "w");
   if (outputFile == NULL){
       printf("Error opening output file");
       exit(1);
   }

   char * numberString = malloc(2);
   strcpy(numberString, "");

   while (1) {
      char c = fgetc(inputFile);
      if (c == EOF) {
         break;
      }
      if (c == ',') {
         char * result = analize(numberString);
         fprintf(outputFile, "%s %s\n", numberString, result);

         numberString = realloc(numberString, 2);
         strcpy(numberString, "");
      }
      else {
         append(numberString, c);
      }
   }
   char * result = analize(numberString);
   fprintf(outputFile, "%s %s\n", numberString, result);
   free(numberString);


   fclose(inputFile);
   return 0;
}

char * analize(char * inputNumber) {
   return "NO DEFINIDO";
}

void append(char * str, char c) {
   int length = strlen(str);
   int newLength = length + 2;
   str = realloc(str, newLength);
   str[length] = c;
   str[length+1] = '\0';
}