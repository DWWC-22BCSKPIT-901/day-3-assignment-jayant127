#include <iostream>
using namespace std;

// Function to calculate factorial using recursion
int factorial(int n) {
    if (n == 0 || n == 1) return 1; // Base case
    return n * factorial(n - 1); // Recursive case
}

int main() {
    int n;
    cout << "Enter a number (0 <= N <= 15): ";
    cin >> n;

    if (n < 0 || n > 15) {
        cout << "Invalid input. Please enter a number between 0 and 15." << endl;
        return 1;
    }

    cout << n << "! = " << factorial(n) << endl;

    return 0;
}
