#include <iostream>
#include <bitset>

using namespace std;

int casos, objetivo, cantidad, caloria;

int main() {
    cin >> casos;
    while (casos--) {
        cin >> objetivo >> cantidad;
        bitset<300005> bs;
        bs[0] = 1;
        for (int i = 0; i < cantidad; ++i) {
            cin >> caloria;
            bs |= (bs << caloria);
        }
        int respuesta = -1;
        for (int i = objetivo; i < 300005; ++i) {
            if (bs[i]) {
                respuesta = i;
                break;
            }
        }
        if (respuesta != -1) cout << respuesta << "\n";
        else cout << "NO SOLUTION\n";
    }
    return 0;
}