#include <iostream>
#include <vector>

using namespace std;

int main()
{

    const int limite = 100000;
    vector<int> cant_div(limite + 1, 0);
    vector<long long> suma_div(limite + 1, 0);

    for (int i = 1; i <= limite; ++i)
    {
        for (int j = i; j <= limite; j += i)
        {
            cant_div[j]++;
            suma_div[j] += i;
        }
    }

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int a, b, k;
            cin >> a >> b >> k;
            long long g = 0, h = 0;
            int inicio = ((a + k - 1) / k) * k;
            for (int i = inicio; i <= b; i += k)
            {
                g += cant_div[i];
                h += suma_div[i];
            }
            cout << g << " " << h << "\n";
        }
    }

    return 0;
}