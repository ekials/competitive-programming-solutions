#include <iostream>
#include <bitset>
using namespace std;

int caso, obj, cant, cal;

int main()
{
    cin >> caso;
    while(caso --)
    {
        cin >> obj >> cant;
        bitset <300005> bs;
        bs[0] = 1;

        for(int  i = 0; i < cant; i++)
        {
            cin >> cal;
            bs |= (bs << cal);
        }
        int rpta = -1;
        for(int i = obj; i < 300005; i++)
        {
           if(bs[i])
           {
             rpta = i;
             break;
           }
        } 

        if(rpta != -1) cout << rpta << "\n";
        else cout << "NO SOLUTION\n";
    }
    return 0;
}