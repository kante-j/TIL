#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;

bool colArray[16];
bool leftDigArray[40];
bool rightDigArray[16];
bool col[16][16];
int N;

bool check(int row, int col){
    if(colArray[col]){
        return false;
    }
    if(leftDigArray[row-col+N]){
        return false;
    }
    if(rightDigArray[row+col]){
        return false;
    }
    return true;
}

int dfs(int row){
    if(row == N){
        return 1;
    }
    int cnt = 0;
    for(int col=0; col<N; col++){
        if(check(row,col)){
            colArray[col] = true;
            leftDigArray[row-col+N] = true;
            rightDigArray[row+col] = true;
            cnt += dfs(row+1);
            colArray[col] = false;
            leftDigArray[row-col+N] = false;
            rightDigArray[row+col] = false;
        }
    }
    return cnt;

}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    cout<<dfs(0);

    return 0;
}
