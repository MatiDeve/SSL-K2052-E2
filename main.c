#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void analizeAndSave(FILE * outputFile, char * numberString);
char * analize(char * numberString);
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
         analizeAndSave(outputFile, numberString);

         numberString = realloc(numberString, 2);
         strcpy(numberString, "");
      }
      else {
         append(numberString, c);
      }
   }
   analizeAndSave(outputFile, numberString);
   free(numberString);

   fclose(inputFile);
   fclose(outputFile);
   return 0;
}

void analizeAndSave(FILE * outputFile, char * numberString) {
   char * result = analize(numberString);
   fprintf(outputFile, "%-15s %-15s\n", numberString, result);
}

char * analize(char * numberString) {
   return "NO DEFINIDO";
}

void append(char * str, char c) {
   int length = strlen(str);
   int newLength = length + 2;
   str = realloc(str, newLength);
   str[length] = c;
   str[length+1] = '\0';
}