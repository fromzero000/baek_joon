#include <bits/stdc++.h>
using namespace std;

int pow(int n, int r){
    if(r==0) return 1;
    else return n*pow(n,r-1);
}

int Z(int N,int r,int c){
    if(N==1){
        int answer = 0;
        if(r==1)
            answer+=2;
        if(c==1)
            answer++;
        return answer;
    }
    else{
        if(c>=pow(2,N-1)){
            if(r>=pow(2,N-1))
                return Z(N-1,r-pow(2,N-1),c-pow(2,N-1)) + 3*pow(4,N-1);
            else return Z(N-1,r,c-pow(2,N-1)) + 1*pow(4,N-1);
        }
        else{
            if(r>=pow(2,N-1))
                return Z(N-1,r-pow(2,N-1),c) + 2*pow(4,N-1);
            else return Z(N-1,r,c);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,r,c;
    cin>>N>>r>>c;
    cout<<Z(N,r,c);
}