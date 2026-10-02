#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() 
{
    //int m;
    int n;
    while (cin >> n && n != 0) 
    {
        int count[100] = {0};         

        for (int i = 0; i < n; i++) 
        {
            int age;
            cin >> age;
            count[age]++;
        }

        bool first = true;
        for (int age = 1; age <= 99; age++) 
        {
            while (count[age]--) 
            {
                if (!first) cout << ' ';
                cout << age;
                first = false;
            }
        }
        cout << '\n';
    }
    return 0;
}