#include <iostream>

using namespace std;

int computeAdditiveInverse(int number, int modulo) {
    number %= modulo;
    if (number < 0) {
        number += modulo;
    }
    return modulo - number;
}

int main() {
    int number, modulo;

    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the modulo: ";
    cin >> modulo;

    int additiveInverse = computeAdditiveInverse(number, modulo);
    cout << "The additive inverse of " << number << " modulo " << modulo << " is: " << additiveInverse << endl;

    return 0;
}
