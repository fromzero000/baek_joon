#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
//MERGE_SORT
int arr[1005];
int tmp[1005];
int n;

void _merge(int st, int en){
    int mid = (st+en)/2;
    int idx1 = st, idx2 = mid;
    for(int i = st; i < en; i++){
        if(idx1>=mid) tmp[i] = arr[idx2++];
        else if(idx2>=en) tmp[i] = arr[idx1++];
        else if(arr[idx1]<=arr[idx2]) tmp[i] = arr[idx1++];
        else tmp[i] = arr[idx2++];
    }
    for(int i = st; i < en; i++) arr[i] = tmp[i];
}

void _sort(int st, int en){
    if(st+1==en) return;
    int mid = (st+en)/2;
    _sort(st,mid);
    _sort(mid,en);
    _merge(st,en);
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    
    _sort(0,n);
    for(int i = 0; i < n; i++) cout<<arr[i]<<'\n';
}