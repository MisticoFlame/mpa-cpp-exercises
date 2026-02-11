#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

struct KnapsackData {
    int M;                 // capacity
    int n;                 // number of items
    vector<int> weight;    // 1-based
    vector<float> value;   // 1-based
};

KnapsackData readKnapsackFile(const string& filename) {
    ifstream in(filename);
    if (!in) {
        cerr << "Error: cannot open file " << filename << "\n";
        exit(1);
    }

    KnapsackData data;
    in >> data.M;
    in >> data.n;

    data.weight.assign(data.n + 1, 0);
    data.value.assign(data.n + 1, 0.0f);

    for (int i = 1; i <= data.n; i++) in >> data.weight[i];
    for (int i = 1; i <= data.n; i++) in >> data.value[i];

    return data;
}

float knapsackDP(int M, int n, const vector<int>& w, const vector<float>& v) {
    vector<vector<float>> T(n + 1, vector<float>(M + 1, 0.0f));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= M; j++) {
            if (w[i] > j) {
                T[i][j] = T[i - 1][j];
            } else {
                float take = v[i] + T[i - 1][j - w[i]];
                float skip = T[i - 1][j];
                T[i][j] = (take > skip) ? take : skip;
            }
        }
    }

    // Print chosen items (like your solution array)
    vector<int> chosen(n + 1, 0);
    int i = n, j = M;
    while (i > 0 && j > 0) {
        if (T[i][j] != T[i - 1][j]) {
            chosen[i] = 1;
            j -= w[i];
        }
        i--;
    }

    cout << "\nSelected items:\n";
    for (int k = 1; k <= n; k++) {
        if (chosen[k] == 1) cout << "Item " << k << " selected\n";
        else cout << "Item " << k << " not selected\n";
    }

    return T[n][M];
}

int main() {
    string filename;
    cout << "Which file do you want to open? ";
    cin >> filename;

    KnapsackData data = readKnapsackFile(filename);

    cout << "\nM (capacity): " << data.M << "\n";
    cout << "n (items): " << data.n << "\n";

    cout << "Weights: ";
    for (int i = 1; i <= data.n; i++) cout << data.weight[i] << " ";
    cout << "\n";

    cout << "Values:  ";
    for (int i = 1; i <= data.n; i++) cout << data.value[i] << " ";
    cout << "\n";

    float best = knapsackDP(data.M, data.n, data.weight, data.value);
    cout << "\nBest total value: " << best << "\n";

    return 0;
}
