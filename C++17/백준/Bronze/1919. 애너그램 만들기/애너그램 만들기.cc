#include <iostream>
#include <algorithm>

using namespace std;
int chars1[26];
int chars2[26];
int main(){
    string s1,s2;
    int sum = 0;
    cin>>s1>>s2;
    
    for(char c1 : s1){
        chars1[c1 - 'a']++;
    }
    for(char c2 : s2){
        chars2[c2 - 'a']++;
    }
    for(int i = 0; i < 26; i++){
        int n = max(chars1[i],chars2[i]);
        sum+=n - min(chars1[i],chars2[i]);
    }
    cout<<sum;
}