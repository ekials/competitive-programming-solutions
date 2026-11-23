#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string A;
    while (getline(cin, A))
    {
        int palabras = 0;
        bool en_palabra = false;
        for(char c : A)
        {
            if(isalpha(c))
            {
                if(!en_palabra)
                {
                    palabras++;
                    en_palabra = true;
                }
            }
                else
                {
                    en_palabra = false;
                }
            

        }
        
        cout << palabras << "\n";
    }

    return 0;
}

