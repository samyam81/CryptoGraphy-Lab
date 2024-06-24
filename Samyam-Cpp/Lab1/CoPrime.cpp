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

bool areCoprime(int num1, int num2) {
    return euclideanGCD(num1, num2) == 1;
}

int main() {
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;

    if (areCoprime(num1, num2)) {
        cout << num1 << " and " << num2 << " are coprime." << endl;
    } else {
        cout << num1 << " and " << num2 << " are not coprime." << endl;
    }

    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    
    return 0;
}
