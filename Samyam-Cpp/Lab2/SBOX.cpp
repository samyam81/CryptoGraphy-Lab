#include <iostream>
#include <bitset>
#include <string>

using namespace std;

int S1[4][16] = {
    {14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
    {0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
    {4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
    {15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}
};

bitset<4> getS1Output(bitset<6> input) {
    int row = (input[5] << 1) + input[0];
    int col = (input[4] << 3) + (input[3] << 2) + (input[2] << 1) + input[1];
    int value = S1[row][col];
    return bitset<4>(value);
}

int main() {
    string input_string;
    cout << "Enter a 6-bit binary input: ";
    cin >> input_string;
    
    if (input_string.length() != 6) {
        cerr << "Error: Input must be exactly 6 bits long." << endl;
        return 1;
    }
    
    bitset<6> input(input_string);
    bitset<4> output = getS1Output(input);
    
    cout << "Input to S1: " << input << endl;
    cout << "Output of S1: " << output << endl;

    cout<<"Name: Samyam Subedi \nRoll No: 86 \nSection: C"<<endl;
    return 0;
}
