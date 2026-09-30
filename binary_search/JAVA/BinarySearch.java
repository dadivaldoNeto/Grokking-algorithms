package JAVA;

public class BinarySearch {
	
	public static <T extends  Number/*This will change*/> T binarySearch(T[] arr, T value) {
			int left = 0;
			int right = arr.length - 1;

			while (left <= right) {
				int mid = left + (right - left) / 2;
				if (arr[mid] == value)
					return  arr[mid];
			}
			return  arr[arr.length];
	}

	public static void main(String[] args) {

	}
}
