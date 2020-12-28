
#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    int T;
    cin >> T;
    while(T--){
        int M;
        cin >> M;
        vector<int> arr;
        vector<int> result;
        
        for(int i=1; i<=M; i++){
            int num;
            cin >>num;
            priority_queue<int> pq;
            arr.push_back(num);
            if(i % 2 !=0){
                for(int j = 0; j<arr.size(); j++){
                    pq.push(arr[j]);
                }
                int temp = pq.size()/2;
                for(int k=0; k<temp; k++){
                    pq.pop();
                }
                result.push_back(pq.top());
//                cout<<pq.top()<<" ";
            }
        }
        cout<<arr.size()/2+1<<endl;
        for(int i=0; i<result.size(); i++){
            cout<<result[i] <<" ";
        }
        cout<<endl;
        
    }
}
