// find possible stair path to reach on nth stair : if you can take single , double or triple step  at a time.
#include<stdio.h>
int Total_Stair_Path(int n){
    int totalWays;
   if (n==1 || n==2) return n;
   else if(n==3) return n+1;
   else return  totalWays=Total_Stair_Path(n-1)+Total_Stair_Path(n-2)+Total_Stair_Path(n-3);
}
int main(){
    int n;
    printf("enter the no. of stairs: ");
    scanf("%d",&n);
    printf("%d",Total_Stair_Path(n));
}