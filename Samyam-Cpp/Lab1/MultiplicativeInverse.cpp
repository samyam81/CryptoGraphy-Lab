#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> extendedEuclideanAlgorithm(int a, int b) {
    vector<vector<int>> iterations;
    int x0 = 1, y0 = 0, x1 = 0, y1 = 1; 
    int q, r, x2, y2;
    while (b != 0) {
        vector<int> iteration;
        iteration.push_back(a);
        iteration.push_back(b);
        iteration.push_back(x0);
        iteration.push_back(y0);
        iteration.push_back(x1);
        iteration.push_back(y1);
        q = a / b;
        r = a % b;
        x2 = x0 - q * x1;
        y2 = y0 - q * y1;
        a = b;
        b = r;
        x0 = x1;
        y0 = y1;
        x1 = x2;
        y1 = y2;

        iteration.push_back(q);
        iterations.push_back(iteration);
    }

    return iterations;
}

int multiplicativeInverse(int a, int n) {
    vector<vector<int>> iterations = extendedEuclideanAlgorithm(a, n);
    int x = iterations.back()[4];
    x %= n;
    if (x < 0) {
        x += n;
    }
    return x;
}

int main() {
    int number, modulo;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the modulo: ";
    cin >> modulo;
    int inverse = multiplicativeInverse(number, modulo);
    cout << "The multiplicative inverse of " << number << " modulo " << modulo << " is: " << inverse << endl;
    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
