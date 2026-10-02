#include <iostream>
#include <vector>

using namespace std;

int main() {
    int h;
    int hola = 1;

    while (cin >> h && h != 0) {
        vector<int> vec(h);
        int sum = 0;

        for (int i = 0; i < h; i++) {
            cin >> vec[i];
            sum += vec[i];
        }

        int avg = sum / h;
        int contador = 0;

        for (int i = 0; i < h; i++) {
            if (vec[i] > avg) {
                contador += (vec[i] - avg);
            }
        }

        cout << "Set #" << hola << endl;
        cout << "The minimum number of moves is " << contador << "." << endl << endl;
        hola++;
    }

    return 0;
}