#include <string>
#include <vector>

using namespace std;

int solution(int coin, vector<int> cards) {
    int n = cards.size();
    vector<bool> hand(n + 1, false);
    vector<bool> drawn(n + 1, false);
    
    int round = 1;
    int idx = 0;
    
    for (; idx < n / 3; idx++)
        hand[cards[idx]] = true;
    
    
    while (idx < n) 
    {
        drawn[cards[idx++]] = true;
        drawn[cards[idx++]] = true;
        
        bool pass = false;
        
        for (int i = 1; i <= n; i++) 
        {
            if (hand[i] && hand[n + 1 - i]) 
            {
                hand[i] = false;
                hand[n + 1 - i] = false;
                pass = true;
                break;
            }
        }
        
        if (!pass && coin >= 1) 
        {
            for (int i = 1; i <= n; i++) 
            {
                if (hand[i] && drawn[n + 1 - i]) 
                {
                    hand[i] = false;
                    drawn[n + 1 - i] = false;
                    coin -= 1;
                    pass = true;
                    break;
                }
            }
        }
        
        if (!pass && coin >= 2) 
        {
            for (int i = 1; i <= n; i++) 
            {
                if (drawn[i] && drawn[n + 1 - i]) 
                {
                    drawn[i] = false;
                    drawn[n + 1 - i] = false;
                    coin -= 2;
                    pass = true;
                    break;
                }
            }
        }
        
        if (!pass) break;
        round++;
    }
    
    return round;
}