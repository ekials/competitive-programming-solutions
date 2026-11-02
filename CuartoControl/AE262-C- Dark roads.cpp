#include <algorithm>
#include <cstdio>
#include <numeric>
#include <vector>

using namespace std;

struct Arista {
    int x, y, z;
};

vector<int> padre;

int buscar(int x) {
    while (padre[x] != x) {
        padre[x] = padre[padre[x]];
        x = padre[x];
    }
    return x;
}

int main() {
    int m, n;
    while (scanf("%d %d", &m, &n) == 2 && (m != 0 || n != 0)) {
        vector<Arista> aristas(n);
        long long total = 0;
        for (auto& a : aristas) {
            scanf("%d %d %d", &a.x, &a.y, &a.z);
            total += a.z;
        }
        sort(aristas.begin(), aristas.end(),
             [](const Arista& a, const Arista& b) { return a.z < b.z; });

        padre.resize(m);
        iota(padre.begin(), padre.end(), 0);

        long long usado = 0;
        for (const auto& a : aristas) {
            int rx = buscar(a.x), ry = buscar(a.y);
            if (rx != ry) {
                padre[rx] = ry;
                usado += a.z;
            }
        }
        printf("%lld\n", total - usado);
    }
    return 0;
}