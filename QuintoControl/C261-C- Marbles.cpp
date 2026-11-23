#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n;
    while (cin >> n && n != 0)
    {
        long long c1, n1, c2, n2;
        cin >> c1 >> n1 >> c2 >> n2;

        long long a = n1;
        long long b = n2;
        long long x = 1, y = 0;
        long long x1 = 0, y1 = 1;
        long long a1 = a, b1 = b;

        while (b1 != 0)
        {
            long long cociente = a1 / b1;
            long long temporal = b1;
            b1 = a1 - cociente * b1;
            a1 = temporal;

            temporal = x1;
            x1 = x - cociente * x1;
            x = temporal;

            temporal = y1;
            y1 = y - cociente * y1;
            y = temporal;
        }

        long long mcd = a1;

        if (n % mcd != 0)
        {
            cout << "failed\n";
            continue;
        }

        long long x0 = x * (n / mcd);
        long long y0 = y * (n / mcd);
        long long paso_x = n2 / mcd;
        long long paso_y = n1 / mcd;

        long long k_min;
        if (x0 >= 0)
        {
            k_min = -(x0 / paso_x);
        }
        else
        {
            k_min = (-x0 + paso_x - 1) / paso_x;
        }

        long long k_max;
        if (y0 >= 0)
        {
            k_max = y0 / paso_y;
        }
        else
        {
            k_max = -((-y0 + paso_y - 1) / paso_y);
        }

        if (k_min > k_max)
        {
            cout << "failed\n";
            continue;
        }

        long long m1_a = x0 + k_min * paso_x;
        long long m2_a = y0 - k_min * paso_y;

        long long m1_b = x0 + k_max * paso_x;
        long long m2_b = y0 - k_max * paso_y;

        if (m1_a * c1 + m2_a * c2 <= m1_b * c1 + m2_b * c2)
        {
            cout << m1_a << " " << m2_a << "\n";
        }
        else
        {
            cout << m1_b << " " << m2_b << "\n";
        }
    }

    return 0;
}