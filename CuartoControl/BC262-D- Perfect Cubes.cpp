#include <cstdio>

int main() {
    long long cubo[201];
    for (int i = 0; i <= 200; ++i) cubo[i] = 1LL * i * i * i;

    for (int a = 2; a <= 200; ++a) {
        for (int b = 2; b < a; ++b) {
            for (int c = b; c < a; ++c) {
                long long resto = cubo[a] - cubo[b] - cubo[c];
                if (resto < cubo[c]) break;
                for (int d = c; d < a && cubo[d] <= resto; ++d) {
                    if (cubo[d] == resto)
                        printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
                }
            }
        }
    }
    return 0;
}