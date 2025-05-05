int main(){
    // array declaration: arr[] = {1,2,3,5,6}
// int arr[5] = {1,2,3,4,5} 
// #define n 10
// arr[n];
// #define n 10
// int main(){
//   int arr[n];
  
// }


    //  int  i=10;
//  int* ptr =&i;
  int arr[]={1,2,3,4,5};
  // for (int i=0;i<5;i++){
  // int *ptr = &arr[i];

  // printf("%d\n",*(ptr+i));
  // }
  int sum2=0, sum1=0,*p1,*p2;
  for(p1 = &arr[0] ; p1 < &arr[5] ; p1++){
    sum1+=*p1;
    
  }
  printf("%d\n",sum1);
  // we are assinging base address of array to pointer
  for(p2 = arr; p2 < arr+5; p2++){
    sum2+=*p2;
  }
  printf("%d\n",sum2);

// printing 2d array using pointer


    int a[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int *p;

    // Treat the 2D array as a flat array
    for (p = &a[0][0]; p < &a[0][0] + 2 * 3; p++) {
        printf("%d ", *p);
    }
    printf("\n");
    for (p = a; p < a+ 2; p++) {
            printf("%d ", *p);
                    }

   
}

