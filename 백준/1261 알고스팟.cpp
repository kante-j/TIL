#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <queue>
using namespace std;

int N, M;
int map[101][101];
int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
bool visit[101][101] = {false,};
int cost[101][101]={0,};

void setCostArr(){
    for(int i=0; i<M; i++){
        for(int j=0; j<N; j++){
            cost[i][j] = 9999;
        }
    }
    cost[0][0] = 0;
}
void bfs(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,0});
    while(!pq.empty()){
        int x = pq.top().first;
        int y = pq.top().second;
        pq.pop();
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 && yy >=0 && xx<M && yy < N && visit[xx][yy] == false && cost[x][y] + map[xx][yy] < cost[xx][yy]){
                cost[xx][yy] = cost[x][y] + map[xx][yy];
                pq.push({xx,yy});
            }
        }
    }

}

int main(){
    cin>>N>>M;
    for(int i=0; i<M; i++){
        string num;
        cin >> num;
        for(int j=0; j<num.length(); j++){
            map[i][j] = num[j] - '0';
        }
    }
    setCostArr();
    bfs();
    cout<<cost[M-1][N-1];

}
