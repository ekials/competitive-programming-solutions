#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> g;

int dfs(int i, int j) {
    if (i < 0 || i >= (int)g.size() || j < 0 || j >= (int)g[i].size() || g[i][j] != '1') return 0;
    g[i][j] = '0';
    int total = 1;
    for (int di = -1; di <= 1; ++di)
        for (int dj = -1; dj <= 1; ++dj)
            total += dfs(i + di, j + dj);
    return total;
}

string limpiar(string s) {
    while (!s.empty() && (s.back() == '\r' || s.back() == ' ')) s.pop_back();
    return s;
}

int main() {
    int t;
    string linea;
    getline(cin, linea);
    t = stoi(linea);

    for (int caso = 0; caso < t; ++caso) {
        g.clear();
        while (getline(cin, linea) && limpiar(linea).empty()) {}
        do {
            linea = limpiar(linea);
            if (linea.empty()) break;
            g.push_back(linea);
        } while (getline(cin, linea));

        int mejor = 0;
        for (int i = 0; i < (int)g.size(); ++i)
            for (int j = 0; j < (int)g[i].size(); ++j)
                if (g[i][j] == '1') mejor = max(mejor, dfs(i, j));

        if (caso > 0) cout << '\n';
        cout << mejor << '\n';
    }
    return 0;
}