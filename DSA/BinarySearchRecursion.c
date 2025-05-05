#include<stdio.h>
int binarySearch(int arr[],int low, int high,int key){
    while(low<=high){

        int mid = low+(high-low)/2;

        if (arr[mid]==key) return mid;

        else if (key<arr[mid]) {
            return binarySearch(arr,low,mid-1,key);
        
        }
        else{
            return binarySearch(arr,mid+1,high,key);
        }
    }
    return -1;
}
int main(){
    int arr[] = { 2, 3, 4, 10, 40 ,100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;
    printf("Enter the key :");
    scanf("%d",&key);

    int result = binarySearch(arr, 0, n - 1, key);
   if(result == -1) 
        printf("Element is not present in array");
   else 
        printf("Element is present at index %d",result);

}