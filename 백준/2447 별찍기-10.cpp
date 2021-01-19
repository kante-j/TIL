#include <iostream>

using namespace std;
char map[7000][7000];
void divcon(int n, int x, int y){
    if(n==1){
        map[x][y]='*';
        return;
    }
    int nextN = n/3;
    for(int i=0; i<3; i++){
        for(int j=0 ;j<3; j++){
            if(i==1 && j==1){
                continue;
            }else{
                divcon(nextN,x+nextN*i,y+nextN*j);
            }
        }
    }
}
int main(){
    int N;
    cin >> N;
    divcon(N,0,0);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if(map[i][j]){
                cout << map[i][j];
            }else{
                cout << ' ';
            }
        }
        cout << endl;
    }
}