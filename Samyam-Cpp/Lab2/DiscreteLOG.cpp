#include <iostream>
#include <cmath>

using namespace std;

int discreteLog(int g, int y, int n) {
    for (int x = 0; x < n - 1; ++x) {
        if (int(pow(g, x)) % n == y)
            return x;
    }
    return -1; 
}

int main() {
    int g, y, n;
    cout << "Enter the base (primitive root) g: ";
    cin >> g;
    cout << "Enter the number y: ";
    cin >> y;
    cout << "Enter the modulo n: ";
    cin >> n;
    int x = discreteLog(g, y, n);
    if (x == -1) {
        cout << "No discrete logarithm found for g^x ≡ y mod n." << endl;
    } else {
        cout << "Discrete logarithm of " << y << " with respect to base " << g << " modulo " << n << " is: " << x << endl;
    }
    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
