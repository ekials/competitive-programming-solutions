#include <iostream>

using namespace std;

int main()
{
    long long m1, n;
    while (cin >> m1 >> n && m1 >= 0)
    {
        long long total_n = 0;
        if (n >= 0)
        {
            total_n = 1;
            long long potencia = 1;
            while (potencia <= n / 10)
            {
                long long izquierda = n / (potencia * 10);
                long long actual = (n / potencia) % 10;
                long long derecha = n % potencia;

                if (actual == 0)
                {
                    total_n += (izquierda - 1) * potencia + derecha + 1;
                }
                else
                {
                    total_n += izquierda * potencia;
                }
                potencia *= 10;
            }
        }

        long long limite_m = m1 - 1;
        long long total_m = 0;
        if (limite_m >= 0)
        {
            total_m = 1;
            long long potencia = 1;
            while (potencia <= limite_m / 10)
            {
                long long izquierda = limite_m / (potencia * 10);
                long long actual = (limite_m / potencia) % 10;
                long long derecha = limite_m % potencia;

                if (actual == 0)
                {
                    total_m += (izquierda - 1) * potencia + derecha + 1;
                }
                else
                {
                    total_m += izquierda * potencia;
                }
                potencia *= 10;
            }
        }

        cout << total_n - total_m << "\n";
    }

    return 0;
}