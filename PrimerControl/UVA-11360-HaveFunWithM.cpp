#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int T;
    if (!(cin >> T)) return 0;
    for (int caseNum = 1; caseNum <= T; caseNum++) {
        int N;
        cin >> N;
        vector<vector<int>> mat(N, vector<int>(N));
        for (int i = 0; i < N; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < N; j++) {
                mat[i][j] = s[j] - '0';
            }
        }
        int M;
        cin >> M;
        while (M--) {
            string op;
            cin >> op;
            if (op == "row") {
                int a, b;
                cin >> a >> b;
                a--; b--;
                for (int j = 0; j < N; j++) {
                    swap(mat[a][j], mat[b][j]);
                }
            } else if (op == "col") {
                int a, b;
                cin >> a >> b;
                a--; b--;
                for (int i = 0; i < N; i++) {
                    swap(mat[i][a], mat[i][b]);
                }
            } else if (op == "inc") {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        mat[i][j] = (mat[i][j] + 1) % 10;
                    }
                }
            } else if (op == "dec") {
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        mat[i][j] = (mat[i][j] - 1 + 10) % 10;
                    }
                }
            } else if (op == "transpose") {
                vector<vector<int>> temp = mat;
                for (int i = 0; i < N; i++) {
                    for (int j = 0; j < N; j++) {
                        mat[i][j] = temp[j][i];
                    }
                }
            }
        }
        cout << "Case #" << caseNum << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cout << mat[i][j];
            }
            cout << "\n";
        }
        cout << "\n";
    }
    return 0;
}