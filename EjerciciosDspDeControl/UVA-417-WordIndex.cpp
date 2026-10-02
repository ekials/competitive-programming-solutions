#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

int main() {

    unordered_map<string, int> wordIndex;
    queue<string> q;

    for (char c = 'a'; c <= 'z'; ++c) {
        string s(1, c);
        q.push(s);
    }

    int id = 1;
    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        wordIndex[curr] = id++;

        if (curr.length() < 5) {
            char lastChar = curr.back();
            for (char nextChar = lastChar + 1; nextChar <= 'z'; ++nextChar) {
                q.push(curr + nextChar);
            }
        }
    }

    string inputWord;
    while (cin >> inputWord) {
        if (wordIndex.count(inputWord)) {
            cout << wordIndex[inputWord] << "\n";
        } else {
            cout << 0 << "\n";
        }
    }

    return 0;
}