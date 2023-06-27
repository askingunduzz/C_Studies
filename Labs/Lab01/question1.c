#include <stdio.h>
#include <stdbool.h>

// NOT = Hocam soruda switch case ile yapmak aklıma geldi denemek istedim,
// true false değerlerini kullanabilmek içinse yukarıdaki kütüphaneyi dahil ettim.
// kütüphane kullanımı yasak mı bilmiyorum o yüzden belirtmek istedim.
// yazdığım metod recursive bir şekilde çağrılıyor. 

int modulus(int num, int d)
{

    switch(num<d) {
    case true: 
        //base condition
        return num;
        //30 ,8 
        // büyükse onu döndürüyor.
     case false: 
        return modulus(num - d, d);
        // 30-8,8 >> 22,8
        // 22-8,8 >> 14,8
        // 14-8,8 >> 6,8 >> 6 8den küçük sonuç = 6 dönecek.
     
    }
}

int main()
{
    int num;
    int d;

    printf("Enter number> ");
    scanf("%d", &num);
    printf("Enter divisor> ");
    scanf("%d", &d);

    int mod = modulus(num, d);
    printf("Remainder: %d", mod);

    return 0;
}