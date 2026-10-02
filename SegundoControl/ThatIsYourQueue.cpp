#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

int main()
{

    long long p;
    int c;
    int caso = 1;

    while (cin >> p >> c)
    {
        if (p == 0 && c == 0)
        {
            break;
        }

        cout << "Case " << caso++ << ":\n";

        list<long long> l;
        long long lim = min(p, (long long)c);

        for (long long i = 1; i <= lim; ++i)
        {
            l.push_back(i);
        }

        for (int i = 0; i < c; ++i)
        {
            char op;
            cin >> op;

            if (op == 'N')
            {
                long long act = l.front();
                l.pop_front();
                cout << act << "\n";
                l.push_back(act);
            }
            else if (op == 'E')
            {
                long long x;
                cin >> x;
                l.remove(x);
                l.push_front(x);
            }
        }
    }

    return 0;
}