#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    for (int caso = 1; caso <= t; ++caso) {
        int n;
        long long r;
        scanf("%d %lld", &n, &r);
        vector<long long> x(n), y(n);
        for (int i = 0; i < n; ++i) scanf("%lld %lld", &x[i], &y[i]);

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        vector<bool> visto(n, false);
        dist[0] = 0;

        int estados = 1;
        double carreteras = 0, trenes = 0;

        for (int k = 0; k < n; ++k) {
            int u = -1;
            for (int i = 0; i < n; ++i)
                if (!visto[i] && (u == -1 || dist[i] < dist[u])) u = i;
            visto[u] = true;

            if (dist[u] <= r * r) {
                carreteras += sqrt((double)dist[u]);
            } else {
                trenes += sqrt((double)dist[u]);
                ++estados;
            }

            for (int v = 0; v < n; ++v) {
                if (visto[v]) continue;
                long long dx = x[u] - x[v], dy = y[u] - y[v];
                long long d = dx * dx + dy * dy;
                if (d < dist[v]) dist[v] = d;
            }
        }

        printf("Case #%d: %d %lld %lld\n", caso, estados, llround(carreteras), llround(trenes));
    }
    return 0;
}