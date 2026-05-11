#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k){
    vector<int> answer(id_list.size(), 0);
    unordered_map<string, int> id_idx;
    unordered_map<string, unordered_set<string>> report_map;

    for(int i = 0; i < id_list.size(); ++i)
    {
        id_idx[id_list[i]] = i;
    }

    for(const string& r : report)
    {
        stringstream ss(r);
        string reporter, reported;
        ss >> reporter >> reported;
        report_map[reported].insert(reporter);
    }

    for(const auto& pair : report_map)
    {
        if(pair.second.size() >= k)
        {
            for(const string& reporter : pair.second)
            {
                answer[id_idx[reporter]]++;
            }
        }
    }

    return answer;
}