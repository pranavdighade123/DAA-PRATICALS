/*
Aim: Sort a given set of n integer elements using Quick Sort method and compute its time
complexity. Run the program for varied values of n and record the time taken to sort. The
elements can be read from a user or can be generated using the random number generator.
Demonstrate using C++ how the divide and conquer method works along with its time
complexity analysis: worst case, average case and best case.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Function to perform quick sort
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    cout << "Sorted elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    return 0;
}


/*
The worst-case time complexity is O(n^2)    
The average-case time complexity is O(n log n)
The best-case time complexity is O(n log n)
*/

/*
Output:
Enter the number of elements: 4
Enter the elements:
45
12
89
2
Sorted elements: 2 12 45 89
*/