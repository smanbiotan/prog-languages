/*
// Test II — CER
#include <stdio.h>

// Scenario: a function meant to copy the first n values of source into
// a fixed-size buffer of 10 integers.
void copyFirstN(int source[], int n, int buffer[10]) {
    for (int i = 0; i < n; i++) {   // FIX: changed i <= n to i < n
        buffer[i] = source[i];
    }
}

int main(void) {
    int data[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int buf[10];

    copyFirstN(data, 10, buf);

    printf("Copied buffer: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", buf[i]);
    }
    printf("\n");

    return 0;
}

Claim: Not safe — it overflows the buffer.

Evidence:

Loop condition i <= n runs 11 times (i = 0..10) instead of 10.
buffer[10] only has valid indices 0–9, so buffer[10] = ... writes out of bounds.
data[10] also only has valid indices 0–9, so source[10] reads out of bounds.

Reasoning: This is an off-by-one bounds error — 
for a size-10 array, the last valid index is 9, not 10, but <= lets the loop treat n itself as a valid index.
That extra iteration reads garbage from outside data and writes it outside buf, both undefined behavior. 
Fix: change i <= n to i < n.
*/

/*
// 3.
#include <stdio.h>

void rotateLeft(int arr[], int n, int k) {
    int i, j, temp;

    if (n <= 0)
        return;

    k = k % n;
                   
    for (i = 0, j = k - 1; i < j; i++, j--) {        // arr[] = {1, 2, 3, 4, 5}; k = 2;
        temp = arr[i];     // temp = 1 value sa array   i = [0] which is value = 1, j = [1] which is value = 2
        arr[i] = arr[j];   // arr[i] = 2               
        arr[j] = temp;     // arr[j] = 1               // first traverse {2, 1, 3, 4, 5}
    }

    for (i = k, j = n - 1; i < j; i++, j--) {   // i = k which is (2); j = 5 - 1 which is = (4); 
        temp = arr[i];        // temp = 3  value sa array   
        arr[i] = arr[j];      // arr[i] = 5     
        arr[j] = temp;        // arr[j] = 3     // second traverse {2, 1, 5, 4, 3}
    }

    for (i = 0, j = n - 1; i < j; i++, j--) {              // i = 0 which is value niya 2
        temp = arr[i];    // temp = 2;   value sa array    // j = 5 - 1 which is = (4);              
        arr[i] = arr[j];  // arr[i] = 3;
        arr[j] = temp;    // arr[j] = 2;         // final traverse {3, 4, 5, 1, 2} so mao ni ang final result.
    }                                                                                
} 

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    rotateLeft(arr, n, k);

    printf("Rotated array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
*/

/*
// 2.
#include <stdio.h>

void insertAt(int arr[], int *n, int cap, int pos, int value) {

  if (*n >= cap) {
        return false;
    }

    if (pos < 0 || pos > *n) {
        return false;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    (*n)++;
    return true;
}

int main(void) {
    int arr[5] = {1, 2, 3, 4};
    int n = 4;
    int cap = 5;

    printf("Before insert: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    if (insertAt(arr, &n, cap, 1, 99)) {
        printf("Inserted 99 at position 1\n");
    } else {
        printf("Insert failed\n");
    }

    printf("After insert: ");
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");

    if (!insertAt(arr, &n, cap, 2, 42)) {
        printf("Insert rejected: array is full (n=%d, cap=%d)\n", n, cap);
    }

    if (!insertAt(arr, &n, cap, 10, 7)) {
        printf("Insert rejected: invalid position\n");
    }

    return 0;
}
*/


/*
// 1.
#include <stdio.h>

int removeDuplicates(int arr[], int n);

int main() {

  int arr[] = {1, 3, 3, 2, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);

  int newLen = removeDuplicates(arr, n);

  for(int i = 0; i < newLen; i++){
    printf("%d ", arr[i]);
  }

  return 0;
}

int removeDuplicates(int arr[], int n) {
  int newLength = 0;

  for(int i = 0; i < n; i++) { // sa outer loop i-check lang ang every element sa original array nimo.
    int isDuplicate = 0;

    for(int j = 0; j < newLength; j++) { 
      if(arr[i] == arr[j]){ // i-check ang original array which is arr[i] kung na saved na saimong unique portion 
        isDuplicate = 1;
        break;
      }
    }

    if(isDuplicate == 0){
      arr[newLength] = arr[i];
      newLength++;
    }
  }

  return newLength;

}
*/


/*
#include <stdio.h>

void reverseInPlace(int arr[], int n);

int main() {

  int arr[] = {1, 2, 3, 4, 5, 6, 9, -1};
  int n = 8;

  printf("Original values: ");
  for(int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }

  reverseInPlace(arr, n);

  printf("\nReversed Values: ");
    for(int i = 0; i < n; i++) {
    printf("%d", arr[i]);
  }

return 0;

}

void reverseInPlace(int arr[], int n){

    int left = 0;
    int right = n - 1;
    int temp;

    while(left < right) {
      
      temp = arr[left];
      arr[left] = arr[right];
      arr[right] = temp;

      left++;
      right--;
    }
}
*/


/*
#include <stdio.h>

int countEven(int arr[], int n);

int main() {

  int arr[] = {1, 2, 3, 4, 5, 6, 9, -1};
  int n = 8;

  printf("%d", countEven(arr, n));

  return 0;
}

int countEven(int arr[], int n) {

  int count = 0;

  for(int i = 0; i < n; i++) {
    if(arr[i] % 2 == 0) {
      count++;
    }
  }
    return count;
}
*/
