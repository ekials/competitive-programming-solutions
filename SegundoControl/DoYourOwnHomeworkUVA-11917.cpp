#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    int t;
    if (cin >> t)
    {
        int c = 1;
        while (c <= t)
        {
            int n;
            cin >> n;

            map<string, int> m;
            for (int i = 0; i < n; ++i)
            {
                string s;
                int d;
                cin >> s >> d;
                m[s] = d;
            }

            int lim;
            string obj;
            cin >> lim >> obj;

            cout << "Case " << c << ": ";

            if (m.find(obj) != m.end())
            {
                int dias = m[obj];
                if (dias <= lim)
                {
                    cout << "Yesss\n";
                }
                else if (dias <= lim + 5)
                {
                    cout << "Late\n";
                }
                else
                {
                    cout << "Do your own homework!\n";
                }
            }
            else
            {
                cout << "Do your own homework!\n";
            }

            c++;
        }
    }

    return 0;
}