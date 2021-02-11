#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int start = 0;
    for(int i=0; i<9; i++){
        int num;
        cin >> num;
        if(num == 0){
            num = 9;
        }
        start = start*10 + num;
    }

    queue<int> q;
    map<int, int> d;
    d[start] = 0;
    q.push(start);
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        string now = to_string(temp);
        int z = now.find('9');
        int x = z/3;
        int y = z%3;
        for(int i=0; i<4; i++){
            int xx = x + dx[i];
            int yy = y + dy[i];
            if(xx>=0 && xx<3 && yy>=0 && yy<3){
                string next = now;
                swap(next[x*3+y], next[xx*3+yy]);
                int num = stoi(next);
                if(d.count(num) == 0){
                    d[num] = d[temp] + 1;
                    q.push(num);
                }
            }
        }
    }
    if(d.count(123456789) == 0){
        cout<<-1;
    }else{
        cout<<d[123456789];
    }
    return 0;
}
