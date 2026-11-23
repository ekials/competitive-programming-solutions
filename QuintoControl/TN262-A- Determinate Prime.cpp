#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    const int limite = 32005;
    vector<bool> es_primo(limite + 1, true);
    es_primo[0] = es_primo[1] = false;
    vector<int> primos;

    for (int i = 2; i <= limite; ++i)
    {
        if (es_primo[i])
        {
            primos.push_back(i);
            for (int j = i * i; j <= limite; j += i)
            {
                es_primo[j] = false;
            }
        }
    }

    vector<vector<int>> conjuntos;
    int n = primos.size();
    int i = 0;
    while (i + 2 < n)
    {
        int dif = primos[i + 1] - primos[i];
        if (primos[i + 2] - primos[i + 1] == dif)
        {
            vector<int> actual = {primos[i], primos[i + 1], primos[i + 2]};
            int j = i + 3;
            while (j < n && primos[j] - primos[j - 1] == dif)
            {
                actual.push_back(primos[j]);
                ++j;
            }
            conjuntos.push_back(actual);
            i = j - 1;
        }
        else
        {
            ++i;
        }
    }

    int x, y;
    while (cin >> x >> y && (x != 0 || y != 0))
    {
        if (x > y)
        {
            swap(x, y);
        }
        for (const auto& c : conjuntos)
        {
            if (c.front() >= x && c.back() <= y)
            {
                for (size_t k = 0; k < c.size(); ++k)
                {
                    cout << c[k] << (k + 1 == c.size() ? "" : " ");
                }
                cout << "\n";
            }
        }
    }

    return 0;
}