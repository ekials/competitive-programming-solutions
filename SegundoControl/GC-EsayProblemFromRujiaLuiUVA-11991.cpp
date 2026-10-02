#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{

    int n, m;
    while (cin >> n >> m)
    {
        map<int, vector<int>> pos;

        for (int i = 1; i <= n; ++i)
        {
            int val;
            cin >> val;
            pos[val].push_back(i);
        }

        for (int i = 0; i < m; ++i)
        {
            int k, v;
            cin >> k >> v;

            if (pos.find(v) != pos.end() && k <= (int)pos[v].size())
            {
                cout << pos[v][k - 1] << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
    }

    return 0;
}