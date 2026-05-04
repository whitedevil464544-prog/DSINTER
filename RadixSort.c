#include <stdio.h>  

// Function to get the maximum value in an array
int getMax(int a[], int n) {  
   int max = a[0], i;  
   for(i = 1; i < n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; // Maximum element from the array  
}  

// Function to implement radix sort  
void radixSort(int a[], int n) {  
  int big, nod = 0, steps, count[10], i, j, k, bucket[10][n], loc, div = 1;
  
  big = getMax(a, n);
  
  // Count the number of digits in the largest number
  while (big > 0) {
    nod++;
    big = big / 10;
  }

  for (steps = 1; steps <= nod; steps++) {
    // Initialize count array
    for (j = 0; j < 10; j++) {
      count[j] = 0;
    }
    
    // Distribute elements into buckets
    for (i = 0; i < n; i++) {
      loc = (a[i] / div) % 10;
      bucket[loc][count[loc]++] = a[i];
    }

    // Collect elements back into the array
    k = 0;
    for (j = 0; j < 10; j++) {  // Looping through digits 0-9
      for (i = 0; i < count[j]; i++) {
        a[k++] = bucket[j][i];
      }
    }

    // Move to the next digit
    div = div * 10;
  }
}

// Function to print array elements  
void printArray(int a[], int n) { 
  int i; 
  for (i = 0; i < n;i++) {  
    printf("%d\t", a[i]);  
  }  
  printf("\n");  
}  

int main() {  
  int a[100],n,i;
  printf("\nEnter No.of elements ");
  scanf("%d",&n);
  for (i=0;i<n;i++) {  
    scanf("%d",&a[i]);  
  }  
  printf("Before sorting, array elements are:\n");  
  printArray(a, n);  
  radixSort(a, n);  
  printf("After applying Radix sort, array elements are:\n");  
  printArray(a, n);  
  return 0;
}
