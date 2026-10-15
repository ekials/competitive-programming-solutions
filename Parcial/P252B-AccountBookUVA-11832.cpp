#include <iostream>
#include <vector>
#include <string>

using namespace std;

int cantidad, objetivo, valores[45];
bool izq[45][80005], der[45][80005];
const int offset = 40005;

int main() 
{
    while (cin >> cantidad >> objetivo && (cantidad || objetivo)) {
        for (int i = 0; i < cantidad; ++i) cin >> valores[i];
        
        for (int i = 0; i <= cantidad; ++i)
            for (int j = 0; j <= 80000; ++j)
                izq[i][j] = der[i][j] = false;
        
        izq[0][offset] = true;
        for (int i = 0; i < cantidad; ++i) {
            for (int j = 0; j <= 80000; ++j) {
                if (izq[i][j]) {
                    izq[i+1][j + valores[i]] = true;
                    izq[i+1][j - valores[i]] = true;
                }
            }
        }
        
        der[cantidad][offset] = true;
        for (int i = cantidad - 1; i >= 0; --i) {
            for (int j = 0; j <= 80000; ++j) {
                if (der[i+1][j]) {
                    der[i][j + valores[i]] = true;
                    der[i][j - valores[i]] = true;
                }
            }
        }
        
        if (!izq[cantidad][offset + objetivo]) {
            cout << "*\n";
            continue;
        }
        
        string respuesta = "";
        for (int i = 0; i < cantidad; ++i) {
            bool pos = false, neg = false;
            int tp = objetivo + 2 * offset - valores[i];
            int tn = objetivo + 2 * offset + valores[i];
            for (int j = 0; j <= 80000; ++j) {
                if (izq[i][j]) {
                    int rp = tp - j;
                    if (rp >= 0 && rp <= 80000 && der[i+1][rp]) pos = true;
                    int rn = tn - j;
                    if (rn >= 0 && rn <= 80000 && der[i+1][rn]) neg = true;
                }
                if (pos && neg) break;
            }
            if (pos && neg) respuesta += '?';
            else if (pos) respuesta += '+';
            else if (neg) respuesta += '-';
            else respuesta += '*';
        }
        cout << respuesta << "\n";
    }
    return 0;
}