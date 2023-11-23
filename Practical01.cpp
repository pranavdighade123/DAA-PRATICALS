/*
Write C++ program to find factorial of a given number using
(i)Recursion
(ii)Iteration Compare time and space complexity of both the designs.
*/


#include <iostream>

// Function to calculate factorial using recursion
unsigned long long factorialRecursion(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorialRecursion(n - 1);
}

/*
Best case: O(1)
Average case: O(n)
Worst case: O(n)
*/

// Function to calculate factorial using iteration
unsigned long long factorialIteration(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

/*
Best case: O(1)
Average case: O(n)
Worst case: O(n)
*/

int main() {
    int num;
    std::cout << "Enter a non-negative integer: ";
    std::cin >> num;

    if (num < 0) {
        std::cout << "Factorial is not defined for negative numbers." << std::endl;
    } else {
        // Using recursion
        unsigned long long resultRecursion = factorialRecursion(num);
        std::cout << "Factorial using recursion: " << resultRecursion << std::endl;

        // Using iteration
        unsigned long long resultIteration = factorialIteration(num);
        std::cout << "Factorial using iteration: " << resultIteration << std::endl;
    }

    return 0;
}


/*
Output:
Enter a non-negative integer: 5
Factorial using recursion: 120
Factorial using iteration: 120
*/