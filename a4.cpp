#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        int start = 1;   // Start of the range
        int step = 1;    // Step size between remaining elements
        int remaining = n; // Number of elements remaining
        bool leftToRight = true; // Direction of elimination

        while (remaining > 1) {
            // Eliminate numbers based on the direction
            if (leftToRight || remaining % 2 == 1) {
                start += step;
            }

            step *= 2;        // Step size doubles each round
            remaining /= 2;   // Half of the elements are removed
            leftToRight = !leftToRight; // Alternate direction
        }

        return start; // The last remaining number
    }
};

int main() {
    Solution solution;

    // Example 1
    int n1 = 9;
    cout << "Input: n = " << n1 << "\nOutput: " << solution.lastRemaining(n1) << endl;

    // Example 2
    int n2 = 1;
    cout << "Input: n = " << n2 << "\nOutput: " << solution.lastRemaining(n2) << endl;

    return 0;
}
