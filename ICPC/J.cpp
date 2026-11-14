#include <bits/stdc++.h>
using namespace std;

int main() 
{
    long long filas, columnas;
    cin >> filas >> columnas;
    for (long long r = 1; r <= min(filas - 1, 3LL); r++) 
    {
        for (long long c = 1; c <= min(columnas - 1, 3LL); c++) 
        {
            long long pieza1 = r * c;
            long long pieza2 = r * (columnas - c);
            long long pieza3 = (filas - r) * c;
            long long pieza4 = (filas - r) * (columnas - c);
            set<long long> piezas = {pieza1, pieza2, pieza3, pieza4};
            if (piezas.size() == 4) 
            {
                cout << r << " " << c << "\n";
                return 0;
            }
        }
    }
    cout << "*\n";
    return 0;
}



