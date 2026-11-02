#include <iostream>

using namespace std;

long long N, A, B;

long long siguiente(long long x) {
    return ((x * x % N) * A + B) % N;
}

int main() {
    while (cin >> N && N != 0) {
        cin >> A >> B;

        long long lento = 0, rapido = 0;
        do {
            lento = siguiente(lento);
            rapido = siguiente(siguiente(rapido));
        } while (lento != rapido);

        long long ciclo = 0;
        do {
            rapido = siguiente(rapido);
            ++ciclo;
        } while (rapido != lento);

        cout << N - ciclo << '\n';
    }
    return 0;
}