#include <iostream>
#include <vector>
#include <queue>
#include <string>
//#include <map>
#include<unordered_map>

using namespace std;
int main()
{
    int t, e = 1;

    while(cin >> t && t!=0)
    {
        //vector <vector <int, int>> elem_equp;
        unordered_map<int, int> elem_equp;
        //map<int, int> elem_equp;
        for(int i = 0; i < t; i++)
        {
            int num_elem;
            cin >> num_elem;
            for(int j = 0; j < num_elem; j++)
            {
                int elem;
                cin >> elem;    
                elem_equp[elem] = i;
            }
        }
        queue<int> equpQ;
        vector <queue<int>> elemQ(t);

        cout << "Scenario #" << e++ << "\n";

        string ind;
        while(cin >> ind && ind != "STOP" )
        {
            if(ind == "ENQUEUE")
            {
                int x;
                cin >> x;
                int I = elem_equp[x];

                if(elemQ[I].empty()) equpQ.push(I);
                elemQ[I].push(x);
            }
            
            if(ind == "DEQUEUE")
            {
                int equpC = equpQ.front();
                cout << elemQ[equpC].front()<< "\n";
                elemQ[equpC].pop();

                if(elemQ[equpC].empty()) equpQ.pop();
            }
        }
        
        cout << "\n";
        
    }
    return 0;
}