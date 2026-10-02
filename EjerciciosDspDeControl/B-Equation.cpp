#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>

using namespace std;

int main()
{
    
    int t;
    while (cin >> t)
    {
        string s;
            
        getline(cin, s);
        getline(cin, s);

        map<char, int> p;
        p['+'] = 1;
        p['-'] = 1;
        p['*'] = 2;
        p['/'] = 2;

        for (int tc = 0; tc < t; tc++) 
        {
            if (tc > 0) cout << "\n";

            stack<char> st;
            string rs = "";

            while(getline (cin, s) && !s.empty())
            {
                char c = s[0];

                if( c >= '0' && c <= '9' )  rs += c;
                else if(c == '(') st.push(c);
                else if(c == ')')
                {
                        
                    while (!st.empty() && st.top() != '(') 
                    {
                        rs += st.top();
                        st.pop();
                    }
                    if(!st.empty()) st.pop();
                }
                else
                {
                    while (!st.empty() && (st.top() != '(') && p[st.top()] >= p[c])
                    {
                        rs += st.top();
                        st.pop();
                    }     
                    st.push(c);

                }
            }

            while (!st.empty()) 
            {
                rs += st.top();
                st.pop();
            }

            cout << rs << "\n";
        } 


    }
    return 0;
}