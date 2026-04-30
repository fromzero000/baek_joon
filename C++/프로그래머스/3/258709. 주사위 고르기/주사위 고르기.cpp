#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int maxWin = -1;
    int n = dice.size();
    vector<bool> chooseA(n, false);
    for(int i = n/2; i < n; i++)
        chooseA[i] = true;
    
    do
    {
        vector<int> a, b;
        for(int i = 0; i < n; i++)
        {
            if(chooseA[i]) a.push_back(i);
            else b.push_back(i);
        }
        auto sums = [&](auto& self, const vector<int>& dices, vector<int>& v, int cur, int depth)->void{
            if(depth == n/2) 
            {
                v.push_back(cur);
                return;
            }
            for(int i = 0; i < 6; i++)
                self(self, dices, v, cur+dice[dices[depth]][i], depth+1);
        };
        vector<int> sumA, sumB;
        sums(sums, a, sumA, 0, 0);
        sums(sums, b, sumB, 0, 0);

        sort(sumB.begin(), sumB.end(), less<int>());
        int winCnt = 0;
        for(int suma : sumA)
        {
            auto lower = lower_bound(sumB.begin(), sumB.end(), suma)-sumB.begin();
            winCnt += lower;
        }
        if(winCnt > maxWin)
        {
            answer = move(a);
            maxWin = winCnt;
        }
    }while(next_permutation(chooseA.begin(), chooseA.end()));
    
    for(int i = 0; i < answer.size(); i++)
        answer[i]++;
    return answer;
}