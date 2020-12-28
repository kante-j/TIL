
#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <bits/stdc++.h>
using namespace std;
int main(){
    int K,N;
    cin >> K>>N;
    
    vector<long long> arr;
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    
    for(int i=0; i<K; i++){
        long long num;
        cin>>num;
        arr.push_back(num);
        pq.push(num);
    }
    
    long long result = 0;
    for(int i=0; i<N; i++){
        result = pq.top();
        pq.pop();
        for (long long item : arr) {
            long long temp = item * result;
            if(INT_MAX <= temp){
                break;
            }
            pq.push(temp);
            if (result % item == 0) break;
        }
    }
    cout<<result;
    
    return 0;
}
