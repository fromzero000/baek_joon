#include <string>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    vector<vector<pair<int, int>>> parent(51, vector<pair<int,int>>(51));
    vector<vector<string>> value(51, vector<string>(51));
    for(int i = 1; i <= 50; i++)
        for(int j = 1; j <= 50; j++)
            parent[i][j] = {i, j};
    auto findRoot = [&](auto& self, int r, int c)->pair<int, int>{
        if(parent[r][c] == make_pair(r, c)) return {r, c};
        
        auto [pr, pc] = parent[r][c];
        parent[r][c] = self(self, pr, pc);
        return parent[r][c];
    };
    
    auto mergeCell = [&](pair<int, int> p1, pair<int, int> p2)->void{
        auto root1 = findRoot(findRoot, p1.first, p1.second);
        auto root2 = findRoot(findRoot, p2.first, p2.second);
        if(root1 == root2) return;
        
        string val = "";
        if(value[root1.first][root1.second] != "") val = value[root1.first][root1.second];
        else if(value[root2.first][root2.second] != "") val = value[root2.first][root2.second];
        parent[root2.first][root2.second] = {root1.first, root1.second};
        value[root1.first][root1.second] = val;
        value[root2.first][root2.second] = ""; 
    };

    auto unmergeCell = [&](int r, int c)->void{
        auto root = findRoot(findRoot, r, c);
        string val = value[root.first][root.second];
        vector<pair<int, int>> unmerge;
        for(int i = 1; i <= 50; i++)
            for(int j = 1; j <= 50; j++)
                if(findRoot(findRoot, i, j) == root)
                    unmerge.push_back({i, j});
        
        for(auto& p : unmerge)
        {
            parent[p.first][p.second] = {p.first, p.second};
            value[p.first][p.second] = "";
        }
        value[r][c] = val;
    };
    
    auto updateCell = [&](int r, int c, const string& val)->void{
        auto root = findRoot(findRoot, r, c);
        value[root.first][root.second] = val;
    };
    
    auto updateAll = [&](const string& val1, const string& val2)->void{
        for(int i = 1; i <= 50; i++)
        {
            for(int j = 1; j <= 50; j++)
            {
                auto root = findRoot(findRoot, i, j);
                if(value[root.first][root.second] == val1)
                    value[root.first][root.second] = val2;
            }
        }
    };
    
    auto print = [&](int r, int c)->void{
        auto target = findRoot(findRoot, r, c);
        answer.push_back(value[target.first][target.second]!=""?value[target.first][target.second]:"EMPTY");
    };
    
    for(const string& cmd : commands)
    {
        stringstream ss(cmd);
        string type;
        ss >> type;
        
        if(type == "UPDATE")
        {
            string token1, token2, token3;
            ss >> token1 >> token2;
            if(ss >> token3)
                updateCell(stoi(token1), stoi(token2), token3);
            else
                updateAll(token1, token2);
        }
        else if(type == "MERGE")
        {
            int r1, c1, r2, c2;
            ss >> r1 >> c1 >> r2 >> c2;
            mergeCell({r1, c1}, {r2, c2});
        }
        else if(type == "UNMERGE")
        {
            int r, c;
            ss >> r >> c;
            unmergeCell(r, c);
        }
        else if(type == "PRINT")
        {
            int r, c;
            ss >> r >> c;
            print(r, c);
        }
    }
    return answer;
}