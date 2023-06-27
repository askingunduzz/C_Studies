#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000


void readInput(int arr[], int *nPtr) {
    
    printf("Enter the number of elements: ");
    scanf("%d", nPtr);

    printf("Enter %d elements: ", *nPtr);
    int a = 0;
    
    while (a < *nPtr){
        scanf("%d", &arr[a]);
        a++;
     
    }
 
}


void printNumbers(const int arr[], int n) {
    
    printf("Array elements: ");
    int b = 0;
    
    while (b<n){
        printf("%d ", arr[b]);
        //  printf("%d", b);
        b++;
    }
    
    printf("\n");
    
}

void findLeaders(const int arr[], int n, int leadersArr[], int *sp) {
    int maksimum_ = arr[n-1]; 
    
    int sayim = 0;
    int deger = n-1;
    
    while (deger>=0){
        // for (deger=n-1;deger<0;deger--){
            //
        
      //  if (arr[deger]<= maksimum_)
         if(arr[deger] >= maksimum_){
            maksimum_ = arr[deger];
            leadersArr[sayim] = maksimum_;
            //  printf("%d", sayim);
            sayim++;
        }
        deger--;
    }
    *sp = sayim;
  
}
int main() {
        int arr[SIZE];
        int n;
        int leadersArr[SIZE];
        int s;
        readInput(arr, &n);
        printNumbers(arr, n);
		findLeaders(arr, n, leadersArr, &s);
		printf("Leaders ");
		printNumbers(leadersArr, s);
        return 0;
}