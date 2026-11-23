#include <iostream>
#include <vector>

using namespace std;

int main()
{
    const int limite = 46345;
    vector<bool> es_primo(limite + 1, true);
    vector<long long> primos;
    for (int i = 2; i <= limite; ++i)
    {
        if (es_primo[i])
        {
            primos.push_back(i);
            for (long long j = 1LL * i * i; j <= limite; j += i)
            {
                es_primo[j] = false;
            }
        }
    }

    long long n;
    while (cin >> n && n != 0)
    {
        cout << n << " = ";
        long long temp = n;
        bool primero = true;

        if (temp < 0)
        {
            cout << "-1";
            primero = false;
            temp = -temp;
        }

        for (long long p : primos)
        {
            if (p * p > temp)
            {
                break;
            }
            while (temp % p == 0)
            {
                if (!primero)
                {
                    cout << " x ";
                }
                cout << p;
                primero = false;
                temp /= p;
            }
        }

        if (temp > 1)
        {
            if (!primero)
            {
                cout << " x ";
            }
            cout << temp;
        }
        cout << "\n";
    }

    return 0;
}