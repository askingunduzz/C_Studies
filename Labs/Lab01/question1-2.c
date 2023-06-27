#include <stdio.h>
#include <math.h>

void isRectangle(int *result, double *centerX, double *centerY)
{
    double X_1, Y_1, X_2, Y_2, X_3, Y_3, X_4, Y_4,D_1, D_2, D_3,D_4,D_5,D_6,C_x, C_y;
    
    int ir = 0; 

    scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &X_1, &Y_1, &X_2, &Y_2, &X_3, &Y_3, &X_4, &Y_4);

    D_1 = sqrt(pow((X_2-X_1), 2) + pow((Y_2-Y_1), 2));
    D_2 = sqrt(pow((X_3-X_2), 2) + pow((Y_3-Y_2), 2));
    D_3 = sqrt(pow((X_4-X_3), 2) + pow((Y_4-Y_3), 2));
    D_4= sqrt(pow((X_2-X_1),2) + pow((Y_2-Y_1),2));
    D_5= sqrt(pow((X_3-X_1),2) + pow((Y_3-Y_1),2));
    D_6 = sqrt(pow((X_4-X_2), 2) + pow((Y_4-Y_2), 2));


    if (D_1 == D_3 &&  D_2 == sqrt(pow((X_4-X_1), 2) + pow((Y_4-Y_1), 2)) && D_1*D_2 == D_3*sqrt(pow((X_2-X_1), 2) + pow((Y_2-Y_1), 2))&&(D_4<D_5) && (D_2<D_6) && (D_3< D_5) )
    {
        ir = 1;
        C_x = (X_1 + X_2 + X_3 + X_4)/4;
        C_y = (Y_1 + Y_2 + Y_3 + Y_4)/4;
    }

    *result = ir;
    
   if (ir == 1) {
    *centerX = C_x;
    *centerY = C_y;
    } else {
    *centerX = 0;
    *centerY = 0;
    }

}

int main()
{
 int result;
    double centerX, centerY;

    isRectangle(&result, &centerX, &centerY);

    if (result == 1)

        printf("Given points are rectangle, centers are x: %.3f y: %.3f",centerX,centerY );
    else
        printf("Given points are not rectangle, centers are x: %.3f y: %.3f",centerX,centerY );

    return 0;
}





