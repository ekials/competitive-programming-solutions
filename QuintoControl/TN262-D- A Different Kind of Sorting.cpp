#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
    const int limite = 2000000;
    vector<int> factores(limite + 1, 0);

    for (int i = 2; i <= limite; ++i)
    {
        if (factores[i] == 0)
        {
            for (long long j = i; j <= limite; j *= i)
            {
                for (int k = j; k <= limite; k += j)
                {
                    factores[k]++;
                }
            }
        }
    }

    vector<int> orden(limite);
    iota(orden.begin(), orden.end(), 1);

    sort(orden.begin(), orden.end(), [&](int a, int b)
    {
        if (factores[a] != factores[b])
        {
            return factores[a] < factores[b];
        }
        return a < b;
    });

    int n, caso = 1;
    while (cin >> n && n != 0)
    {
        cout << "Case " << caso++ << ": " << orden[n - 1] << "\n";
    }

    return 0;
}