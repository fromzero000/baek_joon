#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m,l;
vector<int> vec1;

bool find_num(int k){
    int st = 0, en =  n-1;
    while(st<=en){
        int mid = (st+en)/2;
        if(vec1[mid] > k) en = mid-1;
        else if(vec1[mid] < k) st = mid+1;
        else return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>l;vec1.push_back(l);
    }
    sort(vec1.begin(), vec1.begin()+n);
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>l;
        cout<<find_num(l)<<'\n';
    }
}