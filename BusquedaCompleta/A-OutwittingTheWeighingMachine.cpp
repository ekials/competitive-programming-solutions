#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    if (cin >> t) {
        for (int caso = 1; caso <= t; ++caso)
        {
            vector<int> w(10);
            long long suma_parejas = 0;
            for (int i = 0; i < 10; ++i)
            {
                cin >> w[i];
                suma_parejas += w[i];
            }
            long long S = suma_parejas / 4;
            int C = S - w[0] - w[9];
            int A = w[1] - C;
            int B = w[0] - A;
            int E = w[8] - C;
            int D = w[9] - E;

            vector<int> res = {A, B, C, D, E};
            sort(res.begin(), res.end());

            cout << "Case " << caso << ": " << res[0] << " " << res[1] << " " << res[2] << " " << res[3] << " " << res[4] << "\n"; 
         }
    }
    return 0;
}