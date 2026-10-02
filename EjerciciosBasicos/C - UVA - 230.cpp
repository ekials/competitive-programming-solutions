#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Book 
{
    string title;
    string author;

    bool operator<(const Book& other) const 
    {
        if (author != other.author) return author < other.author;
        return title < other.title;
    }
};

int main() 
{

    vector<Book> books;
    string line;

    while (getline(cin, line) && line != "END") 
    {
        size_t quote_pos = line.find('"', 1);
        string title = line.substr(0, quote_pos + 1);
        string author = line.substr(quote_pos + 5);
        books.push_back({title, author});
    }

    sort(books.begin(), books.end());

    int n = books.size();
    map<string, int> title_to_index;
    for (int i = 0; i < n; ++i) title_to_index[books[i].title] = i;

    vector<bool> on_shelf(n, true);
    vector<bool> returned(n, false);

    string command;
    while (cin >> command && command != "END") 
    {
        if (command == "BORROW") 
        {
            cin.ignore();
            getline(cin, line);
            int idx = title_to_index[line];
            on_shelf[idx] = false;
            returned[idx] = false;
        } 
        else if (command == "RETURN") 
        {
            cin.ignore();
            getline(cin, line);
            int idx = title_to_index[line];
            returned[idx] = true;
        }
         else if (command == "SHELVE") 
        {
            for (int i = 0; i < n; ++i) 
            {
                if (returned[i]) 
                {
                    int prev = -1;
                    for (int j = i - 1; j >= 0; --j) 
                    {
                        if (on_shelf[j]) 
                        {
                            prev = j;
                            break;
                        }
                    }
                    if (prev == -1) 
                    {
                        cout << "Put " << books[i].title << " first\n";
                    }
                    else 
                    {
                        cout << "Put " << books[i].title << " after " << books[prev].title << "\n";
                    }
                    on_shelf[i] = true;
                    returned[i] = false;
                }
            }
            cout << "END\n";
        }
    }

    return 0;
}