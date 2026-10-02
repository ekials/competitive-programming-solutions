#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

int main()
{
    string s;
    int cont = 1;
    while(cin >> s && s != "end")
    {
        //stack <char> st;
        vector <char>st;
        for (char c : s)
        {
            int idx = -1;
            for(int i = 0; i < st.size(); i++)
            {
                if(st[i] >= c)
                {
                    if(idx == -1 || st[i] < st[idx]) idx = i;
                }
            }

            if(idx == -1) st.push_back(c);
            else st[idx] = c;
        }
    cout << "Case " << cont++ << ": " << st.size() << "\n";
    }

    return 0;
}