#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int arr[101][101];
bool visit[101][101];
int N;
int islandNum = 1;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };


void resetVisit() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
}

void change(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[x][y] = true;
	arr[x][y] = islandNum;
	while (!q.empty()) {
		pair<int, int> front = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int xx = front.first + dx[i];
			int yy = front.second + dy[i];
			if (xx >= 0 && yy >= 0 && xx < N && yy < N && visit[xx][yy] == false && arr[xx][yy] !=0) {
				visit[xx][yy] = true;
				arr[xx][yy] = islandNum;
				q.push({ xx,yy });
			}
		}
	}
	islandNum++;
}

int bfs(int island) {
	queue<pair<int, int>> q;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == island) {
				q.push({ i,j });
				visit[i][j] = true;
			}
		}
	}

	int res = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			pair<int, int> front = q.front();
			q.pop();
			for (int i = 0; i < 4; i++) {
				int xx = front.first + dx[i];
				int yy = front.second + dy[i];
				if (xx >= 0 && yy >= 0 && xx < N && yy < N) {
					if (arr[xx][yy] != 0 && arr[xx][yy] != island) return res;
					else if (arr[xx][yy] == 0 && visit[xx][yy] == false) {
						visit[xx][yy] = true;
						q.push({ xx,yy });
					}
				}
			}
		}
		res++;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	resetVisit();
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			arr[i][j] = num;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] != 0 && visit[i][j] == false) {
				change(i, j);
			}
		}
	}

	int res = 99999999;
	for (int i = 1; i < islandNum; i++) {
		resetVisit();
		res = min(res, bfs(i));
	}
	cout << res;
	return 0;
}