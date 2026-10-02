#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;
//terminar
int main ()
{
    int n;
    while(cin >> n )
    {
        vector <int> arr;
        //stack<int> arr;
        arr.push_back(n);
        
        int ini = arr[0];
        if( !(ini - arr.back() == 0))arr.push_back(n);


        auto it = is_sorted(arr.begin(), arr.end());

        //if(is_sorted(arr.begin(), arr.end())) cout << ":-) Matrioshka!";
        //else cout << ":-( Try again.";

        if (it != arr.end()) cout << ":-) Matrioshka!";
        else cout << ":-( Try again.";

    }
    return 0;
}