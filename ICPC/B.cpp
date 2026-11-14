#include <bits/stdc++.h>
using namespace std;

int n;
vector<long long> arbol;

void sumar(int i, long long valor) {
    for (; i <= n; i += i & (-i)) arbol[i] += valor;
}

long long consultar(int i) {
    long long total = 0;
    for (; i > 0; i -= i & (-i)) total += arbol[i];
    return total;
}

int main() 
{
    long long d;
    cin >> n >> d;
    vector<long long> x(n), y(n), peso(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i] >> peso[i];

    vector<int> orden1(n), orden2(n);
    iota(orden1.begin(), orden1.end(), 0);
    iota(orden2.begin(), orden2.end(), 0);

    sort(orden1.begin(), orden1.end(), [&](int a, int b) 
    {
        return y[a] * x[b] < y[b] * x[a];
    });
    sort(orden2.begin(), orden2.end(), [&](int a, int b) 
    {
        return y[a] * (d - x[b]) < y[b] * (d - x[a]);
    });

    vector<int> posicion(n);
    for (int i = 0; i < n; i++) posicion[orden2[i]] = i + 1;

    arbol.assign(n + 1, 0);
    long long respuesta = 0;
    long long sumaVistos = 0;
    for (int i = 0; i < n; i++) {
        int gato = orden1[i];
        int p = posicion[gato];
        long long mayores = sumaVistos - consultar(p);
        respuesta += mayores * peso[gato];
        sumar(p, peso[gato]);
        sumaVistos += peso[gato];
    }
    cout << respuesta << "\n";
    return 0;
}
