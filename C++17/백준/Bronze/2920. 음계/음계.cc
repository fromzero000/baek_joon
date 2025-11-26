#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int before, next;
    cin>>before;
    if(before == 1){
        next = 2;
        while(before != 8){
            cin>>before;
            if(before != next) {
                cout<< "mixed";
                return 0;
            }
            next++;
        }
        cout<< "ascending";
        return 0;
    }
    if(before == 8){
        next = 7;
        while(before != 1){
            cin>>before;
            if(before != next){
                cout<< "mixed";
                return 0;
            }
            next--;
        }
        cout<< "descending";return 0;
    }
    else cout << "mixed";
  return 0;
}