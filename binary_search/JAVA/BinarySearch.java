package JAVA;

public class BinarySearch {

	public static <T extends  Comparable<T>/*This will change*/> T binarySearch(T[] arr, T value) {
			int left = 0;
			int right = arr.length - 1;

			while (left <= right) {
				int mid = left + (right - left) / 2;
				int r = arr[mid].compareTo(value);
				if (r == 0)
					return  arr[mid];
				if (r > 0)
					right = mid - 1;
				else
					left = mid + 1;
			}
			return  null;
	}

	public static void main(String[] args) {
        // Test 1: Searching for an element present in an Integer array
        Integer[] numbers = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
        Integer target1 = 23;
        Integer result1 = binarySearch(numbers, target1);
        String actualOutput1 = (result1 != null ? "Found (" + result1 + ")" : "Not Found");
        String expectedOutput1 = "Found (23)";
        System.out.println("Test 1 | Result: " + actualOutput1 + " \t|\t Correct Output: " + expectedOutput1);

        // Test 2: Searching for an element NOT present in the Integer array
        Integer target2 = 15;
        Integer result2 = binarySearch(numbers, target2);
        String actualOutput2 = (result2 != null ? "Found (" + result2 + ")" : "Not Found");
        String expectedOutput2 = "Not Found";
        System.out.println("Test 2 | Result: " + actualOutput2 + " \t|\t Correct Output: " + expectedOutput2);

        // Test 3: Testing with a String array
        String[] words = {"apple", "banana", "cherry", "date", "fig", "grape"};
        String targetWord = "cherry";
        String resultWord = binarySearch(words, targetWord);
        String actualOutput3 = (resultWord != null ? "Found (" + resultWord + ")" : "Not Found");
        String expectedOutput3 = "Found (cherry)";
        System.out.println("Test 3 | Result: " + actualOutput3 + " |\t Correct Output: " + expectedOutput3);

        // Test 4: Edge case - Empty array
        Integer[] emptyArr = {};
        Integer resultEmpty = binarySearch(emptyArr, 5);
        String actualOutput4 = (resultEmpty != null ? "Found (" + resultEmpty + ")" : "Not Found");
        String expectedOutput4 = "Not Found";
        System.out.println("Test 4 | Result: " + actualOutput4 + " \t|\t Correct Output: " + expectedOutput4);
    }
}
