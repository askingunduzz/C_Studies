#include <stdio.h>
#include <math.h>

int main() {
    
    float a;
    float b;
    float c;
    
    printf("Enter value of a: ");
    scanf("%f", &a);
    printf("Enter value of b: ");
    scanf("%f", &b);
    printf("Enter value of c: ");
    scanf("%f", &c);
    
    int minimum_x;
    int maximum_x;
    
    printf("Enter minimum value of x_n: ");
    scanf("%d", &minimum_x);
    printf("Enter maximum value of x_n: ");
    scanf("%d", &maximum_x);
    

    float minus_1 ;
   minus_1= 10.0;
     
     int i = 1;
     
     while(i<=maximum_x){
           float x_n = minus_1 * b + (-b + sqrt(b*b - 4*a*c))/(2*a);
           
        if (i >= minimum_x) {
            printf("x_%d: %.2f\n", i, x_n);
        }
        
        minus_1 = x_n;
         i++;
     }
   

  
    
    return 0;
}
