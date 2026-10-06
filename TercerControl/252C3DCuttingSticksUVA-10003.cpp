#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main()
{
    int l;
    while (cin >> l && l != 0)
    {
        int n;
        cin >> n;

        vector<int> cuts(n + 2);
        cuts[0] = 0;
        for (int i = 1; i <= n; ++i)
        {
            cin >> cuts[i];
        }
        cuts[n + 1] = l;

        int num_points = n + 2;
        vector<vector<int>> dp(num_points, vector<int>(num_points, 0));

        for (int len = 2; len < num_points; ++len)
        {
            for (int i = 0; i + len < num_points; ++i)
            {
                int j = i + len;
                dp[i][j] = INF;

                for (int k = i + 1; k < j; ++k)
                {
                    int cost = cuts[j] - cuts[i] + dp[i][k] + dp[k][j];
                    if (cost < dp[i][j])
                    {
                        dp[i][j] = cost;
                    }
                }
            }
        }

        cout << "The minimum cutting is " << dp[0][n + 1] << ".\n";
    }

    return 0;
}