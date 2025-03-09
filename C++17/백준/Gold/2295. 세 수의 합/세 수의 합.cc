#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> vec1;
vector<int> vec2;

bool binarysearch(int k){
    int st = 0, en = vec2.size()-1;
    while(st<=en){
        int mid = (st+en)/2;
        if(vec2[mid] < k) st = mid+1;
        else if(vec2[mid] > k) en = mid-1;
        else return 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i = 0; i < n; i++){
        int k;
        cin>>k;vec1.push_back(k);
    }
    sort(vec1.begin(),vec1.end());

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            vec2.push_back(vec1[i]+vec1[j]);
        }
    }
    sort(vec2.begin(), vec2.end());

    for(int i = 0; i < n*n; i++){
        if(i==0||vec2[i]!=vec2[i-1]) vec2.push_back(vec2[i]);
    }

    vec2.erase(vec2.begin(),vec2.begin()+n*n);

    for(int i = n-1; i > -1; i--){
        for(int j = i; j > -1; j--){
            if(binarysearch(vec1[i]-vec1[j])){
                cout<<vec1[i];
                return 0;
            }
//            if(binary_search(vec2.begin(), vec2.end(),vec1[i]-vec1[j])){
//                cout<<vec1[i];
//                return 0;
//            }
        }
    }
}