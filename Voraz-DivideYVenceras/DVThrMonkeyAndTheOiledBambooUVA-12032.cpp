#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool es_posible(int k, const vector<int>& r)
{
    int prev = 0;
    for (size_t i = 0; i < r.size(); ++i)
    {
        int diff = r[i] - prev;
        if (diff > k)
        {
            return false;
        }
        if (diff == k)
        {
            k--;
        }
        prev = r[i];
    }
    return true;
}

int main()
{
    int t;
    if (cin >> t)
    {
        for (int c = 1; c <= t; ++c)
        {
            int n;
            cin >> n;

            vector<int> r(n);
            int prev = 0;
            int k_min = 0;

            for (int i = 0; i < n; ++i)
            {
                cin >> r[i];
                k_min = max(k_min, r[i] - prev);
                prev = r[i];
            }

            int ans = k_min;
            if (!es_posible(k_min, r))
            {
                ans = k_min + 1;
            }

            cout << "Case " << c << ": " << ans << "\n";
        }
    }

    return 0;
}