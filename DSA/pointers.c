#include<stdio.h>
int sum1toN(int n,int sum){

  if (n==0){
    printf("%d",sum);
  }
  sum1toN(n-1,sum+n);  
}
int main(){
  int n,sum=0;
  printf("Enter the number :");
  scanf("%d",&n);
  sum1toN(n,sum);
}

