
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
    int n;
    while (cin >> n && n != 0) 
    {
        vector<pair<string, bool>> o(n, {"", false});
        int pos = 0;

        for (int k = 0; k < n; k++) 
        {
            string simb, name;
            cin >> simb >> name;
            int len = name.length();

            while (len > 0) 
            {
                if (!o[pos].second) len--; 
                if (len > 0) pos = (pos + 1) % n;
            }

            o[pos].first = simb;
            o[pos].second = true;
            pos = (pos + 1) % n;
        }

        for (int j = 0; j < n; j++) 
        {
            if (j == n - 1) cout << o[j].first << "\n";
            else cout << o[j].first << " ";
        }
    }
    return 0;
}