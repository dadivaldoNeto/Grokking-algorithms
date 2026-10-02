

#include <stdio.h>

const int N = 4;

extern int _binary_search(int *arr, int size, int target);


int main(void) {
  
  int arr[N];
  for (int i = 0; i < N; ++i)
    arr[i] = 1 + i;

  int result = _binary_search(arr, N, 2);
  printf("Result is: %d\n", result);
}

