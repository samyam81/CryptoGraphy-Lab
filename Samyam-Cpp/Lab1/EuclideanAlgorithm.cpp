#include <iostream>

using namespace std;

int euclideanGCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;

    // Input two numbers
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    // Calculate and display the GCD
    int gcd = euclideanGCD(num1, num2);
    cout << "GCD of " << num1 << " and " << num2 << " is: " << gcd << endl;

    return 0;
}
