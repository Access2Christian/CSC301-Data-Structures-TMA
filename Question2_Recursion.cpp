
/*
 * CSC 301 - Data Structures
 * Tutor-Marked Assessment: Question 2
 * Solving Problems Using Recursion
 *
 * Name: Christian Nnaji
 * Matric No: 2024/B/SENG/0246
 * Student ID: 30037606
 */

#include <iostream>
#include <string>
using namespace std;

// ============================
// FUNCTION 1: FACTORIAL
// ============================
// Base Case: When n is 0 or 1, factorial is 1.
// Recursive Case: n * factorial(n - 1)
// The function keeps multiplying n by the factorial of (n-1)
// until it reaches the base case.
int factorial(int n) {
    // Handle negative input
    if (n < 0) {
        cout << "  [Note: Factorial is not defined for negative numbers]" << endl;
        return -1;
    }
    // Base case
    if (n == 0 || n == 1) {
        return 1;
    }
    // Recursive case
    return n * factorial(n - 1);
}

// ============================
// FUNCTION 2: FIBONACCI
// ============================
// Base Case: When n is 0, return 0. When n is 1, return 1.
// Recursive Case: fib(n) = fib(n-1) + fib(n-2)
// Each number is the sum of the two numbers before it.
int fibonacci(int n) {
    // Base cases
    if (n == 0) return 0;
    if (n == 1) return 1;
    // Recursive case: sum of two preceding values
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// Helper function to print the first n Fibonacci numbers
void printFibonacciSequence(int count) {
    cout << "  First " << count << " Fibonacci numbers: ";
    for (int i = 0; i < count; i++) {
        cout << fibonacci(i);
        if (i < count - 1) cout << ", ";
    }
    cout << endl;
}

// ============================
// FUNCTION 3: STRING REVERSAL
// ============================
// Base Case: If the string is empty or has one character, return it as is.
// Recursive Case: Take the first character, reverse the rest,
// then put the first character at the end.
string reverseString(string str) {
    // Base case
    if (str.length() <= 1) {
        return str;
    }
    // Recursive case: reverse the substring from index 1 onward,
    // then append the first character at the end
    return reverseString(str.substr(1)) + str[0];
}

// ============================
// FUNCTION 4: BINARY SEARCH (Recursive)
// ============================
// Base Case: If low > high, the element is not in the array (return -1).
//            If the middle element equals the target, return its index.
// Recursive Case: If target < middle element, search the left half.
//                 If target > middle element, search the right half.
int binarySearch(int arr[], int low, int high, int target) {
    // Base case: element not found
    if (low > high) {
        return -1;
    }

    // Calculate middle index (avoids integer overflow)
    int mid = low + (high - low) / 2;

    // Base case: element found
    if (arr[mid] == target) {
        return mid;
    }

    // Recursive case: search appropriate half
    if (target < arr[mid]) {
        return binarySearch(arr, low, mid - 1, target);     // search left half
    } else {
        return binarySearch(arr, mid + 1, high, target);    // search right half
    }
}

int main() {
    cout << "============================================" << endl;
    cout << "   CSC 301 - Recursion Problems            " << endl;
    cout << "   Christian Nnaji | 2024/B/SENG/0246      " << endl;
    cout << "============================================" << endl;

    // ===== TESTING FACTORIAL =====
    cout << "\n--- FACTORIAL FUNCTION ---" << endl;

    // Test 1: Normal case
    cout << "  Factorial of 5: " << factorial(5) << endl;

    // Test 2: Edge case - factorial of 0
    cout << "  Factorial of 0: " << factorial(0) << endl;

    // Test 3: Larger number
    cout << "  Factorial of 8: " << factorial(8) << endl;

    // Test 4: Edge case - factorial of 1
    cout << "  Factorial of 1: " << factorial(1) << endl;

    // ===== TESTING FIBONACCI =====
    cout << "\n--- FIBONACCI FUNCTION ---" << endl;

    // Test 1: Generate first 8 numbers
    printFibonacciSequence(8);

    // Test 2: Specific index
    cout << "  Fibonacci at index 10: " << fibonacci(10) << endl;

    // Test 3: Edge case - index 0
    cout << "  Fibonacci at index 0: " << fibonacci(0) << endl;

    // Test 4: Edge case - index 1
    cout << "  Fibonacci at index 1: " << fibonacci(1) << endl;

    // ===== TESTING STRING REVERSAL =====
    cout << "\n--- STRING REVERSAL FUNCTION ---" << endl;

    // Test 1: Normal string
    string word1 = "Christian";
    cout << "  Reverse of \"" << word1 << "\": " << reverseString(word1) << endl;

    // Test 2: Palindrome
    string word2 = "madam";
    cout << "  Reverse of \"" << word2 << "\": " << reverseString(word2) << endl;

    // Test 3: Single character (edge case)
    string word3 = "A";
    cout << "  Reverse of \"" << word3 << "\": " << reverseString(word3) << endl;

    // Test 4: Empty string (edge case)
    string word4 = "";
    cout << "  Reverse of \"\" (empty): \"" << reverseString(word4) << "\"" << endl;

    // ===== TESTING BINARY SEARCH =====
    cout << "\n--- BINARY SEARCH FUNCTION ---" << endl;

    // Test array (must be sorted for binary search)
    int sortedArray[] = {2, 8, 15, 23, 37, 42, 56, 71, 89};
    int arraySize = 9;

    cout << "  Array: {2, 8, 15, 23, 37, 42, 56, 71, 89}" << endl;

    // Test 1: Element in the middle
    int target1 = 37;
    int result1 = binarySearch(sortedArray, 0, arraySize - 1, target1);
    cout << "  Search for " << target1 << ": Found at index " << result1 << endl;

    // Test 2: Element at the beginning
    int target2 = 2;
    int result2 = binarySearch(sortedArray, 0, arraySize - 1, target2);
    cout << "  Search for " << target2 << ": Found at index " << result2 << endl;

    // Test 3: Element not in array
    int target3 = 50;
    int result3 = binarySearch(sortedArray, 0, arraySize - 1, target3);
    cout << "  Search for " << target3 << ": ";
    if (result3 == -1) cout << "Not found in the array" << endl;
    else cout << "Found at index " << result3 << endl;

    // Test 4: Edge case - empty array (simulated with low > high)
    int target4 = 10;
    int result4 = binarySearch(sortedArray, 0, -1, target4);
    cout << "  Search in empty array for " << target4 << ": ";
    if (result4 == -1) cout << "Not found (empty array)" << endl;
    else cout << "Found at index " << result4 << endl;

    cout << "\n============================================" << endl;
    cout << "   Program Completed Successfully           " << endl;
    cout << "============================================" << endl;

    return 0;
}

