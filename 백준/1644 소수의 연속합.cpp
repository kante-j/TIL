#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool arr[4000000];
vector<int> sosu;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<=N; i++){
        arr[i] = true;
    }
    arr[0]=arr[1] = false;
    for(int i=2; i<=N; i++){
        if(!arr[i])continue;
        for(int j=i+i; j<=N; j+=i){
            arr[j] = false;
        }
    }
    for(int i=2; i<=N; i++){
        if(arr[i]){
            sosu.push_back(i);
        }
    }

    int x,y,cnt =0;
    x=y=0;
    if(N == 1){
        cout << 0;
        return 0;
    }
    int sum = sosu[0];
    while(true){
        if(sum == N){
            cnt++;
            y++;
            if(y>=sosu.size())break;
            sum = sum + sosu[y];
        }else if(sum < N){
            y++;
            if(y>=sosu.size())break;
            sum = sum + sosu[y];
        }else if(sum>N){
            sum = sum - sosu[x];
            x++;
        }
    }
    cout<<cnt;

    return 0;
}
