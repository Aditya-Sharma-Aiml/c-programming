#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;

}

void InsertionSort(int arr[], int n) {

    for (int i = 0; i <= n - 1; i++) {
    ///imp
    int j = i;

    while(j>0 && arr[j-1]>arr[j]){ 

        swap(&arr[j-1],&arr[j]);
        j--;
    }   /////
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    InsertionSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}