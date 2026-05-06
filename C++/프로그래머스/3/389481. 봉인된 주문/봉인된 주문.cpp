#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(long long n, vector<string> bans) {
    string answer = "";
    vector<long long> bansNum(bans.size());
    long long target = n;
    for(int i = 0; i < bans.size(); i++)
    {   
        long long pos = 1; 
        for(int j = bans[i].length()-1; j >= 0; j--)
        {
            bansNum[i] += (bans[i][j]-'a'+1)*pos;
            pos *= 26;
        }
    }
    sort(bansNum.begin(), bansNum.end());
    for(int i = 0; i < bansNum.size(); i++)
    {
        if(target >= bansNum[i])
            target++;
        else break;
    }
    
    while(target)
    {
        target--;
        answer += (char)('a'+target%26);
        target /= 26;
    }
    reverse(answer.begin(), answer.end());
    return answer;
}