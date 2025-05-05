//rotate the given array 'arr' by k steps ,where k in non -ve.
//k can be greater than size of array n
#include<stdio.h>
int rev(int arr[] ,int a,int b){
          int start=a;
          int end=b;
          while (start<end){
           int  temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
          return *arr;

    }
int main(){
    int n,k;
        printf("Enter the size of array: ");
        scanf("%d",&n);

        printf("Enter the rotating step(k): ");
        scanf("%d",&k);

        int arr[n];
        
        printf("Enter the element: ");
        for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    if(k>n){
        k=k%n;
        rev(arr,0,n-1);
        rev(arr,0,k-1);
        rev(arr,k,n-1);
    }
    else{
        rev(arr,0,n-1);
        rev(arr,0,k-1);
        rev(arr,k,n-1);
    }
    
    printf("rotated array: ");
     for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
     }
}