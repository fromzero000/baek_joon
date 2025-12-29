#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int N, in, sum = 0;
    
    cin >> N;
    vector<int> numbers;
    for(int i = 0; i < N; i++){
        cin >> in;
        numbers.push_back(in);
        sum+=in;
    }
    sort(numbers.begin(), numbers.end());
    sum = round((double)sum/N);
    cout<<sum<<'\n';
    cout<<numbers[N/2]<<'\n';
    int frequencies[8001];
    fill(frequencies, frequencies+8001, 0);
    for(int i = 0; i < N; i++){
        if(numbers[i]>=0) frequencies[numbers[i]]++;
        else frequencies[-numbers[i]+4000]++;
    }
    int highest_frequency = 0;
    for(int i = 0; i < 8001; i++){
        if(frequencies[i] > highest_frequency) highest_frequency = frequencies[i];
    }
    vector<int> highest_frequencies;
    for(int i = 0; i < 8001; i++){
        if(frequencies[i] == highest_frequency) {
            if(i<=4000) highest_frequencies.push_back(i);
            else highest_frequencies.push_back(-i+4000);
        }
    }
    sort(highest_frequencies.begin(), highest_frequencies.end());
    cout<<(highest_frequencies.size()==1?highest_frequencies[0]:highest_frequencies[1])<<'\n';
    cout<<numbers[N-1] - numbers[0]<<'\n';
}