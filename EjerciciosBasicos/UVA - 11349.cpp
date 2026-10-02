#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{

    int t;
    if (!(cin >> t)) return 0;

    for (int tc = 1; tc <= t; ++tc) 
    {
        string dummy;
        char c1, c2;
        int n;
        cin >> c1 >> c2 >> n;

        vector<vector<long long>> m(n, vector<long long>(n));
        bool symmetric = true;

        for (int i = 0; i < n; ++i) 
        {
            for (int j = 0; j < n; ++j) 
            {
                cin >> m[i][j];
                if (m[i][j] < 0) 
                {
                    symmetric = false;
                }
            }
        }

        if (symmetric) {
            for (int i = 0; i < n; ++i) 
            {
                for (int j = 0; j < n; ++j) 
                {
                    if (m[i][j] != m[n - 1 - i][n - 1 - j]) 
                    {
                        symmetric = false;
                        break;
                    }
                }
                if (!symmetric) break;
            }
        }

        if (symmetric) 
        {
            cout << "Test #" << tc << ": Symmetric.\n";
        } 
        else
        {
            cout << "Test #" << tc << ": Non-symmetric.\n";
        }
    }

    return 0;
}