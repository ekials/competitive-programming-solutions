#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<int> validos = {2, 3, 5, 7, 13, 17};
    int n;
    if (cin >> n)
    {
        string linea;
        cin >> linea;
        size_t pos = 0;
        for (int i = 0; i < n; ++i)
        {
            size_t coma = linea.find(',', pos);
            int p = stoi(linea.substr(pos, coma - pos));
            pos = coma + 1;

            bool es_perfecto = false;
            for (int v : validos)
            {
                if (p == v)
                {
                    es_perfecto = true;
                    break;
                }
            }
            cout << (es_perfecto ? "Yes\n" : "No\n");
        }
    }

    return 0;
}