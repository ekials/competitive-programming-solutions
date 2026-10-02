#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

int main() 
{

    int t, scenario = 1;

    while (cin >> t && t != 0) 
    {
        unordered_map<int, int> element_to_team;

        for (int i = 0; i < t; ++i) 
        {
            int num_elem;
            cin >> num_elem;
            for (int j = 0; j < num_elem; ++j) 
            {
                int elem;
                cin >> elem;
                element_to_team[elem] = i; 
            }
        }

        queue<int> team_queue;             
        vector<queue<int>> member_queue(t); 

        cout << "Scenario #" << scenario++ << "\n";

        string cmd;
        while (cin >> cmd && cmd != "STOP") 
        {
            if (cmd == "ENQUEUE") 
            {
                int x;
                cin >> x;
                int team_id = element_to_team[x];

                if (member_queue[team_id].empty())team_queue.push(team_id);
              
                member_queue[team_id].push(x);

            }
            else if (cmd == "DEQUEUE") 
            {
                int current_team = team_queue.front();

                cout << member_queue[current_team].front() << "\n";
                member_queue[current_team].pop();
                
                if (member_queue[current_team].empty()) team_queue.pop();
            }
        }
        cout << "\n";      
    }

    return 0;
}