#include <iostream>
#include <vector>
#include <algorithm>
//revisarr nose que esta mal 
using namespace std;

struct caja{int tam; int b;};

int main()
{
    int nro;
    while(cin >> nro)
    {
        vector <int> pila;
        for(int i = 0; i < nro; i++)
        {
            int n;
            cin >> n;
            pila.push_back(n);
        }
        //int pivot = pila[0];
        vector <caja> P;
        int maxH = 0;
        for(int i = 0; i < nro; i++)
        {
            int x = pila[i];
            int baseActual = 0;
            while(!P.empty())
            {
                caja tope = P.back();
                if(x < tope.tam && baseActual + x <= tope.b + tope.tam)
                { 
                    baseActual = max(baseActual, tope.b); 
                    break;
                }
                else 
                {
                    baseActual = max(baseActual, tope.b+ tope.tam);
                    P.pop_back();
                }
            }
            caja nueva;
            nueva.tam = x;
            nueva.b = baseActual;
            P.push_back(nueva);
            maxH = max(maxH, nueva.b + nueva.tam);
        }
        cout << maxH << '\n';     
   }
    return 0;
}