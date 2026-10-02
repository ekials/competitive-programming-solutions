#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() 
{

    string s;
    int caseNum = 1;

    while (cin >> s && s != "end") {
        vector<char> stacks;

        for (char c : s) {
            int bestIdx = -1;

            for (int i = 0; i < (int)stacks.size(); ++i) {
                if (stacks[i] >= c) {
                    if (bestIdx == -1 || stacks[i] < stacks[bestIdx]) {
                        bestIdx = i;
                    }
                }
            }

            if (bestIdx == -1) {
                stacks.push_back(c);
            } else {
                stacks[bestIdx] = c;
            }
        }

        cout << "Case " << caseNum++ << ": " << stacks.size() << "\n";
    }

    return 0;
}