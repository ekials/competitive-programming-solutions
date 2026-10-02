#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n, m;
            cin >> n >> m;

            vector<vector<int>> mat(n, vector<int>(m));
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < m; ++j)
                {
                    cin >> mat[i][j];
                }
            }

            bool ok = true;
            set<pair<int, int>> edges;

            for (int j = 0; j < m; ++j)
            {
                int cnt = 0;
                int u = -1;
                int v = -1;

                for (int i = 0; i < n; ++i)
                {
                    if (mat[i][j] == 1)
                    {
                        cnt++;
                        if (u == -1)
                        {
                            u = i;
                        }
                        else
                        {
                            v = i;
                        }
                    }
                }

                if (cnt != 2)
                {
                    ok = false;
                    break;
                }

                if (u > v)
                {
                    swap(u, v);
                }

                if (edges.count({u, v}))
                {
                    ok = false;
                    break;
                }

                edges.insert({u, v});
            }

            if (ok)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}