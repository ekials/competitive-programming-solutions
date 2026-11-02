#include <algorithm>
#include <climits>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

vector<int> padre, tam;

int buscar(int x) {
    while (padre[x] != x) {
        padre[x] = padre[padre[x]];
        x = padre[x];
    }
    return x;
}

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m) == 2 && (n != 0 || m != 0)) {
        padre.resize(n + 1);
        tam.resize(n + 1);
        iota(padre.begin(), padre.end(), 0);
        fill(tam.begin(), tam.end(), 1);

        long long maximo = LLONG_MIN;
        int mejor = 0;
        for (int i = 0; i < m; ++i) {
            int u, v;
            long long w;
            scanf("%d %d %lld", &u, &v, &w);
            if (w < maximo) continue;
            if (w > maximo) {
                maximo = w;
                iota(padre.begin(), padre.end(), 0);
                fill(tam.begin(), tam.end(), 1);
                mejor = 0;
            }
            int ru = buscar(u), rv = buscar(v);
            if (ru != rv) {
                padre[ru] = rv;
                tam[rv] += tam[ru];
            }
            mejor = max(mejor, tam[rv]);
        }
        printf("%d\n", mejor);
    }
    return 0;
}