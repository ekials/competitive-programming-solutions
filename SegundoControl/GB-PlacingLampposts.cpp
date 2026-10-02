#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;
vector<vector<int>> g;
vector<bool> vis;
pair<int, int> dp[1005][2];

pair<int, int> resolver(int u, int p, int colocar)
{
    if (dp[u][colocar].first != -1)
    {
        return dp[u][colocar];
    }

    int lamparas = colocar;
    int dobles = 0;

    for (int v : g[u])
    {
        if (v != p)
        {
            if (colocar == 1)
            {
                pair<int, int> op0 = resolver(v, u, 0);
                pair<int, int> op1 = resolver(v, u, 1);
                op1.second += 1;

                if (op0.first < op1.first)
                {
                    lamparas += op0.first;
                    dobles += op0.second;
                }
                else if (op1.first < op0.first)
                {
                    lamparas += op1.first;
                    dobles += op1.second;
                }
                else
                {
                    lamparas += op0.first;
                    dobles += max(op0.second, op1.second);
                }
            }
            else
            {
                pair<int, int> op1 = resolver(v, u, 1);
                lamparas += op1.first;
                dobles += op1.second;
            }
        }
    }

    dp[u][colocar] = {lamparas, dobles};
    return dp[u][colocar];
}

void dfs(int u)
{
    vis[u] = true;
    for (int v : g[u])
    {
        if (!vis[v])
        {
            dfs(v);
        }
    }
}

int main()
{

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            if (!(cin >> n >> m))
            {
                break;
            }

            g.assign(n, vector<int>());
            vis.assign(n, false);

            for (int i = 0; i < n; ++i)
            {
                dp[i][0] = {-1, -1};
                dp[i][1] = {-1, -1};
            }

            for (int i = 0; i < m; ++i)
            {
                int u, v;
                cin >> u >> v;
                g[u].push_back(v);
                g[v].push_back(u);
            }

            int tot_lamparas = 0;
            int tot_dobles = 0;

            for (int i = 0; i < n; ++i)
            {
                if (!vis[i])
                {
                    dfs(i);

                    pair<int, int> op0 = resolver(i, -1, 0);
                    pair<int, int> op1 = resolver(i, -1, 1);

                    if (op0.first < op1.first)
                    {
                        tot_lamparas += op0.first;
                        tot_dobles += op0.second;
                    }
                    else if (op1.first < op0.first)
                    {
                        tot_lamparas += op1.first;
                        tot_dobles += op1.second;
                    }
                    else
                    {
                        tot_lamparas += op0.first;
                        tot_dobles += max(op0.second, op1.second);
                    }
                }
            }

            int tot_simples = m - tot_dobles;

            cout << tot_lamparas << " " << tot_dobles << " " << tot_simples << "\n";
        }
    }

    return 0;
}