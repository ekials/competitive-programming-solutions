#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    if (cin >> t)
    {
        for (int c = 1; c <= t; ++c)
        {
            int n, k;
            cin >> n >> k;

            vector<long long> x(n);
            for (int i = 0; i < n; ++i)
            {
                cin >> x[i];
            }

            vector<long long> y(n);
            for (int i = 0; i < n; ++i)
            {
                cin >> y[i];
            }

            vector<long long> profit(n);
            for (int i = 0; i < n; ++i)
            {
                profit[i] = y[i] - x[i];
            }

            sort(profit.begin(), profit.end(), greater<long long>());

            long long total_profit = 0;
            int must_take = n - k;   

            for (int i = 0; i < n; ++i)
            {
                if (i < must_take || profit[i] > 0)
                {
                    total_profit += profit[i];
                }
                else
                {
                    break; 
                }
            }

            cout << "Case " << c << ": ";
            if (total_profit > 0)
            {
                cout << total_profit << "\n";
            }
            else
            {
                cout << "No Profit\n";
            }
        }
    }

    return 0;
}