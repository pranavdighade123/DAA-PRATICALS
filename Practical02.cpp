/*
Implement Binary search program with Divide and Conquer design strategy for n numbers
using C++. Discuss Best, Average and Worst time complexity.
*/

#include <iostream>
#include <vector>

// Binary Search function
int binarySearch(const std::vector<int>& arr, int target, int left, int right) {
    if (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;  // Element found, return its index
        }

        if (arr[mid] < target) {
            return binarySearch(arr, target, mid + 1, right); // Search in the right half
        }

        return binarySearch(arr, target, left, mid - 1); // Search in the left half
    }

    return -1;  // Element not found
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;

    std::cout << "Enter the number to search: ";
    std::cin >> target;

    int result = binarySearch(arr, target, 0, arr.size() - 1);

    if (result != -1) {
        std::cout << "Element found at index " << result << std::endl;
    } else {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}

/*
Best case: O(1)
Average case: O(log n)
Worst case: O(log n)
*/


/*
Output:
Enter the number to search: 8
Element found at index 7
*/