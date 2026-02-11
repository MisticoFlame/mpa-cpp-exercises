#include <iostream>
#include <stack>

using namespace std;

int computeRecursive(int x, int y) {
    if (x <= 4) {
        return x + y;
    } else {
        x = x - 4;
        y = y / 3;
        return computeRecursive(x, y) + x * y;
    }
}

int computeIterative(int x, int y) {
    stack<int> st;
    int result = 0;

    while (x > 4) {
        x = x - 4;
        y = y / 3;
        st.push(x * y);
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    result = result + x + y; // base case added at the end
    return result;
}

int main() {
    int num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Result (recursive): " << computeRecursive(num1, num2) << "\n";
    cout << "Result (iterative): " << computeIterative(num1, num2) << "\n";

    return 0;
}
