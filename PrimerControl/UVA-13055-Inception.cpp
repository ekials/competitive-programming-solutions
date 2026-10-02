#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    stack<string> pila;
    
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        if (op == "Sleep") {
            string x;
            cin >> x;
            pila.push(x);
        } else if (op == "Kick") {
            if (!pila.empty()) {
                pila.pop();
            }
        } else if (op == "Test") {
            if (pila.empty()) {
                cout << "Not in a dream\n";
            } else {
                cout << pila.top() << "\n";
            }
        }
    }
    
    return 0;
}