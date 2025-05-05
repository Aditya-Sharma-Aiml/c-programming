#include<stdio.h>
int* swap(int *arr ,int n){
        arr[2]=100;
        int x=sizeof(arr)/sizeof(arr[0]);
        printf("%d is not original size\n",x);//can't  be access original size
          int start=0;
          int end=n-1;
          while (start<end){
           int  temp=arr[start];
            arr[start]=arr[end];
            arr[end]=temp;
            start++;
            end--;
        }
        // for (int i=0;i<n;i++){ //arr[i]=arr[j] : i+j=n-1 => j=n-i-1
        //     arr[i]=arr[n-i-1];
        // }
          
          return arr;
          

    }


int main(){
    // int arr1[]={1,2,3,4,5};

    // printf("%d \n",sizeof(arr1));
    // printf("%d \n",sizeof(arr1[0]));
    // int n= sizeof(arr1)/sizeof(arr1[0]);
    // //int n= sizeof(arr1)/sizeof(int);
    // printf("%d \n",n);


    // //int arr2[]; // not valid decleration
    // int arr2[5]; // valid
    // //input
    // printf("Enter the element: ");
    // for (int i=0;i<5;i++){
    //     scanf("%d",&arr2[i]);
    // }
    // //output
    // for (int i=0;i<5;i++){
    //     printf("%d ",arr2[i]);
    // }

    //passing array  to function
    int arr3[]={1,2,3,4,5};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    printf("size: %d\n",n3);
    printf("before updation: %d\n",arr3[2]);
    printf("original array: ");
    for (int i=0;i<n3;i++){
        printf("%d ",arr3[i]);
    }
    printf("\n");
    //int* revArray=swap(arr3,n3);
    swap(arr3,n3);
    //printf("After updation: %d\n",revArray[2]);
    printf("After updation: %d\n",arr3[2]);
    //reversed array:
    printf("reversed array: ");
    for (int i=0;i<n3;i++){
        printf("%d ",arr3[i]);
        //printf("%d ",revArray[i]);
    }


}


