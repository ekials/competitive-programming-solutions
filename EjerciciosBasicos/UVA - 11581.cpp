#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    char x;

    while (cin >> x)
    {
        if (x == '.')
        {
            cout << endl;
            continue;
        }

        vector<char> funciones;
        vector<vector<char>> llamadas(256);

        while (x != '.')
        {
            if (x == '(')
            {
                char origen;
                cin >> origen;
                bool existe = false;

                for (char f : funciones)
                {
                    if (f == origen)
                    {
                        existe = true;
                        break;
                    }
                }

                if (!existe) funciones.push_back(origen);

                cin >> x;

                while (x != ')')
                {
                    llamadas[(int)origen].push_back(x);
                    bool existe2 = false;

                    for (char f : funciones)
                    {
                        if (f == x)
                        {
                            existe2 = true;
                            break;
                        }
                    }

                    if (!existe2) funciones.push_back(x);
                    cin >> x;
                }
            }

            cin >> x;
        }

        vector<vector<char>> alcanza(256);

        for (char inicio : funciones)
        {
            vector<char> encontrados;

            for (char siguiente : llamadas[(int)inicio])
            {
                bool esta = false;

                for (char f : encontrados)
                {
                    if (f == siguiente)
                    {
                        esta = true;
                        break;
                    }
                }

                if (!esta) encontrados.push_back(siguiente);
            }

            bool cambio = true;

            while (cambio)
            {
                cambio = false;

                for (int i = 0; i < encontrados.size(); i++)
                {
                    char actual = encontrados[i];

                    for (char siguiente : llamadas[(int)actual])
                    {
                        bool esta = false;

                        for (char f : encontrados)
                        {
                            if (f == siguiente)
                            {
                                esta = true;
                                break;
                            }
                        }

                        if (!esta)
                        {
                            encontrados.push_back(siguiente);
                            cambio = true;
                        }
                    }
                }
            }

            alcanza[(int)inicio] = encontrados;
        }


        sort(funciones.begin(), funciones.end());

        vector<bool> usado(256, false);
        for (char a : funciones)
        {
            if (usado[(int)a])
                continue;

            vector<char> modulo;
        for (char b : funciones)
            {
                if (usado[(int)b])
                    continue;

                bool aLlegaB = false;
                bool bLlegaA = false;

                for (char f : alcanza[(int)a])
                {
                    if (f == b)
                    {
                        aLlegaB = true;
                        break;
                    }
                }

                for (char f : alcanza[(int)b])
                {
                    if (f == a)
                    {
                        bLlegaA = true;
                        break;
                    }
                }       

                if (aLlegaB && bLlegaA)
                {
                    modulo.push_back(b);
                    usado[(int)b] = true;
                }
            }

            sort(modulo.begin(), modulo.end());

            for (int i = 0; i < modulo.size(); i++)
            {
                if (i > 0) cout << " ";

                cout << modulo[i];
            }

            cout << endl;
        }

        cout << endl;
    }

    return 0;
}