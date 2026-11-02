#include <cstdio>

int dp[27][352];

int main() {
    dp[0][0] = 1;
    for (int letra = 1; letra <= 26; ++letra)
        for (int l = 26; l >= 1; --l)
            for (int s = 351; s >= letra; --s)
                dp[l][s] += dp[l - 1][s - letra];

    int l, s, caso = 0;
    while (scanf("%d %d", &l, &s) == 2 && (l != 0 || s != 0)) {
        int res = (l <= 26 && s <= 351) ? dp[l][s] : 0;
        printf("Case %d: %d\n", ++caso, res);
    }
    return 0;
}