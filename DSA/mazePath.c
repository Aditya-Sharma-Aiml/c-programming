//maze path: find the number of ways to rech destination of an matrix
// conditions: we move only right and down with a single step
#include<stdio.h>
int mazePath(int currentRow,int currentCol,int endRow,int endCol){
    int rightWays = 0;
    int downWays = 0; 

    if (currentRow==endRow && currentCol==endCol){
        return 1;
    }
    else if (currentRow==endRow){ // we can move only rightways 
        rightWays += mazePath(currentRow,currentCol+1,endRow,endCol);
    }
    else if (currentCol==endCol){ // we can move only downtways 
        downWays += mazePath(currentRow+1,currentCol,endRow,endCol);
    }
     
    else{
        rightWays = mazePath(currentRow,currentCol+1,endRow,endCol);
        downWays = mazePath(currentRow+1,currentCol,endRow,endCol);
    }
    int totalWays = rightWays + downWays;
    return totalWays;
    
}
int main(){
    int endRows,endCols,startRow,startCol;

    printf("Enter the no. of rows and columns : ");
    scanf("%d %d",&endRows,&endCols);

    printf("Enter the starting rows and column : ");
    scanf("%d %d",&startRow,&startCol);

    int totalWays=mazePath(startRow,startCol,endRows,endCols);
    printf("%d",totalWays);
}