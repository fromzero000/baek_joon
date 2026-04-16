#include <string>
#include <vector>
#include <sstream>
#include <set>
#include <queue>
using namespace std;

int solution(string message, vector<vector<int>> spoiler_ranges){
    stringstream ss(message);
    set<string> secret;
    set<string> not_secret;
    queue<pair<int, int>> q;
    for(const auto& r : spoiler_ranges)
        q.push({r[0], r[1]});
    
    string target;
    int pos = 0;
    auto cur = q.front();q.pop();
    while(ss >> target)
    {
        while(pos < message.length() && message[pos] == ' ') pos++;
        while(cur.second != -1 && cur.second < pos)
        {
            if(!q.empty())
            {
                cur = q.front();q.pop();
            }
            else
                cur = {-1, -1};
        }
        
        if(pos <= cur.second && pos+target.length()-1 >= cur.first)
        {
            secret.insert(target);
        }
        
        else
        {
            not_secret.insert(target);
        }
        pos += target.length();
    }
    int result = secret.size();
    for(const auto& word : secret)
    {
        if(not_secret.find(word) != not_secret.end())
            result--;
    }
    return result;
}