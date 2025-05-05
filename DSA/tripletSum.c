#include<stdio.h>
int main(){
    int sum,n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    printf("Enter the sum of triplets: ");
    scanf("%d",&sum);
    int arr[n];
    printf("Enter the element: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int count=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if((arr[i]+arr[j]+arr[k])==sum){
                    printf("(%d,%d,%d)\n",arr[i],arr[j],arr[k]);
                count++;
            }
            
            }
        }
    }
    printf("triplets counts: %d",count);

}