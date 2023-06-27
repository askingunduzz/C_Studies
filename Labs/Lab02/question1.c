#include <stdio.h>
#define SIZE 1000

void readInput(int arr[], int *nPtr);
void printNumbers(const int arr[], int n);

int main() {
    
    int n;
    int arr[SIZE];
    
    readInput(arr, &n);
    printNumbers(arr, n);

    return 0;
}

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
