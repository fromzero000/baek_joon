#include <iostream>
using namespace std;

int arr[1000005];
int temp[1000005];
int n;
void merge(int st, int en){
    int mid = (st+en)/2;int i1 = st, i2 = mid;
    for(int i = st; i < en; i++){
        if(i1>=mid) temp[i] = arr[i2++];
        else if(i2>=en) temp[i] = arr[i1++];
        else if(arr[i1]<=arr[i2]) temp[i] = arr[i1++];
        else temp[i] = arr[i2++];
    }
    for(int i = st; i < en; i++) arr[i] = temp[i];
}
void merge_sort(int st, int en){
    if(st+1==en) return;
    int mid = (st+en)/2;
    merge_sort(st, mid);
    merge_sort(mid, en);
    merge(st,en);
}
int main() {
    cin>>n;
    for(int i = 0; i < n; i++) cin>>arr[i];
    merge_sort(0,n);
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<'\n';

    return 0;
}
