#include <stdio.h>
#include <math.h>

int main() {
    double a ;
    double b ;
    double h ;
    double T ;
    double sum_of ;
    double xi;
    int n;
    int c ;
    int d;

    printf(":Enter value of a: \n");
    scanf("%lf", &a);
    printf("Enter value of b: \n");
    scanf("%lf", &b);
    printf("Enter value of n: \n");
    scanf("%d", &n);
    printf("Enter value of c: \n");
    scanf("%d", &c);
    printf("Enter value of d: \n");
    scanf("%d", &d);

    h = ((b-a)/n) ;

    
    sum_of = 0;
    
    int i = 1;
    
    while(i<n){
     xi = a + i*h;
     sum_of = sum_of + pow(xi, c) + 2*d;
     i++;
    }
 

    T = ((h/2)*(pow(a, c)+2*d + pow(b, c)+2*d + 2*sum_of));

 
    printf("T: %.2lf", T);

    return 0;
}
