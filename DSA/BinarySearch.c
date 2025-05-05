#include <stdio.h>

int binarySearch(int arr[], int low, int high, int key)
{
    ///imp
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key)
            return mid;

        else if (key > arr[mid] )
            low = mid + 1;

        else
            high = mid - 1;
    }
////
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;
    int result = binarySearch(arr, 0, n - 1, key);
   if(result == -1) 
        printf("Element is not present in array");
   else 
        printf("Element is present at index %d",result);

}