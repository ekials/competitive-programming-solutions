#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>

using namespace std;

vector<int> padre;
vector<int> dist;

int buscar(int u)
{
    if (padre[u] == u)
    {
        return u;
    }
    int p = padre[u];
    padre[u] = buscar(p);
    dist[u] += dist[p];
    return padre[u];
}

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;

            padre.resize(n + 1);
            dist.resize(n + 1, 0);

            for (int i = 1; i <= n; ++i)
            {
                padre[i] = i;
                dist[i] = 0;
            }

            char op;
            while (cin >> op)
            {
                if (op == 'O')
                {
                    break;
                }

                if (op == 'E')
                {
                    int u;
                    cin >> u;
                    buscar(u);
                    cout << dist[u] << "\n";
                }
                else if (op == 'I')
                {
                    int u, v;
                    cin >> u >> v;
                    padre[u] = v;
                    dist[u] = abs(u - v) % 1000;
                }
            }
        }
    }

    return 0;
}