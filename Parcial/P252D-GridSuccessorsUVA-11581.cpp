#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <unordered_map>

using namespace std;

using Cuadricula = array<array<int, 3>, 3>;

int convertir_a_entero(const Cuadricula& g) {
    int valor = 0;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            valor = valor * 2 + g[i][j];
    return valor;
}

Cuadricula obtener_siguiente(const Cuadricula& g) {
    static const int movimiento_fila[] = {-1, 1, 0, 0};
    static const int movimiento_columna[] = {0, 0, -1, 1};
    Cuadricula siguiente{};
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            int suma = 0;
            for (int d = 0; d < 4; ++d) {
                int ni = i + movimiento_fila[d], nj = j + movimiento_columna[d];
                if (ni >= 0 && ni < 3 && nj >= 0 && nj < 3)
                    suma += g[ni][nj];
            }
            siguiente[i][j] = suma % 2;
        }
    }
    return siguiente;
}

int resolver(Cuadricula g) {
    unordered_map<int, int> primera_aparicion; 
    int paso = 0;
    while (true) {
        int valor = convertir_a_entero(g);
        if (primera_aparicion.count(valor)) {
            int inicio_ciclo = primera_aparicion[valor];
            return inicio_ciclo - 1;   
        }
        primera_aparicion[valor] = paso;
        g = obtener_siguiente(g);
        ++paso;
    }
}

int main() {

    int total_casos;
    if (cin >> total_casos) {
        while (total_casos--) {
            Cuadricula g;
            for (int i = 0; i < 3; ++i) {
                string fila;
                cin >> fila;
                for (int j = 0; j < 3; ++j)
                    g[i][j] = fila[j] - '0';
            }
            cout << resolver(g) << '\n';
        }
    }

    return 0;
}