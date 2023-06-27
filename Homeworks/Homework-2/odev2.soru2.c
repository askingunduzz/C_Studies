#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define SIZE 250

float myAtof(char *string, char *error);

int main()
{
    char in[SIZE];
    float fn1, fn2, sonuc;
    char oper, errorState = 0;

    printf("Enter arithmetic operation:\n");
    gets(in);
   
  int i = 0;
  
   while (in[i] != '\0')
  {
    if (isspace(in[i]))
    {
        printf("Error has been occurred due to inappropriate input!\n");
        return 1;
    }
    i++;
   }
   
   
    if (strcmp(in, "+") == 0) {
    fn1 = 0.0;
    fn2 = 0.0;
    oper = '+';
    
   } else {
    switch (sscanf(in, "%f %c %f", &fn1, &oper, &fn2)) {
        case 3:
            break;
        default:
            printf("Error has been occurred due to inappropriate input!\n");
            return 1;
        }
   }

    if (oper == '/' && fn2 == 0) {
        printf("Cannot divided into 0.\n");
        return 1;
    }


    if (oper == '+') {
    sonuc = fn1 + fn2;
    } else if (oper == '-') {
    sonuc = fn1 - fn2;
    } else if (oper == '*') {
    sonuc = fn1 * fn2;
    } else if (oper == '/') {
    sonuc = fn1 / fn2;
    } else {
    printf("Invalid operator type!\n");
    return 1;
    }


    printf("%.2f %c %.2f = %.2f\n", fn1, oper, fn2, sonuc);

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
