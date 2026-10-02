#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Med
{
    long long t;
    int f;
    int id;
    string nom;

    bool operator>(const Med& o) const
    {
        if (t != o.t)
        {
            return t > o.t;
        }
        return id > o.id;
    }
};

void sol()
{
    int n, k;
    if (!(cin >> n >> k))
    {
        return;
    }

    priority_queue<Med, vector<Med>, greater<Med>> pq;

    for (int i = 0; i < n; ++i)
    {
        string nom;
        int f;
        cin >> nom >> f;
        pq.push({f, f, i, nom});
    }

    for (int i = 0; i < k; ++i)
    {
        Med act = pq.top();
        pq.pop();

        cout << act.t << " " << act.nom << "\n";

        act.t += act.f;
        pq.push(act);
    }
}

int main()
{

    int t;
    if (cin >> t)
    {
        while (t--)
        {
            sol();
        }
    }

    return 0;
}