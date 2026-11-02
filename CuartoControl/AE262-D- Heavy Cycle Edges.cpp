#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

struct Arista {
    int u, v;
    long long w;
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && (n != 0 || m != 0)) {
        vector<Arista> aristas(m);
        for (auto& a : aristas) cin >> a.u >> a.v >> a.w;
        sort(aristas.begin(), aristas.end(),
             [](const Arista& a, const Arista& b) { return a.w < b.w; });

        padre.resize(n);
        iota(padre.begin(), padre.end(), 0);

        vector<long long> res;
        for (const auto& a : aristas) {
            int ru = buscar(a.u), rv = buscar(a.v);
            if (ru == rv) res.push_back(a.w);
            else padre[ru] = rv;
        }

        if (res.empty()) {
            cout << "forest\n";
        } else {
            for (size_t i = 0; i < res.size(); ++i) {
                if (i) cout << ' ';
                cout << res[i];
            }
            cout << '\n';
        }
    }
    return 0;
}