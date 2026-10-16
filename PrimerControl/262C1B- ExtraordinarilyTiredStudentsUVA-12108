#include <iostream>
#include <vector>

using namespace std;

struct est 
{
    int a; 
    int b;   
    int c;  
};

int main() 
{
    int cant_est, nroCaso = 1;

    while (cin >> cant_est && cant_est != 0) 
    {
        vector<est> estudiantes(cant_est);
        for (int i = 0; i < cant_est; ++i) 
        {
            cin >> estudiantes[i].a >> estudiantes[i].b >> estudiantes[i].c;
        }

        int rptaMin = -1;

        for (int m = 1; m <= 10000; m++) 
        {
            int contDorm = 0;

            for (int i = 0; i < cant_est; i++) 
            {
                if (estudiantes[i].c > estudiantes[i].a) contDorm++;    
            }

            int contDesp = cant_est - contDorm;
            if (contDesp == cant_est) 
            {
                rptaMin = m;
                break;
            }

            for (int i = 0; i < cant_est; i++) 
            {
                if (estudiantes[i].c == estudiantes[i].a) 
                {
                    if (contDorm > contDesp)estudiantes[i].c++; 
                    else estudiantes[i].c = 1;
                } 
                else if (estudiantes[i].c == estudiantes[i].a + estudiantes[i].b) estudiantes[i].c = 1;
                
                else estudiantes[i].c++; 
                
            }
        }

        cout << "Case " << nroCaso++ << ": " << rptaMin << "\n";
    }

    return 0;
}