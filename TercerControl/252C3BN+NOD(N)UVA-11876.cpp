#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_VAL = 1000000;

int main()
{

    vector<int> nod(MAX_VAL + 1, 0);
    for (int i = 1; i <= MAX_VAL; ++i)
    {
        for (int j = i; j <= MAX_VAL; j += i)
        {
            nod[j]++;
        }
    }

    vector<int> seq;
    seq.push_back(1); 

    while (seq.back() <= MAX_VAL)
    {
        int last = seq.back();
        int next_val = last + nod[last];
        seq.push_back(next_val);
    }

    int t;
    if (cin >> t)
    {
        for (int c = 1; c <= t; ++c)
        {
            int a, b;
            cin >> a >> b;

            auto low = lower_bound(seq.begin(), seq.end(), a);
            auto high = upper_bound(seq.begin(), seq.end(), b);

            int count = distance(low, high);

            cout << "Case " << c << ": " << count << "\n";
        }
    }

    return 0;
}