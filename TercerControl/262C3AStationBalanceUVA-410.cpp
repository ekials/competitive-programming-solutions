#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    
    int camaras, especimenes;
    int numero_caso = 1;

    while (cin >> camaras >> especimenes) {
          vector<double> masas(2 * camaras, 0.0);
        double suma_masas = 0;

        for (int i = 0; i < especimenes; ++i) {
            cin >> masas[i];
            suma_masas += masas[i];
        }

       
        sort(masas.begin(), masas.end());

        double masa_promedio = suma_masas / camaras; 
        double desbalance = 0.0;

        cout << "Set #" << numero_caso++ << "\n";

        for (int i = 0; i < camaras; ++i) {
            double masa_camara = masas[i] + masas[2 * camaras - 1 - i];
            desbalance += abs(masa_camara - masa_promedio);

            cout << " " << i << ":";
            if (masas[i] > 0) {
                cout << " " << (int)masas[i];
            }
            if (masas[2 * camaras - 1 - i] > 0) {
                cout << " " << (int)masas[2 * camaras - 1 - i];
            }
            cout << "\n";
        }

        cout << fixed << setprecision(5);
        cout << "IMBALANCE = " << desbalance << "\n\n";
    }

    return 0;
}