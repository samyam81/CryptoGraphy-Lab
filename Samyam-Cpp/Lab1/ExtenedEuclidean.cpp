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

void displayIterations(const vector<vector<int>>& iterations) {
    cout << "Iteration |  a   |  b   |  x0  |  y0  |  x1  |  y1  |  q   |" << endl;
    cout << "-----------------------------------------------------------" << endl;
    int count = 1;
    for (const auto& iteration : iterations) {
        cout << "    " << count << "     | ";
        for (int i = 0; i < iteration.size(); ++i) {
            cout << "  " << iteration[i] << "  | ";
        }
        cout << endl;
        ++count;
    }
}

int main() {
    int a, b;

    cout << "Enter the value of a: ";
    cin >> a;
    cout << "Enter the value of b: ";
    cin >> b;

    vector<vector<int>> iterations = extendedEuclideanAlgorithm(a, b);

    cout << "\nIterations of Extended Euclidean Algorithm:" << endl;
    displayIterations(iterations);

    return 0;
}
