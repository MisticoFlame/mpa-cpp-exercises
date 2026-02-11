#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int countOccurrences(int V[], int x, int n) {
    int times = 0;
    for (int i = 1; i <= n; i++) {
        if (V[i] == x) {
            times++;
        }
    }
    return times;
}

int main() {
    int n, x;
    int *VAny, *VBest, *VWorst;

    cout << "Enter the number you want to count: ";
    cin >> x;

    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Seed rand() so the "any case" looks random each run
    srand((unsigned)time(nullptr));

    VAny = new int[n + 1];
    VBest = new int[n + 1];
    VWorst = new int[n + 1];

    for (int i = 1; i <= n; i++) {
        VAny[i] = rand() % 9;   // 0..8
        VBest[i] = x;          // best case: all equal to x
        VWorst[i] = x - 1;     // worst case: none equals x
    }

    cout << "\nVAny: ";
    for (int i = 1; i <= n; i++) cout << VAny[i] << " ";

    cout << "\nVBest: ";
    for (int i = 1; i <= n; i++) cout << VBest[i] << " ";

    cout << "\nVWorst: ";
    for (int i = 1; i <= n; i++) cout << VWorst[i] << " ";

    cout << "\n\nCount of " << x << " in VAny:   " << countOccurrences(VAny, x, n);
    cout << "\nCount of " << x << " in VBest:  " << countOccurrences(VBest, x, n);
    cout << "\nCount of " << x << " in VWorst: " << countOccurrences(VWorst, x, n) << "\n";

    delete[] VAny;
    delete[] VBest;
    delete[] VWorst;

    return 0;
}
