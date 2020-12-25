#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <string>
#include <tuple>
#define INF 987654321
using namespace std;
int N, M, T;

vector<vector<int>> roundPlate(1);
vector<tuple<int,int,int>> command;
bool visit[51][51] = {false,};

void rotate(int index, int dir, int cnt){
    vector<int> temp = roundPlate[index];
    vector<int> result;
    if (dir == 0){
        for(int i=0; i<cnt; i++){
            int b = temp.back();
            temp.insert(temp.begin()+1, b);
            temp.pop_back();
        }
        roundPlate[index] = temp;
    }else{
        for(int i=0; i<cnt; i++){
            int front = temp[1];
            temp.push_back(front);
            temp.erase(temp.begin()+1, temp.begin()+2);
        }
        
        roundPlate[index] = temp;
    }
}

bool dfs(int i, int j){
    if(visit[i][j]) return false;
    visit[i][j] = true;
    int tempNumber = roundPlate[i][j];
    if(tempNumber == 0)return false;
    bool check = false;
    if(j == 1){
        if( tempNumber == roundPlate[i][2] &&  visit[i][j+1] == false){
            dfs(i,2);
            roundPlate[i][1] = 0;
            roundPlate[i][2] = 0;
            check = true;
        }
        if(tempNumber == roundPlate[i][M] &&  visit[i][M] == false){
            dfs(i,M);
            roundPlate[i][1] = 0;
            roundPlate[i][M] = 0;
            check = true;
        }
    }else if(j == M){
        if(tempNumber == roundPlate[i][j-1] &&  visit[i][j-1] == false){
            dfs(i,j-1);
            roundPlate[i][j] = 0;
            roundPlate[i][j-1] = 0;
            check = true;
        }
        if(tempNumber == roundPlate[i][1] &&  visit[i][1] == false){
            dfs(i,1);
            roundPlate[i][j] = 0;
            roundPlate[i][1] = 0;
            check = true;
        }
    }else if(2<= j && j<=M-1){
        if(tempNumber== roundPlate[i][j-1] &&  visit[i][j-1] == false){
            dfs(i,j-1);
            roundPlate[i][j] = 0;
            roundPlate[i][j-1] = 0;
            check = true;
        }
        if(tempNumber == roundPlate[i][j+1] &&  visit[i][j+1] == false){
            dfs(i,j+1);
            roundPlate[i][j] = 0;
            roundPlate[i][j+1] = 0;
            check = true;
        }
    }
    
    if(i==1){
        if(tempNumber == roundPlate[i+1][j] &&  visit[i+1][j] == false){
            dfs(i+1,j);
            roundPlate[i][j] = 0;
            roundPlate[i+1][j] = 0;
            check = true;
        }
    }else if(i == N){
        if(tempNumber == roundPlate[i-1][j] &&  visit[i-1][j] == false){
            dfs(i-1,j);
            roundPlate[i][j] = 0;
            roundPlate[i-1][j] = 0;
            check = true;
        }
    }else{
        if(tempNumber == roundPlate[i+1][j] &&  visit[i+1][j] == false){
            dfs(i+1,j);
            roundPlate[i][j] = 0;
            roundPlate[i+1][j] = 0;
            check = true;
        }
        if(tempNumber == roundPlate[i-1][j] &&  visit[i-1][j] == false){
            dfs(i-1,j);
            roundPlate[i][j] = 0;
            roundPlate[i-1][j] = 0;
            check = true;
        }
    }
    
    return check;
}
void changeNumber(){
    double avg = 0;
    double sum = 0 , cnt = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            sum +=roundPlate[i][j];
            if(roundPlate[i][j] != 0){
                cnt++;
            }
        }
    }
    avg = sum/cnt;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j++){
            if(roundPlate[i][j] != 0 ){
                if(roundPlate[i][j] > avg){
                    roundPlate[i][j] = roundPlate[i][j]-1;
                }else if(roundPlate[i][j] < avg){
                    roundPlate[i][j] = roundPlate[i][j] + 1;
                }
            }
            
        }
    }
}

void resetVisit(){
    for(int i=0; i<=N; i++){
        for(int j=0; j<=M; j++){
            visit[i][j] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M >> T;
    for(int i=0; i<N; i++){
        vector<int> temp(1);
        for(int j=0; j<M; j++){
            int num;
            cin >> num;
            temp.push_back(num);
        }
        roundPlate.push_back(temp);
    }
    
    for(int i=0; i<T; i++){
        int x,d,k;
        cin >> x>>d>>k;
        int tempx = x;
        for(int j=x; j<=N; j+=tempx){
            rotate(j,d,k);
        }
        bool check = false;
        for(int x=1; x<=N; x++){
            for(int y=1; y<=M; y++){
                bool c = dfs(x,y);
                if(check == false){
                    check = c;
                }
            }
        }
        if(check == false){
            changeNumber();
        }
        resetVisit();
    }
    
    int sum = 0;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=M; j ++){
            sum += roundPlate[i][j];
        }
    }
    
    cout << sum;
    
    
    
    return 0;
}
