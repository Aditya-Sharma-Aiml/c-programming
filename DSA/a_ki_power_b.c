#include<stdio.h>
// int power(int a,int b){
//     if (a==0 && b==0) printf("not defined");
//     else if (b==0) return 1;
//     return a*power(a,(b-1));
// }
int power(int a, int b){
    if (b==0) return 1;
    else{
        int half=power(a,b/2);
        if(b%2==0) return half*half;
        else return a*half*half;
    }        
}
int main(){
    int a,b;
    printf("Enter the a ki power b:");
    scanf("%d %d",&a,&b);
    printf("%d",power(a,b));
}