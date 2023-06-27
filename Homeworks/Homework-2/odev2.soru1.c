#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define SIZE 250
float myAtof(char *string, char *error);

int main()
{
    char string[SIZE];            // Array declaration.
    float fnum1;
    char errorState=0;

    printf("Enter a number:\n");
    gets(string);

    fnum1=myAtof(string,&errorState);

    if (errorState==0){
        printf("Your number is: %.2f \n", fnum1);
    }else if (errorState==1){
        printf("Error has been occurred due to inappropriate input!\n");
    }

    return 0;
}

float myAtof(char* string, char* error) {
    int dpc,dc,sn ;
    float sonuc;
    sonuc= 0.0f;
    dpc=0;
    dc = 0;
    sn = 1;

    while (*string == ' ') {
        string++;
    }

   switch (*string) {
    case '-':
        sn = -1;
        string++;
        break;
    case '+':
        string++;
        break;
 
}
    while (*string != '\0' && isdigit(*string)) {
        sonuc = sonuc * 10.0f + (float)(*string - '0');
        dc++;
        string++;
    }

    if (*string == '.') {
        string++;
        dpc++;

      for (; *string != '\0' && isdigit(*string); string++) {
     sonuc = sonuc * 10.0f + (float)(*string - '0');
     dc++;
     dpc++;
   }

    }

   if (*string == 'e' || *string == 'E') {
        int us,us_sn;
        us= 0;
        us_sn= 1;
        string++;

      switch (*string) {
    case '-':
        us_sn = -1;
        string++;
        break;
    case '+':
        string++;
        break;
}
        while (*string != '\0' && isdigit(*string)) {
            us = us * 10 + (*string - '0');
            string++;
        }

        us = us*us_sn;
        dpc = dpc-us;
    }

  
  for (; *string != '\0'; string++) {
    if (*string != ' ') {
        *error = 1;
        return 0.0f;
    }
}


    if (dc == 0 && dpc == 0) {
        *error = 1;
        return 0.0f;
    }

   for (; dpc > 1; dpc--) {
    sonuc= sonuc / 10.0f;
}

    sonuc= sonuc*sn;

    *error = 0;
    return sonuc;
}

