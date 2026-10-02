#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N, Q;
    int caso = 1;

    while(cin >> N >> Q && (N != 0 || Q != 0) )
    {
        
        vector <int> canicas;
        for(int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            canicas.push_back(n);
        }
        sort(canicas.begin(), canicas.end());

        cout << "CASE# " << caso << ":" << endl;

        for(int q = 0; q < Q; q++)
        {
            int nro;
            cin >> nro;
   
            bool encontrado = false;

            for(int j = 0; j < (int)canicas.size(); j++ )
            {
                int pos = j + 1;
                if(nro == canicas[j])
                {
                    cout << nro << " found at " << pos << endl; 
                    encontrado = true;
                    break;  
                }
            }
               if(!encontrado)cout << nro << " not found" << endl; 
        } 
        caso ++;
    }

    return 0;
}