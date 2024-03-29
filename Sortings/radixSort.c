#include <stdio.h>
#define MAX 20

int getDigitCount(int n){
  int count=0;
  while(n>0){
    n=n/10;
    count++;
  }
  return count;
}

int getMaxDigit(int arr[], int n){
  int max=arr[0], i;
  for(i=1; i<n; i++)
   if( max < arr[i])
      max =arr[i];
  return getDigitCount(max);
}
void countSort(int arr[], int n, int pos){
  int temp[MAX], count[10]={0}, i;
  for(i=0;i<n;i++){
    count[(arr[i]/pos)%10]++;
  }
  for(i=1;i<10;i++)
    count[i]+=count[i-1];
  for(i=n-1;i>=0;i--){
    temp[--count[(arr[i]/pos)%10]]=arr[i];
  }
  for(i=0;i<n;i++)
    arr[i]= temp[i];
}
void radixSort(int arr[], int n){
  int digitCount=getMaxDigit(arr, n);
  int i,pos;
  for(i=1,pos=1;i<=digitCount;i++,pos=pos*10)
    countSort(arr, n, pos);
}

int main(){
  int arr[] = {9,0,7,6,5,4,3,2,1,0};
  int i;
  printf("Before sortings....\n");
  for (i=0 ; i<10 ; i++){
    printf("%d ", arr[i]);
  }
  printf("\nAfter sortings....\n");
  radixSort(arr,9); //from 0 to 9th index

  for (i=0 ; i<10 ; i++){
    printf("%d ", arr[i]);
  }

  return 0;

}
