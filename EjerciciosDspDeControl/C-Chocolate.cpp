#include <iostream>
#include <vector>

using namespace std;

int main() 
{
    int T;
    if (!(cin >> T)) return 0;

    for (int t = 1; t <= T; t++)
    {
        int L, R, S;
        cin >> L >> R >> S; 

        vector<bool> hasL(100005, false);
        vector<bool> hasR(100005, false);
        vector<bool> hasS(100005, false);

        for (int i = 0; i < L; i++) 
        {
            int x;
            cin >> x;
            hasL[x] = true;
        }

        for (int i = 0; i < R; i++) 
        {
            int x;
            cin >> x;
            hasR[x] = true;
        }

        for (int i = 0; i < S; i++) 
        {
            int x;
            cin >> x;
            hasS[x] = true;
        }

        int sL = 0, mL = 0;
        int sR = 0, mR = 0;
        int sS = 0, mS = 0;

        for (int i = 0; i < 100005; i++) 
        {
            if (hasL[i] && !hasR[i] && !hasS[i]) sL++;
            if (!hasL[i] && hasR[i] && hasS[i]) mL++;

            if (hasR[i] && !hasL[i] && !hasS[i]) sR++;
            if (!hasR[i] && hasL[i] && hasS[i]) mR++;

            if (hasS[i] && !hasL[i] && !hasR[i]) sS++;
            if (!hasS[i] && hasL[i] && hasR[i]) mS++;
        }

        cout << "Case #" << t << ":\n";
        cout << sL << " " << mL << "\n"; 
        cout << sR << " " << mR << "\n";
        cout << sS << " " << mS << "\n";
    }

    return 0;
}