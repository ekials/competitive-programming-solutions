#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Pt
{
    long long x, y;
};

Pt sub(Pt a, Pt b)
{
    return {a.x - b.x, a.y - b.y};
}

long long cruz(Pt a, Pt b)
{
    return a.x * b.y - a.y * b.x;
}

long long area(Pt a, Pt b, Pt c)
{
    return cruz(sub(b, a), sub(c, a));
}

bool en_segmento(Pt p, Pt a, Pt b)
{
    if (area(p, a, b) != 0)
    {
        return false;
    }
    return p.x >= min(a.x, b.x) && p.x <= max(a.x, b.x) &&
           p.y >= min(a.y, b.y) && p.y <= max(a.y, b.y);
}

int main()
{

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            int n;
            if (!(cin >> n))
            {
                break;
            }

            vector<Pt> p(n);
            for (int i = 0; i < n; ++i)
            {
                cin >> p[i].x >> p[i].y;
            }

            int q;
            cin >> q;

            while (q--)
            {
                Pt pt;
                cin >> pt.x >> pt.y;

                if (area(p[0], p[1], pt) < 0 || area(p[0], p[n - 1], pt) > 0)
                {
                    cout << "n\n";
                    continue;
                }

                if (en_segmento(pt, p[0], p[1]) || en_segmento(pt, p[0], p[n - 1]))
                {
                    cout << "y\n";
                    continue;
                }

                int low = 1, high = n - 1, idx = -1;
                while (low <= high)
                {
                    int mid = low + (high - low) / 2;
                    if (area(p[0], p[mid], pt) >= 0)
                    {
                        idx = mid;
                        low = mid + 1;
                    }
                    else
                    {
                        high = mid - 1;
                    }
                }

                if (idx == n - 1)
                {
                    if (en_segmento(pt, p[0], p[n - 1]) || en_segmento(pt, p[n - 2], p[n - 1]))
                    {
                        cout << "y\n";
                    }
                    else
                    {
                        cout << "n\n";
                    }
                }
                else
                {
                    long long a = area(p[idx], p[idx + 1], pt);
                    if (a >= 0)
                    {
                        cout << "y\n";
                    }
                    else
                    {
                        cout << "n\n";
                    }
                }
            }
        }
    }

    return 0;
}