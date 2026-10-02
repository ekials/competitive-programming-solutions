#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    while(cin >> N >> M && (N != 0 || M != 0))
    {
        vector <int> discosN;
        vector <int> discosM;
       
        for(int i = 0; i < N; i++)
        {
            int n;
            cin >> n;
            discosN.push_back(n);
        }
        for(int i = 0; i < M; i++)
        {
            int n;
            cin >> n;
            discosM.push_back(n);
        }

        
        int j = 0;
        int i = 0;
        int cont = 0;
        while (i < N && j < M)
        {
            if (discosN[i] == discosM[j]) 
            {
                cont++;
                i++;
                j++;
            } 
            else if (discosN[i] < discosM[j]) i++;
            else j++;
        }
    cout << cont << "\n";
    }
    return 0;
}