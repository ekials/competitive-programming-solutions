#include <bitset>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const int MAXB = 101;

bitset<MAXB> a_bits(const string& s) {
    bitset<MAXB> b;
    for (int i = 0; i < (int)s.size(); ++i)
        if (s[i] == '1') b.set(i);
    return b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, q;
    cin >> m >> q;
    vector<bitset<MAXB>> pelis(m);
    vector<int> largo(m);
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        pelis[i] = a_bits(s);
        largo[i] = s.size();
    }

    while (q--) {
        string s;
        cin >> s;
        int l = s.size();
        bitset<MAXB> clip = a_bits(s), mascara;
        for (int i = 0; i < l; ++i) mascara.set(i);

        int mejor = l + 1, indice = -1;
        for (int i = 0; i < m; ++i) {
            for (int off = 0; off + l <= largo[i]; ++off) {
                int dif = (((pelis[i] >> off) ^ clip) & mascara).count();
                if (dif < mejor) {
                    mejor = dif;
                    indice = i + 1;
                }
            }
        }
        cout << indice << '\n';
    }
    return 0;
}