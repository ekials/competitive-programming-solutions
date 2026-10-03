#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{

    int n;
    while (cin >> n)
    {
        if (n == 0)
        {
            break;
        }

        while (true)
        {
            int primero;
            cin >> primero;

            if (primero == 0)
            {
                cout << "\n";
                break;
            }

            vector<int> target(n);
            target[0] = primero;
            for (int i = 1; i < n; ++i)
            {
                cin >> target[i];
            }

            stack<int> st;
            int act = 1;
            bool ok = true;

            for (int i = 0; i < n; ++i)
            {
                int req = target[i];

                while (act <= n && (st.empty() || st.top() != req))
                {
                    st.push(act);
                    act++;
                }

                if (!st.empty() && st.top() == req)
                {
                    st.pop();
                }
                else
                {
                    ok = false;
                    break;
                }
            }

            if (ok)
            {
                cout << "Yes\n";
            }
            else
            {
                cout << "No\n";
            }
        }
    }

    return 0;
}