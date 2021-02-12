#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[201][201][201];
bool visit[201][201][201];
int A,B,C;

void bfs(){
    queue<tuple<int,int,int>> q;
    q.push({0,0,C});
    while(!q.empty()){
        tuple<int,int,int> front = q.front();
        q.pop();
        int x = get<0>(front);
        int y = get<1>(front);
        int z = get<2>(front);
        //A->B
        if(y+x >B && visit[x+y-B][B][z] ==false){
            visit[x+y-B][B][z] = true;
            q.push({x+y-B,B,z});
        }else if(visit[0][x+y][z] == false && x+y<=B){
            visit[0][x+y][z] = true;
            q.push({0,x+y,z});
        }
        //A->C
        if(z+x >C && visit[x+z-C][y][C] ==false){
            visit[x+z-C][y][C] = true;
            q.push({x+z-C,y,C});
        }else if(visit[0][y][x+z] == false && x+z <=C){
            visit[0][y][x+z] = true;
            q.push({0,y,x+z});
        }
        //B->A
        if(x+y>A && visit[A][x+y-A][z] == false){
            visit[A][x+y-A][z] = true;
            q.push({A,x+y-A,z});
        }else if(visit[x+y][0][z] == false && x+y<=A){
            visit[x+y][0][z] =true;
            q.push({x+y,0,z});
        }
        //B->C
        if(z+y >C && visit[x][y+z-C][C] ==false){
            visit[x][y+z-C][C] = true;
            q.push({x,y+z-C,C});
        }else if(visit[x][0][y+z] == false && y+z <= C){
            visit[x][0][y+z]= true;
            q.push({x,0,y+z});
        }
        //C->A
        if(x+z>A && visit[A][y][x+z-A] == false){
            visit[A][y][x+z-A] = true;
            q.push({A,y,z+x-A});
        }else if(visit[x+z][y][0] == false && x+z<=A){
            visit[x+z][y][0]=true;
            q.push({x+z,y,0});
        }
        //C->B
        if(y+z >B && visit[x][B][z+y-B] ==false){
            visit[x][B][z+y-B]  = true;
            q.push({x,B,z+y-B});
        }else if(visit[x][y+z][0] == false && y+z <= B){
            visit[x][y+z][0]= true;
            q.push({x,y+z,0});
        }

    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> A>>B>>C;
    visit[0][0][C] = true;

    bfs();
    bool res[201] = {false,};
    for(int i=0; i<201; i++){
        for(int j=0; j<201; j++){
            for(int k=0; k<201; k++){
                if(i == 0 && visit[i][j][k]){
                    res[k] = true;
                }
            }
        }
    }
    vector<int> arr;
    for(int i=0; i<201; i++){
        if(res[i]){
            arr.push_back(i);
        }
    }
    sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }



    return 0;
}
