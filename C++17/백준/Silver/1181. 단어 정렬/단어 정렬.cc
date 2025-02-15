#include<bits/stdc++.h>
using namespace std;

void qsort(string w[], int s, int e){
    string pivot = w[s];
    int left = s;
    int right = e;
    while(left < right){
        while(right>left&&(pivot.length()<w[right].length()
        ||(pivot.length()==w[right].length()&&pivot<=w[right]))) right--;
        if(left>right) break;
        while(right>left&&(pivot.length()>w[left].length()
        ||(pivot.length()==w[left].length()&&pivot>=w[left]))) left++;
        if(left>right) break;
        swap(w[left],w[right]);
    }
    swap(w[s],w[left]);
    if(s<left) qsort(w,s,left-1);
    if(e>right) qsort(w,left+1,e);
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;string privious;
    cin>>N;
    string words[N];
    for(int i = 0; i < N; i++)
        cin>>words[i];
    qsort(words,0,N-1);
    for(string str : words){
        if(str!=privious)
            cout<<str<<'\n';
        privious = str;
    }
        
}