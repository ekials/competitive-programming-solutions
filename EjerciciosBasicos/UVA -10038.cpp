#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int n;
    while(cin >> n && n <= 3000)
    {
        vector <int> arr;
        for(int i = 0; i < n; i++)
        {
            int nro;
            cin>>nro;
            arr.push_back(nro);
        }
        vector<bool> diffs(n, false);
        bool isJolly = true;

        for(int i = 1; i < arr.size(); i++) 
        {
            int diff = abs(arr[i] - arr[i - 1]);
            if (diff >= 1 && diff <= n - 1 && !diffs[diff]) diffs[diff] = true;
            else isJolly = false;
        }
        if (isJolly) cout << "Jolly\n";
        else cout << "Not jolly\n";
    }

    return 0 ;
}