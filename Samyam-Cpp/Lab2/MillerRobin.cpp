#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

long long modularExponentiation(long long a, long long b, long long m) {
    long long result = 1;
    a = a % m;
    while (b > 0) {
        if (b & 1) 
            result = (result * a) % m;
        b = b >> 1; 
        a = (a * a) % m;
    }
    return result;
}

bool millerRabinTest(long long n, int k) {
    if (n <= 1 || n == 4) return false;
    if (n <= 3) return true;

    long long d = n - 1;
    while (d % 2 == 0)
        d /= 2;
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4);
        long long x = modularExponentiation(a, d, n);

        if (x == 1 || x == n - 1)
            continue;
        while (d != n - 1) {
            x = (x * x) % n;
            d *= 2;

            if (x == 1) return false;
            if (x == n - 1) continue;
        }
        return false;
    }
    return true;
}

int main() {
    srand(time(0)); 

    long long num;
    int iterations;

    cout << "Enter a number to check for primality: ";
    cin >> num;

    cout << "Enter number of iterations for Miller-Rabin test: ";
    cin >> iterations;

    if (millerRabinTest(num, iterations))
        cout << num << " is likely prime." << endl;
    else
        cout << num << " is composite." << endl;

    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
