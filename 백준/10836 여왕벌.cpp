#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int M, N;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> M >> N;
	vector<int> arr(2*M-1,1);
	for (int i = 0; i < N; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		for (int j = a; j < a + b; j++) {
			arr[j] += 1;
		}
		for (int j = a + b; j < 2 * M - 1; j++) {
			arr[j] += 2;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (j == 0) {
				cout << arr[M - i - 1] << " ";
			}
			else {
				cout << arr[M + j - 1] << " ";
			}
		}
		cout << "\n";
	}

	return 0;
}