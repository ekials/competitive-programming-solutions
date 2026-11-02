#include <iostream>
#include <string>

using namespace std;

const double EPS = 1e-9;

char obtener_caracter(double re, double im, const string& chars) {
    double zr = 0, zi = 0;
    for (int iter = 0; iter < 12; ++iter) {
        double nuevo_zr = zr * zr - zi * zi + re;
        double nuevo_zi = 2 * zr * zi + im;
        zr = nuevo_zr;
        zi = nuevo_zi;
        if (zr * zr + zi * zi > 4.0 + EPS)
            return chars[iter];
    }
    return ' ';
}

int main() {
    int t;
    cin >> t;
    for (int caso = 0; caso < t; ++caso) {
        string entrada;
        double min_i, max_i, prec_i, min_r, max_r, prec_r;
        cin >> entrada >> min_i >> max_i >> prec_i >> min_r >> max_r >> prec_r;
        string chars = entrada.substr(1, 12);

        if (caso > 0) cout << '\n';

        for (int f = 0; min_i + f * prec_i <= max_i + EPS; ++f) {
            double im = min_i + f * prec_i;
            string linea;
            for (int c = 0; min_r + c * prec_r <= max_r + EPS; ++c) {
                double re = min_r + c * prec_r;
                linea += obtener_caracter(re, im, chars);
            }
            cout << linea << '\n';
        }
    }
    return 0;
}