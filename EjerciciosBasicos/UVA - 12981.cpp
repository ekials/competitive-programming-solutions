#include <iostream>

using namespace std;

int main() 
{

    int t;
    if (cin >> t) 
    {
        for (int i = 1; i <= t; ++i) 
        {
            int a, b, c, d;
            int x, y, z, w;

            cin >> a >> b >> c >> d;
            cin >> x >> y >> z >> w;

            bool possible = (a == x && b == y && c == z && d == w) || 
                            (c == x && a == y && d == z && b == w) || 
                            (d == x && c == y && b == z && a == w) || 
                            (b == x && d == y && a == z && c == w);

            cout << "Case #" << i << ": " << (possible ? "POSSIBLE" : "IMPOSSIBLE") << "\n";
        }
    }

    return 0;
}