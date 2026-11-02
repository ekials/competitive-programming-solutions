#include <iostream>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

struct a
{
    vector<int> parent;
    a(int n) 
    {
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int i) 
    {
        if (parent[i] == i)
            return i;
        return parent[i] = find(parent[i]);
    }
    bool unite(int i, int j) 
    {
        int root_i = find(i);
        int root_j = find(j);
        if (root_i != root_j)
        {
            parent[root_i] = root_j;
            return true;
        }
        return false;
    }
};

int main() 
{
    int t;
    if (!(cin >> t)) return 0;
    string line;
    getline(cin, line);

    for (int tc = 0; tc < t; ++tc) 
    {
        if (tc > 0) cout << "\n";

        while (getline(cin, line) && line.empty());

        int n = line[0] - 'A' + 1;
        a dsu(n);
        int components = n;

        while (getline(cin, line) && !line.empty()) {
            int u = line[0] - 'A';
            int v = line[1] - 'A';
            if (dsu.unite(u, v)) components--;
        }

        cout << components << "\n";
    }

    return 0;
}