#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void combinar(int indice, int k, int n, const vector<int>& s, vector<int>& actual, bool& primero) 
{
    if (actual.size() == 6) 
    {
        if (!primero)  cout << "\n";
        primero = false;
        for (size_t i = 0; i < actual.size(); ++i) 
        {
            if (i > 0) cout << " ";
            cout << actual[i];
        }
        return;
    }
    
    for (int i = indice; i < k; ++i) 
    {
        actual.push_back(s[i]);
        combinar(i + 1, k, n, s, actual, primero);
        actual.pop_back();
    }
}

int main() 
{
    
    int k;
    bool primer_caso = true;
    
    while (cin >> k && k != 0) 
    {
        vector<int> s(k);
        for (int i = 0; i < k; ++i) cin >> s[i];
        
        if (!primer_caso) cout << "\n\n";
        primer_caso = false;
        
        vector<int> actual;
        bool primero = true;
        combinar(0, k, 6, s, actual, primero);
    }
    cout << "\n";
    return 0;
}