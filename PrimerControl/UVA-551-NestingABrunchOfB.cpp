#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        if (!s.empty() && s.back() == '\r') s.pop_back();
        
        stack<int> st;
        int pos = 0;
        int err = 0;
        int n = s.length();
        
        for (int i = 0; i < n; ) {
            pos++;
            if (i + 1 < n && s[i] == '(' && s[i + 1] == '*') {
                st.push(5);
                i += 2;
            } else if (i + 1 < n && s[i] == '*' && s[i + 1] == ')') {
                if (st.empty() || st.top() != 5) {
                    err = pos;
                    break;
                }
                st.pop();
                i += 2;
            } else if (s[i] == '(') {
                st.push(1);
                i++;
            } else if (s[i] == '[') {
                st.push(2);
                i++;
            } else if (s[i] == '{') {
                st.push(3);
                i++;
            } else if (s[i] == '<') {
                st.push(4);
                i++;
            } else if (s[i] == ')') {
                if (st.empty() || st.top() != 1) {
                    err = pos;
                    break;
                }
                st.pop();
                i++;
            } else if (s[i] == ']') {
                if (st.empty() || st.top() != 2) {
                    err = pos;
                    break;
                }
                st.pop();
                i++;
            } else if (s[i] == '}') {
                if (st.empty() || st.top() != 3) {
                    err = pos;
                    break;
                }
                st.pop();
                i++;
            } else if (s[i] == '>') {
                if (st.empty() || st.top() != 4) {
                    err = pos;
                    break;
                }
                st.pop();
                i++;
            } else {
                i++;
            }
        }
        
        if (err != 0) {
            cout << "NO " << err << "\n";
        } else if (!st.empty()) {
            cout << "NO " << pos + 1 << "\n";
        } else {
            cout << "YES\n";
        }
    }
    return 0;
}