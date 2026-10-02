#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct p
{
    int fil;
    int col;
};

p posicion(vector<vector<int>> vec, int bloq)
{
    p p1;
    for(int i=0;i<vec.size();i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            if(bloq == vec[i][j])
            {
                p1.col = j;
                p1.fil = i;
                return p1;
            }

        }
    }
}

void funcion( vector<vector<int>> vec, int a , int b, int posX_a, p posA, p posB){
    if(posX_a == posB.col) return;
    int y = vec[posA.fil].size() -1 -posA.fil;
    for(int i=vec[posB.fil].size()-1 ; i>posB.col;i--){
        vec[vec[posB.fil][i]].push_back(vec[posB.fil][i]);
        vec[posB.fil].pop_back();
    }
    vec[posB.fil].push_back(a);
}

void pile(vector<vector<int>> &vec, string h, p pos, int des)
{
    if(h == "onto")
    {



    }
        vector<int> temp;
        for(int i =pos.col;i<vec[pos.fil].size();i++)
        {
            temp.push_back(vec[pos.fil][i]);
        }

        for(int i =pos.col;i<vec[pos.fil].size();i++)
        {
            temp.pop_back();
        }

        for(int i = 0;i<temp.size();i++)
        {
            vec[des].push_back(temp[i]);
        }
        

}


int main ()
{
    int n;
    while(cin>>n)
    {
        vector<vector<int>> vec(n);
        vector<string> comando;
        for(int i=0;i<n;i++)
        {
            vec[i].push_back(i);
        }

        string h;
        string accion;
        int a, b;            
        
        while (cin >> h)
        {
            if (h == "quit")
                break;

            cin >> a >> accion >> b;
            if(h== "move")
            {

            }
            else
            {

            }
    
        }

       


    }
    return 0;
}