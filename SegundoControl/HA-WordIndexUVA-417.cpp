#include <iostream>
#include <string>
#include <vector>

using namespace std;

int c[30][30];

void prep()
{
    for (int i = 0; i <= 26; ++i)
    {
        c[i][0] = 1;
    }
    for (int i = 1; i <= 26; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
        }
    }
}

int main()
{
    prep();

    string s;
    while (cin >> s)
    {
        bool ok = true;
        int n = s.length();

        for (int i = 1; i < n; ++i)
        {
            if (s[i] <= s[i - 1])
            {
                ok = false;
                break;
            }
        }

        if (!ok)
        {
            cout << 0 << "\n";
            continue;
        }

        int ans = 0;

        for (int i = 1; i < n; ++i)
        {
            ans += c[26][i];
        }

        char prev = 'a';
        for (int i = 0; i < n; ++i)
        {
            char curr = s[i];
            for (char ch = prev; ch < curr; ++ch)
            {
                int rem_len = n - 1 - i;
                int rem_chars = 'z' - ch;
                ans += c[rem_chars][rem_len];
            }
            prev = curr + 1;
        }

        cout << ans + 1 << "\n";
    }

    return 0;
}