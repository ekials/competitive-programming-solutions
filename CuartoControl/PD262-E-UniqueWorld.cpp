#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> ady;
vector<int> camino;

bool dfs(int u, int padre, int t) {
    if (u == t) return true;
    for (auto [v, c] : ady[u]) {
        if (v == padre) continue;
        camino.push_back(c);
        if (dfs(v, u, t)) return true;
        camino.pop_back();
    }
    return false;
}

int main() {
    int casos;
    scanf("%d", &casos);
    for (int caso = 0; caso < casos; ++caso) {
        if (caso > 0) printf("\n");
        int n, m;
        scanf("%d %d", &n, &m);
        ady.assign(n + 1, {});
        for (int i = 0; i < m; ++i) {
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            ady[a].push_back({b, c});
            ady[b].push_back({a, c});
        }

        int k;
        scanf("%d", &k);
        while (k--) {
            int s, t, costo;
            scanf("%d %d %d", &s, &t, &costo);

            camino.clear();
            dfs(s, 0, t);

            int base = 0;
            for (int c : camino) base += c;
            int extra = costo - base;

            if (camino.empty() || extra < 0 || extra % 2 != 0) {
                printf("No\n");
                continue;
            }

            int obj = extra / 2;
            set<int> usados(camino.begin(), camino.end() - 1);
            const int INF = 1e9;
            vector<int> dp(obj + 1, INF);
            dp[0] = 0;
            for (int c : usados)
                for (int x = c; x <= obj; ++x)
                    if (dp[x - c] + 1 < dp[x]) dp[x] = dp[x - c] + 1;

            if (dp[obj] == INF) printf("No\n");
            else printf("Yes %d\n", (int)camino.size() + 2 * dp[obj]);
        }
    }
    return 0;
}