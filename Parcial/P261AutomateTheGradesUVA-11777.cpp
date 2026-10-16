#include <iostream>
#include <algorithm>

using namespace std;

int casos, term1, term2, final_, asistencia, p1, p2, p3;

int main() {
    cin >> casos;
    for (int caso = 1; caso <= casos; ++caso) {
        cin >> term1 >> term2 >> final_ >> asistencia >> p1 >> p2 >> p3;
        int menor = min({p1, p2, p3});
        double clase = (p1 + p2 + p3 - menor) / 2.0;
        double total = term1 + term2 + final_ + asistencia + clase;
        char nota = 'F';
        if (total >= 90) nota = 'A';
        else if (total >= 80) nota = 'B';
        else if (total >= 70) nota = 'C';
        else if (total >= 60) nota = 'D';
        cout << "Case " << caso << ": " << nota << "\n";
    }
    return 0;
}