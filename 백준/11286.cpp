
#include <iostream>
#include <queue>
#include <functional>
#include <utility>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>> pq;

    int N;
    cin >>N;
    for(int i=0; i<N; i++){
        long long num;
        cin >> num;
        if(num == 0){
            if(pq.empty()){
                cout<<0<<"\n";
                continue;
            }
            cout<<pq.top().second<<"\n";
            pq.pop();
        }else{
            pq.push(make_pair(abs(num), num));
        }
    }
    
    return 0;
}
