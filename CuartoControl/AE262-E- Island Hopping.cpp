#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n, grupo = 0;
    while (scanf("%d", &n) == 1 && n != 0) {
        vector<double> x(n), y(n), m(n);
        double total = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%lf %lf %lf", &x[i], &y[i], &m[i]);
            total += m[i];
        }

        vector<double> dist(n, 1e18), tiempo(n, 0);
        vector<int> padre(n, -1);
        vector<bool> visto(n, false);
        dist[0] = 0;
        double suma = 0;

        for (int k = 0; k < n; ++k) {
            int u = -1;
            for (int i = 0; i < n; ++i)
                if (!visto[i] && (u == -1 || dist[i] < dist[u])) u = i;
            visto[u] = true;

            if (padre[u] != -1)
                tiempo[u] = max(tiempo[padre[u]], dist[u]);
            suma += tiempo[u] * m[u];

            for (int v = 0; v < n; ++v) {
                if (visto[v]) continue;
                double d = hypot(x[u] - x[v], y[u] - y[v]);
                if (d < dist[v]) {
                    dist[v] = d;
                    padre[v] = u;
                }
            }
        }

        if (grupo > 0) printf("\n");
        
        printf("Island Group: %d Average %.2f\n", ++grupo, suma / total);
    }
    return 0;
}