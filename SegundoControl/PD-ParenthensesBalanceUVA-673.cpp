#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{

    int n;
    if (cin >> n)
    {
        string s;
        getline(cin, s);

        while (n--)
        {
            getline(cin, s);

            stack<char> st;
            bool ok = true;

            for (char c : s)
            {
                if (c == '(' || c == '[')
                {
                    st.push(c);
                }
                else if (c == ')')
                {
                    if (!st.empty() && st.top() == '(')
                    {
                        st.pop();
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
                else if (c == ']')
                {
                    if (!st.empty() && st.top() == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        ok = false;
                        break;
                    }
                }
            }

            if (ok && st.empty())
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