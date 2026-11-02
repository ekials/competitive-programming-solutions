#include <iostream>
#include <vector>

using namespace std;

int main() {
    const int PERIODO = 15000;
    const int MOD = 10000;
    vector<int> fib(PERIODO);
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < PERIODO; ++i)
        fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;

    int t;
    cin >> t;
    while (t--) {
        long long a, b, n;
        int m;
        cin >> a >> b >> n >> m;

        int mod_m = 1;
        for (int i = 0; i < m; ++i) mod_m *= 10;

        long long res;
        if (n == 0) {
            res = a % mod_m;
        } else {
            int k = n % PERIODO;
            int anterior = fib[(k - 1 + PERIODO) % PERIODO];
            res = (a * anterior + b * fib[k]) % mod_m;
        }
        cout << res << '\n';
    }
    return 0;
}