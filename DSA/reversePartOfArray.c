#include<stdio.h>
int swap(int arr[] ,int n,int a,int b){
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
        int n,x,y;
        printf("Enter the size of array: ");
        scanf("%d",&n);

        printf("Enter the start index and end indes: ");
        scanf("%d %d",&x,&y);

        int arr[n];

        printf("Enter the element: ");
        for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    swap(arr,n,x,y);
     for (int i=0;i<n;i++){
        printf("%d ",arr[i]);
     }
    }