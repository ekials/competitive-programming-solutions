#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    vector<long long> c23;
    long long max_val = 1LL << 31; 

    for (long long p2 = 1; p2 <= max_val; p2 *= 2)
    {
        for (long long p3 = 1; p2 * p3 <= max_val; p3 *= 3)
        {
            c23.push_back(p2 * p3);
        }
    }

    sort(c23.begin(), c23.end());

    long long m;
    while (cin >> m && m != 0)
    {
        auto it = lower_bound(c23.begin(), c23.end(), m);
        cout << *it << "\n";
    }

    return 0;
}