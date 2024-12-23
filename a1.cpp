#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    cout << "Enter n (0 <= n <= 30): ";
    cin >> n;

    if (n < 0 || n > 30) {
        cout << "Invalid input. Please enter a value between 0 and 30." << endl;
        return 1;
    }

    cout << "F(" << n << ") = " << fibonacci(n) << endl;

    return 0;
}
