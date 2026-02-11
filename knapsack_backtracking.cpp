#include <iostream>
#include <vector>

using namespace std;

float weightedSum(const vector<int>& X, const vector<float>& P, int k) {
    float sum = 0.0f;
    for (int i = 1; i <= k; i++) sum += X[i] * P[i];
    return sum;
}

void knapsackBacktracking(float M,
                          const vector<float>& P,
                          const vector<float>& V,
                          vector<int>& X,
                          int k,
                          vector<int>& Xbest,
                          float &Vbest,
                          int n) {
    if (k > n) return;

    for (int i = 0; i <= 1; i++) {
        X[k] = i;

        float currentWeight = weightedSum(X, P, k);
        if (currentWeight <= M) {
            if (k == n) {
                float currentValue = weightedSum(X, V, k);
                if (currentValue > Vbest) {
                    Vbest = currentValue;
                    Xbest = X;
                }
            } else {
                knapsackBacktracking(M, P, V, X, k + 1, Xbest, Vbest, n);
            }
        }
    }
}

int main() {
    int n;
    float M;

    cout << "Knapsack capacity: ";
    cin >> M;

    cout << "Total number of items: ";
    cin >> n;

    vector<float> P(n + 1), V(n + 1);
    vector<int> X(n + 1, 0), Xbest(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cout << "Weight of item " << i << ": ";
        cin >> P[i];
    }

    for (int i = 1; i <= n; i++) {
        cout << "Value of item " << i << ": ";
        cin >> V[i];
    }

    float Vbest = 0.0f;
    knapsackBacktracking(M, P, V, X, 1, Xbest, Vbest, n);

    cout << "\nBest total value: " << Vbest << "\n";
    cout << "Selected items (0/1): ";
    for (int i = 1; i <= n; i++) cout << Xbest[i] << " ";
    cout << "\n";

    return 0;
}
