#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<long long> numbers) {
    int n = numbers.size();
    vector<int> answer(n);
    auto toFullBinTree = [](long long num)->string{
        string bin{};
        while(num > 0)
        {
            bin += to_string(num%2);
            num /= 2;
        }
        reverse(bin.begin(), bin.end());
        int len = bin.length();
        int msb = 1;
        while(msb < len) msb = msb*2+1;
        while(bin.length() < msb) bin = "0"+bin;
        return bin;
    };
    
    auto isValid = [](auto& self, int st, int en, const string& bin)->bool{
        if(st == en) return true;
        int parent = (st+en)/2;
        int lChild = (st+parent-1)/2;
        int rChild = (parent+1+en)/2;
        if(bin[parent] == '0')
            if(bin[lChild] == '1' || bin[rChild] == '1') return false;
        
        return self(self, st, parent-1, bin) && self(self, parent+1, en, bin);
    };
    
    for(int i = 0; i < n; i++)
    {
        string bin = toFullBinTree(numbers[i]);
        if(isValid(isValid, 0, bin.length()-1, bin)) answer[i] = 1;
        else answer[i] = 0;
    }
    
    return answer;
}