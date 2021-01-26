#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int K, N;
	cin >> K >> N;
	long long left = 1;
	long long right = 0;
	int m = 0;
	for (int i = 0; i < K; i++) {
		int num;
		cin >> num;
		m = max(m, num);
		arr.push_back(num);
	}
	right = m;
	long long mid;
	while (left <= right) {
		mid = (left + right) / 2;
		int res = 0;
		for (int i = 0; i < K; i++) {
			res += arr[i] / mid;
		}
		if (res >= N) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << right;

	return 0;
}