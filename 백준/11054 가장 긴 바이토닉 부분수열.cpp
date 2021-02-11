#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dp[1001];
int dm[1001];
int arr[1001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        arr[i] = num;
    }
    for(int i=0; i<N; i++){
        dp[i] = 1;
        for(int j=0; j<i; j++){
            if(arr[i]>arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i=N-1; i>=0; i--){
        dm[i] = 1;
        for(int j=N-1; j>i; j--){
            if(arr[i] > arr[j]){
                dm[i] = max(dm[i], dm[j]+1);
            }
        }
    }

    int res = 0;

    for(int i=0; i<N; i++){
        res = max(res, dp[i]+dm[i]-1);

    }

    cout<<res;

    return 0;
}
