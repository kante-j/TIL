#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
bool map[3100][3100] = { 0, };

void recur(int x, int y, int depth) {
	if (depth == 3) {
		map[x][y] = 1;
		map[x + 1][y - 1] = 1;
		map[x + 1][y + 1] = 1;
		map[x + 2][y - 2] = 1;
		map[x + 2][y - 1] = 1;
		map[x + 2][y] = 1;
		map[x + 2][y + 1] = 1;
		map[x + 2][y + 2] = 1;
		return;
	}
	recur(x, y, depth / 2);
	recur(x + depth / 2, y - depth / 2, depth / 2);
	recur(x + depth / 2, y + depth / 2, depth / 2);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N;
	cin >> N;
	recur(0, N - 1, N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			cout << (map[i][j] ? "*":" ");
		}
		cout << "\n";
	}


	return 0;
}