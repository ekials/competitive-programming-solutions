#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    vector<int> a;
    int x;
    while (cin >> x) 
    {
        a.push_back(x);
    }

    int n = a.size();
    if (n == 0) return 0;

    vector<int> lis;
    vector<int> pos(n);
    vector<int> parent(n, -1);
    vector<int> lis_indices;

    for (int i = 0; i < n; ++i) 
    {
        auto it = lower_bound(lis.begin(), lis.end(), a[i]);
        int idx = distance(lis.begin(), it);

        if (it == lis.end()) 
        {
            lis.push_back(a[i]);
            lis_indices.push_back(i);
        } else 
        {
            *it = a[i];
            lis_indices[idx] = i;
        }

        pos[i] = idx;
        if (idx > 0) 
        {
            parent[i] = lis_indices[idx - 1];
        }
    }

    int len = lis.size();
    cout << len << "\n-\n";

    vector<int> result;
    int curr = lis_indices.back();
    while (curr != -1) 
    {
        result.push_back(a[curr]);
        curr = parent[curr];
    }

    reverse(result.begin(), result.end());

    for (int val : result) 
    {
        cout << val << "\n";
    }

    return 0;
}