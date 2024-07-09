#include <iostream>
#include <vector>

using namespace std;

int totient(int n) {
    int result = n;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p == 0) {
            while (n % p == 0)
                n /= p;
            result -= result / p;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}

int main() {
    int number;
    cout << "Enter a positive number to compute its Totient value: ";
    cin >> number;
    
    if (number <= 0) {
        cerr << "Error: Input must be a positive integer." << endl;
        return 1;
    }
    
    int phi = totient(number);
    cout << "Totient(" << number << ") = " << phi << endl;
    
    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;

    return 0;
}
