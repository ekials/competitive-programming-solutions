#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int casos;
    if (!(cin >> casos))
    {
        return 0;
    }

    for (int numero_caso = 1; numero_caso <= casos; numero_caso++)
    {
        long long n, k, mod;
        cin >> n >> k >> mod;

        long long suma = 0;
        for (int i = 0; i < n; i++)
        {
            long long elemento;
            cin >> elemento;
            suma = (suma + elemento) % mod;
        }

        long long base = n % mod;
        long long exponente = k - 1;
        long long potencia = 1 % mod;

        while (exponente > 0)
        {
            if (exponente % 2 == 1)
            {
                potencia = (potencia * base) % mod;
            }
            base = (base * base) % mod;
            exponente /= 2;
        }

        long long resultado = (k % mod) * potencia % mod;
        resultado = (resultado * suma) % mod;

        cout << "Case " << numero_caso << ": " << resultado << "\n";
    }

    return 0;
}