

#include <stdio.h>

# define NOT_FOUND -1

const int N = 4;

# define print(value, index)\
		{\
			if (index != NOT_FOUND)\
				printf("Value "#value" is in the array\n");\
			else\
				printf("**Value "#value" is not in the array**\n");\
		}\



extern int _binary_search(int *arr, int size, int target);


int main(void) {

	int arr[N];

	for (int i = N; i > 0; --i)
		arr[i - 1] = i;
	
	int index = _binary_search(arr, N, 4);
	printf("Looking for number 4\n");
	print(4, index)
	
	index = _binary_search(arr, N, 12);
	printf("Looking for number 12\n");
	print(12, index)
	
	printf("Looking for number 2\n");
	index = _binary_search(arr, N, 2);
	print(2, index)

	printf("Looking for number 22\n");
	index = _binary_search(arr, N, 22);
	print(22, index)
	return (0);
}
