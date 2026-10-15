#include <iostream>
#include <vector>

using namespace std;

int main ()
{
    int N, R, C, K;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    while(cin >> N >> R >> C >> K && (N || R || C || K))
    {
        vector<vector <int>> g(R, vector<int>(C));

        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++) cin >> g[r][c];
        }

        while(K--)
        {
            vector<vector<int>> nextG = g;

            for(int r = 0; r < R; r++)
            {
                for(int c = 0; c < C; c++)
                {
                    int hered = g[r][c];
                    int t = (hered + 1) % N;

                    for(int i = 0; i < 4; i++)
                    {
                        int nr = r + dr[i];
                        int nc = c + dc[i];

                        if(nr >= 0 && nr < R && nc >= 0 && nc < C)
                        {
                            if(g[nr][nc] == t) nextG[nr][nc] = hered;
                        }
                    }
                }
            }
            g = nextG;
        }
        for(int r = 0; r < R; r++)
        {
            for(int c = 0; c < C; c++) cout << g[r][c] << (c == C - 1 ? "" : " ");
            cout << "\n";
        }
    }
    return 0;
}