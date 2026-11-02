#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;
vector<string> g;

void dfs(int i, int j) {
    if (i < 0 || i >= n || j < 0 || j >= n || g[i][j] != '1') return;
    g[i][j] = '0';
    for (int di = -1; di <= 1; ++di)
        for (int dj = -1; dj <= 1; ++dj)
            dfs(i + di, j + dj);
}

int main() {
    int imagen = 0;
    while (cin >> n) {
        g.assign(n, "");
        for (auto& fila : g) cin >> fila;

        int total = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (g[i][j] == '1') {
                    ++total;
                    dfs(i, j);
                }

        cout << "Image number " << ++imagen << " contains " << total << " war eagles.\n";
    }
    return 0;
}