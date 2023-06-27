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
        b++;
    }
    printf("\n");
    
}

void findMinMax(const int arr[], int n, int *minPtr, int *maxPtr) {
   
    *maxPtr = arr[0];
    *minPtr = arr[0];
  
   int i = 1;
   
    while(i < n){
     switch(arr[i] < *minPtr){
        case 1:
            *minPtr = arr[i];
            break;
    }
     switch(arr[i] > *maxPtr){
        case 1:
            *maxPtr = arr[i];
            break;
    }
    i++;
    }

}

int main() {
    int arr[SIZE];
    int n, min, max;

    readInput(arr, &n);
    printNumbers(arr, n);

    findMinMax(arr, n, &min, &max);

    printf("Minimum of array is: %d", min);
	printf("\nMaximum of array is: %d", max);

    return 0;
}
