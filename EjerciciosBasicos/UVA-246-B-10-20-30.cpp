#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

struct State 
{
    deque<int> deck;
    vector<deque<int>> piles;

    bool operator<(const State& other) const 
    {
        if (deck != other.deck) return deck < other.deck;
        return piles < other.piles;
    }
};

void processPile(deque<int>& deck, deque<int>& pile) 
{
    while (pile.size() >= 3) 
    {
        int n = pile.size();
        
        int c1 = pile[0], c2 = pile[1], c3 = pile[n - 1];
        if ((c1 + c2 + c3) % 10 == 0) {
            deck.push_back(c1);
            deck.push_back(c2);
            deck.push_back(c3);
            pile.pop_front();
            pile.pop_front();
            pile.pop_back();
            continue;
        }

        c1 = pile[0]; c2 = pile[n - 2]; c3 = pile[n - 1];
        if ((c1 + c2 + c3) % 10 == 0) 
        {
            deck.push_back(c1);
            deck.push_back(c2);
            deck.push_back(c3);
            pile.pop_front();
            pile.pop_back();
            pile.pop_back();
            continue;
        }

        c1 = pile[n - 3]; c2 = pile[n - 2]; c3 = pile[n - 1];
        if ((c1 + c2 + c3) % 10 == 0) 
        {
            deck.push_back(c1);
            deck.push_back(c2);
            deck.push_back(c3);
            pile.pop_back();
            pile.pop_back();
            pile.pop_back();
            continue;
        }

        break;
    }
}

int main() 
{

    while (true)
    {
        int first_card;
        if (!(cin >> first_card) || first_card == 0) break;

        deque<int> initial_deck;
        initial_deck.push_back(first_card);

        for (int i = 1; i < 52; ++i) 
        {
            int card;
            cin >> card;
            initial_deck.push_back(card);
        }

         vector<deque<int>> piles;
        for (int i = 0; i < 7; ++i) 
        {
            deque<int> pile;
            pile.push_back(initial_deck.front());
            initial_deck.pop_front();
            piles.push_back(pile);
        }

        int count = 7;
        int current_pile = 0;
        set<State> visited_states;

        while (true) 
        {
            State current_state = {initial_deck, piles};
            if (visited_states.count(current_state)) 
            {
                cout << "Draw: " << count << "\n";
                break;
            }
            visited_states.insert(current_state);

            if (initial_deck.empty()) 
            {
                cout << "Loss: " << count << "\n";
                break;
            }

            int card = initial_deck.front();
            initial_deck.pop_front();
            count++;

            piles[current_pile].push_back(card);

            processPile(initial_deck, piles[current_pile]);

            if (piles[current_pile].empty())
            {
                piles.erase(piles.begin() + current_pile);
                if (piles.empty()) 
                {                    
                    cout << "Win : " << count << "\n";
                    break;
                }
                current_pile %= piles.size();
            } 
            else  current_pile = (current_pile + 1) % piles.size();
            
        }
    }

    return 0;
}