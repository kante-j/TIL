#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[101][101];
long long dp[101][101];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    for(int i=0; i<N ;i++){
        for(int j=0 ;j<N; j++){
            int num;
            cin >> num;
            arr[i][j] = num;
        }
    }
    dp[0][0] = 1;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0)continue;
            if(j+arr[i][j] < N){
                dp[i][j+arr[i][j]] += dp[i][j];
            }
            if(i+arr[i][j]<N){
                dp[i+arr[i][j]][j] += dp[i][j];
            }
        }
    }


    cout<<dp[N-1][N-1];

    return 0;
}
