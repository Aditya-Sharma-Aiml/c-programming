#include<stdio.h>
int fact(int n){
    if (n==1 || n==0) return 1;

    if (n<0) {
        printf("invalin input");
        return 0;
    }

    int result = n*fact(n-1);
    return result;
}
int main(){
    int n;
    printf("Enter the  number:");
    scanf("%d",&n);
    printf("%d",fact(n));

}

