#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void insertionSortAscending(int *vect, int n) {
    for (int i = 2; i <= n; i++) {
        int x = vect[i];
        int j = i - 1;

        while (j > 0 && vect[j] > x) {
            vect[j + 1] = vect[j];
            j--;
        }
        vect[j + 1] = x;
    }
}

void insertionSortDescending(int *vect, int n) {
    for (int i = 2; i <= n; i++) {
        int x = vect[i];
        int j = i - 1;

        while (j > 0 && vect[j] < x) {
            vect[j + 1] = vect[j];
            j--;
        }
        vect[j + 1] = x;
    }
}

void printFirst(int *vect, int n, int howMany = 10) {
    int limit = (n < howMany) ? n : howMany;
    for (int i = 1; i <= limit; i++) cout << vect[i] << " ";
    cout << "\n";
}

int main() {
    int n, seed;
    cout << "Enter the seed: ";
    cin >> seed;

    cout << "Enter the array size: ";
    cin >> n;

    srand(seed);

    int *avgCase = new int[n + 1];
    int *bestCase = new int[n + 1];
    int *worstCase = new int[n + 1];

    // Average case: random
    for (int i = 1; i <= n; i++) avgCase[i] = rand();

    // Best case: already sorted ascending
    for (int i = 1; i <= n; i++) bestCase[i] = i;

    // Worst case: reverse sorted (descending)
    for (int i = 1; i <= n; i++) worstCase[i] = n - i + 1;

    clock_t start, end;
    double ms;

    cout << "\n--- Average case (random) ---\n";
    cout << "Before: ";
    printFirst(avgCase, n);

    start = clock();
    insertionSortAscending(avgCase, n);
    end = clock();
    ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "After:  ";
    printFirst(avgCase, n);
    cout << "Time: " << ms << " ms\n";

    cout << "\n--- Best case (already sorted) ---\n";
    cout << "Before: ";
    printFirst(bestCase, n);

    start = clock();
    insertionSortAscending(bestCase, n);
    end = clock();
    ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "After:  ";
    printFirst(bestCase, n);
    cout << "Time: " << ms << " ms\n";

    cout << "\n--- Worst case (reverse sorted) ---\n";
    cout << "Before: ";
    printFirst(worstCase, n);

    start = clock();
    insertionSortAscending(worstCase, n);
    end = clock();
    ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "After:  ";
    printFirst(worstCase, n);
    cout << "Time: " << ms << " ms\n";

    delete[] avgCase;
    delete[] bestCase;
    delete[] worstCase;

    return 0;
}
