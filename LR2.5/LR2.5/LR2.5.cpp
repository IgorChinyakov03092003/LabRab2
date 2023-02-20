#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int N = 10;
    int x;
    queue<int> a;
    queue<int> b;                       // cards of players relised on queue structure      
    for (int i = 0; i < N / 2; i++) {
        cin >> x;
        a.push(x);
    }
    for (int i = 0; i < N / 2; i++) {
        cin >> x;
        b.push(x);
    }                                   // add cards of players
    int moves = 0;                      // moves counter
    for (; !a.empty() && !b.empty() && moves <= 1000000; ++moves) {
        int ac = a.front(), bc=b.front();           // lift top cards
        a.pop(); b.pop();                           // delete top cards from the top of the CardDecks
        queue<int>* win = (ac == 0 && bc == N - 1) ? &a :   // define winner, get adress where to add cards
            (bc == 0 && ac == N - 1) ? &b :
            (ac > bc) ? &a : &b;
        win->push(ac); win->push(bc);       // add cards to the winner
    }
    if (a.empty()) cout << "second " << moves;
    else if (b.empty()) cout << "first " << moves;  // define winner
    else cout << "botva";           // draw if moves > 10^6
    return 0;
}

