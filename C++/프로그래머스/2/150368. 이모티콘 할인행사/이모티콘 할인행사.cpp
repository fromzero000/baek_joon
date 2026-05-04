#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    vector<int> answer;
    int n = users.size();
    int m = emoticons.size();
    answer.resize(2, 0);
    vector<int> discounts(m, 0);
    auto solve = [&](auto& self, int user, int totalUsers, int totalPurchase)->void{
        if(user == n)
        {
            if(totalUsers > answer[0] || (totalUsers == answer[0]) && (totalPurchase > answer[1]))
            {
                answer[0] = totalUsers;
                answer[1] = totalPurchase;
            }
            return;
        }
        int purchase = 0;
        for(int emo = 0; emo < m; emo++)
            if(users[user][0] <= discounts[emo]) purchase += emoticons[emo]*(100-discounts[emo])/100;
        if(purchase >= users[user][1]) self(self, user+1, totalUsers+1, totalPurchase);
        else self(self, user+1, totalUsers, totalPurchase+purchase);
    };
    auto selectDiscount = [&](auto& self, int emo)->void{
        if(emo == m)
        {
            solve(solve, 0, 0, 0);
            return;
        }
        for(int dc = 10; dc <= 40; dc+=10)
        {
            discounts[emo] = dc;
            self(self, emo+1);
            discounts[emo] = 0;
        }
    };
    selectDiscount(selectDiscount, 0);
    return answer;
}