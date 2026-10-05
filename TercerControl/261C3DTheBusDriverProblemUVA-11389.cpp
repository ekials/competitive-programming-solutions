#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n, d, r;
    while (cin >> n >> d >> r)
    {
        if (n == 0 && d == 0 && r == 0)
        {
            break;
        }

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        for (int i = 0; i < n; ++i)
        {
            cin >> b[i];
        }

        sort(a.begin(), a.end());
        sort(b.rbegin(), b.rend());

        long long tot = 0;

        for (int i = 0; i < n; ++i)
        {
            int sum = a[i] + b[i];
            if (sum > d)
            {
                tot += (long long)(sum - d) * r;
            }
        }

        cout << tot << "\n";
    }

    return 0;
}