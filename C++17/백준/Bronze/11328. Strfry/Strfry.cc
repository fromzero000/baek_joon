#include <iostream>
using namespace std;

bool is_possible(int a[], int b[]){
    for(int i = 0; i < 26; i++){
        if(a[i]!=b[i]) return 0;
    }
    return 1;
}
auto main() -> int{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin>>n;
    
    for(int i = 0; i < n; i++){
        string str1;
        string str2;
        cin>>str1;
        cin>>str2;
        int ch1[26]{0};
        int ch2[26]{0};
        for(int j = 0; j < str1.length(); j++){
            ch1[str1[j]-'a']++;
        }
        for(int j = 0; j < str1.length(); j++){
            ch2[str2[j]-'a']++;
        }
        if(is_possible(ch1,ch2)) cout<<"Possible\n";
        else cout<<"Impossible\n";
    }
}