#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Elemento
{
    long long tam;
    long long suma_hijos;
};

int main()
{

    string linea;
    while (getline(cin, linea))
    {
        if (linea.empty())
        {
            continue;
        }

        stringstream ss(linea);
        long long x;
        vector<Elemento> st;
        bool ok = true;

        while (ss >> x)
        {
            if (!ok)
            {
                continue;
            }

            if (x < 0)
            {
                st.push_back({-x, 0});
            }
            else
            {
                if (st.empty() || st.back().tam != x)
                {
                    ok = false;
                }
                else
                {
                    Elemento top = st.back();
                    st.pop_back();

                    if (top.suma_hijos >= top.tam)
                    {
                        ok = false;
                    }
                    else
                    {
                        if (!st.empty())
                        {
                            st.back().suma_hijos += top.tam;
                        }
                    }
                }
            }
        }

        if (!st.empty())
        {
            ok = false;
        }

        if (ok)
        {
            cout << ":-) Matrioshka!\n";
        }
        else
        {
            cout << ":-( Try again.\n";
        }
    }

    return 0;
}