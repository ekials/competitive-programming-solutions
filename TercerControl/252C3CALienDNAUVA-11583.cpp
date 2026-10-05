#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            cin >> n;

            int cuts = 0;
            unsigned int current_mask = (1U << 26) - 1; 

            for (int i = 0; i < n; ++i)
            {
                string s;
                cin >> s;

                unsigned int mask = 0;
                for (char c : s)
                {
                    mask |= (1U << (c - 'a'));
                }

                if ((current_mask & mask) != 0)
                {
                    current_mask &= mask;
                }
                else
                {
                    cuts++;
                    current_mask = mask; 
                }
            }

            cout << cuts << "\n";
        }
    }

    return 0;
}