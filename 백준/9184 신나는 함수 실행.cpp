#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int arr[21][21][21];
using namespace std;
void print(int a, int b, int c, int res) {
	cout << "w(" << a << ", " << b << ", " << c << ") = " << res << "\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i <21; i++) {
		arr[i][0][0] = 1;
		arr[0][0][i] = 1;
		arr[0][i][0] = 1;
		for (int j = 0; j < 21; j++) {
			arr[i][j][0] = 1;
			arr[i][0][j] = 1;
			arr[0][i][j] = 1;
		}
	}
	for (int i = 1; i < 21; i++) {
		for (int j = 1; j < 21; j++) {
			for (int k = 1; k < 21; k++) {
				if (i < j && j < k) {
					arr[i][j][k] = arr[i][j][k - 1] + arr[i][j - 1][k - 1] - arr[i][j - 1][k];
				}
				else {
					arr[i][j][k] = arr[i - 1][j][k] + arr[i - 1][j - 1][k] + arr[i - 1][j][k - 1] - arr[i - 1][j - 1][k - 1];
				}
			}
		}
	}
	while (true) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) {
			break;
		}
		if (a <= 0 || b <= 0 || c <= 0) {
			print(a, b, c, 1);
		}
		else if (a > 20 || b > 20 || c > 20) {
			print(a, b, c, 1048576);
		}
		else {
			print(a, b, c, arr[a][b][c]);
		}

	}


	return 0;
}