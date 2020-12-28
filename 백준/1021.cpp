#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    
    int N, M;
    cin>>N>>M;
    vector<int> q;
    for(int i =1 ;i<=N; i++){
        q.push_back(i);
    }
    int index = 0;
    int count = 0;
    for(int i=0; i<M; i++){
        int num;
        cin >> num;
        int idx=0;
        for(int j = 0; j<N; j++){
            if(q[j] == num){
                idx = j;
                break;
            }
        }
        
        int minimum = 0;
        int temp = abs(index - idx);
        if(q.size()-temp > temp){
            minimum = temp;
        }else{
            minimum = q.size()-temp;
        }
        
        
        for(int a = idx; a<q.size()-1; a++){
            q[a] = q[a+1];
        }
        q.pop_back();
        index = idx;
        count+=minimum;
        
    }
    cout<<count;
    return 0;
}
