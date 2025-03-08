#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,l;

vector<int> vec;

int lower_index(int k){
    int st = 0, en = n;

    while(st<en){
        int mid = (st+en)/2;
        if(vec[mid] >= k) en = mid;
        else st = mid+1;
    }
    return st;
}

int upper_index(int k){
    int st = 0, en = n;

    while(st<en){
        int mid = (st+en)/2;
        if(vec[mid] > k) en = mid;
        else st = mid+1;
    }
    return st;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>l;
        vec.push_back(l);
    }
    sort(vec.begin(), vec.end());
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>l;
        cout<<upper_index(l) - lower_index(l)<<' ';
    }
}