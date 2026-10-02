#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int N, S, Q;
vector<int> queueB[105]; 

long long solve() 
{
    deque<int> stack_; 
    long long time = 0;
    int current = 1;

    while (true) {
        int X = current;

        while (!stack_.empty()) {
            int top = stack_.back();
            if (top == X) {
                stack_.pop_back();
                time += 1;
            } else if ((int)queueB[X].size() < Q) {
                queueB[X].push_back(top);
                stack_.pop_back();
                time += 1;
            } else {
                break; 
            }
        }

        while (!queueB[X].empty() && (int)stack_.size() < S) {
            int c = queueB[X].front();
            queueB[X].erase(queueB[X].begin());
            stack_.push_back(c);
            time += 1;
        }

        long long total = stack_.size();
        for (int i = 1; i <= N; i++) total += queueB[i].size();
        if (total == 0) break;

        current = (X < N) ? X + 1 : 1;
        time += 2;
    }

    return time;
}

int main() 
{

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> S >> Q;
        for (int i = 1; i <= N; i++) {
            queueB[i].clear();
            int qi;
            cin >> qi;
            queueB[i].resize(qi);
            for (int j = 0; j < qi; j++) cin >> queueB[i][j];
        }
        cout << solve() << "\n";
    }
    return 0;
}