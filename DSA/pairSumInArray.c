//find the  total numbers of pairs in the array whose sum is equal to the given value x

#include<stdio.h>
int main(){
    int sum,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the sum of pairs: ");
    scanf("%d",&sum);
    int arr[n];
    printf("Enter the element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if((arr[i]+arr[j])==sum){
                printf("(%d,%d)\n",arr[i],arr[j]);
                count++;
            }
        }
    }
    printf("pair counts: %d",count);

}