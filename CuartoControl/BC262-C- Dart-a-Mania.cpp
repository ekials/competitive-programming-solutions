#include <cstdio>
#include <set>
#include <vector>

using namespace std;

int main() {
    set<int> conjunto = {0, 50};
    for (int i = 1; i <= 20; ++i) {
        conjunto.insert(i);
        conjunto.insert(2 * i);
        conjunto.insert(3 * i);
    }
    vector<int> v(conjunto.begin(), conjunto.end());

    const int MAX = 1000;
    vector<int> comb(MAX, 0), perm(MAX, 0);
    int k = v.size();
    for (int i = 0; i < k; ++i) {
        for (int j = i; j < k; ++j) {
            for (int l = j; l < k; ++l) {
                int s = v[i] + v[j] + v[l];
                comb[s]++;
                if (i == j && j == l) perm[s] += 1;
                else if (i == j || j == l) perm[s] += 3;
                else perm[s] += 6;
            }
        }
    }

    int x;
    while (scanf("%d", &x) == 1 && x > 0) {
        if (x < MAX && comb[x] > 0) {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", x, comb[x]);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", x, perm[x]);
        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", x);
        }
        for (int i = 0; i < 70; ++i) putchar('*');
        putchar('\n');
    }
    printf("END OF OUTPUT\n");
    return 0;
}