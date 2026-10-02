#include <stdio.h>
#include <stdint.h>

# define NOT_FOUND -1

/**
 * Get the ordered array, first index, last index, and the target value
 *  
 * 0. If first index is greater than last index:
 * 		return not_found
 * 
 * 1. Calculate the middle index (mid)
 * 
 * 2. If array[mid] is equal to target:
 * 		return mid
 * 
 * 3. If array[mid] is greater than target:
 * 		Repeat the search from left to mid - 1
 * 
 * 4. If array[mid] is less than target:
 * 		Repeat the search from mid + 1 to right
 **/

# define print(value, index)\
		{\
			if (index != NOT_FOUND)\
				printf("Value "#value" is in the array\n");\
			else\
				printf("** Value "#value" is not in the array **\n");\
		}\


int	binary_search(const int *arr, const int size, const int target_value) {
	int left = 0;
	int right = size - 1;

	if (arr == NULL)
		return (NOT_FOUND);

	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == target_value)
			return (mid);
		if (arr[mid] > target_value)
			right = mid - 1;
		else if (arr[mid] < target_value)
			left = mid + 1;
	}
	return (NOT_FOUND);
}

# define N 5
int main(void) {

	int arr[N];

	for (int i = N; i > 0; --i)
		arr[i - 1] = i;
	
	int index = binary_search(arr, N, 4);
	printf("Looking for number 4\n");
	print(4, index)
	
	index = binary_search(arr, N, 12);
	printf("Looking for number 12\n");
	print(12, index)
	
	printf("Looking for number 2\n");
	index = binary_search(arr, N, 2);
	print(2, index)

	printf("Looking for number 22\n");
	index = binary_search(arr, N, 22);
	print(22, index)
	return (0);
}
