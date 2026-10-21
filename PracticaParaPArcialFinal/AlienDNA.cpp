#include<iostream>
#include <string>
using namespace std;

int main()
{
    int t;

    if(cin >> t)
    {
        while(t--)
        {
            int n;
            cin >> n;

            int corte = 0; 
            unsigned int cM = (1U << 26) - 1;

            for(int i = 0; i < n; i++)
            {
                string s;
                cin >> s;

                unsigned int m = 0;
                
                for(char c : s) m |= (1U << (c - 'a'));

                if((cM & m) != 0) cM &= m;
                else 
                {
                    corte++; 
                    cM = m;
                }

            }
            
            cout << corte << "\n";
        }
    }

    return 0;
}