#include <stdio.h>

void Merge(int arr[], int low, int mid, int high, int n) {
    int temp[n];
    int left = low;
    int right = mid + 1;
    int k = low;

    while (left <= mid && right <= high) {

        if (arr[left] <= arr[right]) {

            temp[k++] = arr[left++];
        } 
        else {
            temp[k++] = arr[right++];
        }
    }

    while (left <= mid) {

        temp[k++] = arr[left++];
    }

    while (right <= high) {
        
        temp[k++] = arr[right++];
    }

    for (int i = low; i <= high; i++) {
        arr[i] = temp[i];
    }
}

void MergeSort(int arr[], int low, int high, int n) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(arr, low, mid, n);
        MergeSort(arr, mid + 1, high, n);
        Merge(arr, low, mid, high, n);
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

    MergeSort(arr, 0, n - 1, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
