#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int main() 
{

    int t;
    if (!(cin >> t)) return 0;

    string line;
    getline(cin, line);
    getline(cin, line);

    map<char, int> prec;
    prec['+'] = 1;
    prec['-'] = 1;
    prec['*'] = 2;
    prec['/'] = 2;

    for (int tc = 0; tc < t; ++tc) {
        if (tc > 0) cout << "\n";

        stack<char> st;
        string res = "";

        while (getline(cin, line) && !line.empty()) {
            char c = line[0];

            if (c >= '0' && c <= '9') {
                res += c;
            } else if (c == '(') {
                st.push(c);
            } else if (c == ')') {
                while (!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                if (!st.empty()) st.pop();
            } else {
                while (!st.empty() && st.top() != '(' && prec[st.top()] >= prec[c]) {
                    res += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }

        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        cout << res << "\n";
    }

    return 0;
}