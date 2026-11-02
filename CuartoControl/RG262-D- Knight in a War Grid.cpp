#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; ++caso) {
        int r, c, m, n, w;
        scanf("%d %d %d %d %d", &r, &c, &m, &n, &w);

        vector<vector<bool>> agua(r, vector<bool>(c, false));
        for (int i = 0; i < w; ++i) {
            int x, y;
            scanf("%d %d", &x, &y);
            agua[x][y] = true;
        }

        set<pair<int, int>> conjunto;
        for (int a : {m, -m})
            for (int b : {n, -n}) {
                conjunto.insert({a, b});
                conjunto.insert({b, a});
            }
        vector<pair<int, int>> movs(conjunto.begin(), conjunto.end());

        auto valido = [&](int x, int y) {
            return x >= 0 && x < r && y >= 0 && y < c && !agua[x][y];
        };

        vector<vector<bool>> visto(r, vector<bool>(c, false));
        vector<pair<int, int>> pila = {{0, 0}};
        visto[0][0] = true;
        int pares = 0, impares = 0;

        while (!pila.empty()) {
            auto [x, y] = pila.back();
            pila.pop_back();
            int grado = 0;
            for (auto [dx, dy] : movs) {
                int nx = x + dx, ny = y + dy;
                if (!valido(nx, ny)) continue;
                ++grado;
                if (!visto[nx][ny]) {
                    visto[nx][ny] = true;
                    pila.push_back({nx, ny});
                }
            }
            if (grado % 2 == 0) ++pares;
            else ++impares;
        }

        printf("Case %d: %d %d\n", caso, pares, impares);
    }
    return 0;
}