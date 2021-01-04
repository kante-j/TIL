#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int M, N;
int arr[1001][1001];
bool visit[1001][1001] = {false, };
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
int check(){
    int res = -1;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            if(arr[i][j] == 0){
                return -1;
            }
            res = max(res, arr[i][j]);
        }
    }
    return res-1;
}

void oneDay(queue<pair<int, int>> q){
    while(!q.empty()){
        pair<int, int> front = q.front();
        q.pop();

        for(int i=0; i<4; i++){
            int xx = front.first + dx[i];
            int yy = front.second + dy[i];
            if(xx>=0 && yy>=0 && xx<M && yy<N && visit[xx][yy] == false && arr[xx][yy]==0 && arr[xx][yy] != -1){
                visit[xx][yy] = true;
                arr[xx][yy] = arr[front.first][front.second] + 1;
                q.push({xx,yy});
            }
        }
    }
}
int main(){
    cin >> N>> M;
    queue<pair<int,int>> q;
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            int num;
            cin >> num;
            if(num == 1){
                visit[i][j] = true;
                q.push({i,j});
            }
            arr[i][j] = num;
        }
    }
    oneDay(q);
    cout << check();
    return 0;
}
