#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    int n;
    while (cin >> n)
    {
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }

        int m;
        cin >> m;

        sort(a.begin(), a.end());

        int l = 0, r = n - 1;
        int best_i = -1, best_j = -1;

        while (l < r)
        {
            int sum = a[l] + a[r];
            if (sum == m)
            {
                best_i = a[l];
                best_j = a[r];
                l++;
                r--;
            }
            else if (sum < m)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        cout << "Peter should buy books whose prices are " << best_i << " and " << best_j << ".\n\n";
    }

    return 0;
}