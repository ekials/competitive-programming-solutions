#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<vector<int>> ady(26);
    vector<int> grado(26, 0);
    vector<bool> usada(26, false);

    string anterior, actual;
    bool primera = true;
    while (cin >> actual && actual != "#") {
        for (char c : actual) usada[c - 'A'] = true;
        if (!primera) {
            size_t lim = min(anterior.size(), actual.size());
            for (size_t i = 0; i < lim; ++i) {
                if (anterior[i] != actual[i]) {
                    ady[anterior[i] - 'A'].push_back(actual[i] - 'A');
                    grado[actual[i] - 'A']++;
                    break;
                }
            }
        }
        anterior = actual;
        primera = false;
    }

    queue<int> q;
    for (int i = 0; i < 26; ++i)
        if (usada[i] && grado[i] == 0) q.push(i);

    string orden;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        orden += char('A' + u);
        for (int v : ady[u])
            if (--grado[v] == 0) q.push(v);
    }
    cout << orden << '\n';
    return 0;
}