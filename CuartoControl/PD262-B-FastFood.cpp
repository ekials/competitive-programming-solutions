#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {
    int n, k, cadena = 0;
    while (scanf("%d %d", &n, &k) == 2 && (n != 0 || k != 0)) {
        vector<int> d(n + 1);
        for (int i = 1; i <= n; ++i) scanf("%d", &d[i]);

        vector<vector<int>> costo(n + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= n; ++i) {
            for (int j = i; j <= n; ++j) {
                int med = (i + j) / 2;
                for (int r = i; r <= j; ++r) costo[i][j] += abs(d[r] - d[med]);
            }
        }

        const int INF = 2e9;
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, INF));
        vector<vector<int>> corte(k + 1, vector<int>(n + 1, 0));
        dp[0][0] = 0;
        for (int c = 1; c <= k; ++c) {
            for (int j = c; j <= n; ++j) {
                for (int i = c - 1; i < j; ++i) {
                    if (dp[c - 1][i] == INF) continue;
                    int val = dp[c - 1][i] + costo[i + 1][j];
                    if (val < dp[c][j]) {
                        dp[c][j] = val;
                        corte[c][j] = i;
                    }
                }
            }
        }

        vector<int> ini(k + 1), fin(k + 1);
        int j = n;
        for (int c = k; c >= 1; --c) {
            ini[c] = corte[c][j] + 1;
            fin[c] = j;
            j = corte[c][j];
        }

        printf("Chain %d\n", ++cadena);
        for (int c = 1; c <= k; ++c) {
            int med = (ini[c] + fin[c]) / 2;
            if (ini[c] == fin[c])
                printf("Depot %d at restaurant %d serves restaurant %d\n", c, med, ini[c]);
            else
                printf("Depot %d at restaurant %d serves restaurants %d to %d\n", c, med, ini[c], fin[c]);
        }
        printf("Total distance sum = %d\n\n", dp[k][n]);
    }
    return 0;
}