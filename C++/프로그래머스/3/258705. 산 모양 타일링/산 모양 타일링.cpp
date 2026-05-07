#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> tops) {
    int answer = 0;
    
    vector<int> dpBot(2*n+1, 0);
    vector<int> dpTop(n, 0);
    
    dpBot[0] = 1, dpBot[1] = 2;
    if(tops[0] == 1) dpTop[0] = 3;
    for(int i = 2; i < 2*n+1; i++)
    {
        if(i%2 == 0) // 사다리꼴 아랫변
        {
            //앞에꺼랑 합친 마름모 타일
            dpBot[i] += dpBot[i-2];
            
            //현재 삼각형 타일만
            if(tops[(i-2)/2] == 1)
                dpBot[i] += dpTop[(i-2)/2];
            else dpBot[i] += dpBot[i-1];

        }
        else //사다리꼴 윗변
        {
            //윗변 기준 아래 삼각형
            //현재 삼각형 타일만
            dpBot[i] += dpBot[i-1];
            
            //앞에꺼랑 합친 마름모 타일
            if(tops[(i-3)/2] == 1)
                dpBot[i] += dpTop[(i-3)/2];
            else dpBot[i] += dpBot[i-2];
            
            //윗변 기준 위 삼각형
            
            if(tops[(i-1)/2] == 1)
            {
                //현재 삼각형 타일만
                dpTop[(i-1)/2] += dpBot[i];
            
                //밑에꺼랑 합친 마름모 타일
                dpTop[(i-1)/2] += dpBot[i-1];
                dpTop[(i-1)/2]%=10007;
            }
        }
        dpBot[i]%=10007;
    }
    return dpBot[2*n];
}