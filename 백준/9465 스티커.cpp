#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[2][100001] = { 0, };
int dp[2][100001] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		for (int row = 0; row < 2; row++) {
			for (int i = 0; i < n; i++) {
				int num;
				cin >> num;
				arr[row][i] = num;
			}
		}
		dp[0][0] = arr[0][0];
		dp[1][0] = arr[1][0];

		for (int i = 1; i < n; i++) {
			dp[0][i] = arr[0][i] + max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = arr[1][i] + max(dp[0][i - 1], dp[0][i - 2]);
		}
		int res = max(dp[0][n - 1], dp[1][n - 1]);
		cout << res << "\n";
	}
	return 0;

}