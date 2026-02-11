#include <iostream>
#include <string>

using namespace std;

string toBinary(int a) {
    if (a == 0) return "0";
    if (a == 1) return "1";

    int quotient = a / 2;
    int remainder = a % 2;

    return toBinary(quotient) + to_string(remainder);
}

void binaryTrace(int a, int iteration) {
    if (a == 0 || a == 1) {
        cout << "Iteration " << iteration
             << " | a=" << a
             << " | quotient=" << a
             << " | remainder=" << a << "\n";
        return;
    }

    cout << "Iteration " << iteration
         << " | a=" << a
         << " | quotient=" << (a / 2)
         << " | remainder=" << (a % 2) << "\n";

    binaryTrace(a / 2, iteration + 1);
}

int main() {
    int a;
    cout << "Enter a number: ";
    cin >> a;

    if (a < 0) {
        cout << "Error: number must be non-negative.\n";
        return -1;
    }

    cout << "Binary representation of " << a << " is: " << toBinary(a) << "\n";
    cout << "Trace:\n";
    binaryTrace(a, 1);

    return 0;
}
