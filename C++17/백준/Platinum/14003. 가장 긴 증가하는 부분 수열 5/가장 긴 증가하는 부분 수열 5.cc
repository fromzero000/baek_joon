#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> arr;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    arr.resize(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    vector<int> L;
    vector<int> P(n);
    for(int i = 0; i < n; i++){
        auto it = lower_bound(L.begin(), L.end(), arr[i]);
        
        if(it == L.end()){
            L.push_back(arr[i]);
            P[i] = L.size()-1;
        }else{
            *it = arr[i];
            P[i] = it-L.begin();
        }
    }
    
    int len = L.size();
    vector<int> result;
    int target = len-1;
    for(int i = n-1; i >= 0; i--){
        if(P[i] == target){
            result.push_back(arr[i]);
            target--;
        }
    }
    cout << len << '\n';
    for(auto it = result.rbegin(); it != result.rend(); it++)
        cout << *it << ' ';
}