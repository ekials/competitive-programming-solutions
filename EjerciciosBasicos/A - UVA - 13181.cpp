#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
    string h;
    while (cin >> h )
    {
        vector <int> xpos;
        for(int i = 0; i < h.size(); i++) if(h[i] == 'X') xpos.push_back(i);
        int b = 0;
        if(xpos.front() > 0) b = max (b, xpos.front() - 1);
   
        int trailLen = h.size() - 1 - xpos.back();
        if (trailLen > 0) b = max(b, trailLen - 1);

        for (size_t k = 0; k + 1 < xpos.size(); k++) 
        {
            int gap = xpos[k+1] - xpos[k] - 1;
            if (gap > 0) b = max(b, (gap - 1) / 2);
        }
        cout << b << "\n";   
    }
    return 0;
}