#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> arr;
vector<int> pmmd;

int N;
int maxVal = -1000000001;
int minVal = 1000000001;

void dfs(int res, int index) {
	if (index == N) {
		maxVal = max(maxVal, res);
		minVal = min(minVal, res);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (i == 0 && pmmd[i]>0) {
			pmmd[i]--;
			dfs(res + arr[index], index + 1);
			pmmd[i]++;
		}
		else if (i == 1 && pmmd[i] > 0) {
			pmmd[i]--;
			dfs(res - arr[index], index + 1);
			pmmd[i]++;
		}
		else if (i == 2 && pmmd[i] > 0) {
			pmmd[i]--;
			dfs(res * arr[index], index + 1);
			pmmd[i]++;
		}
		else if (i == 3 && pmmd[i] > 0) {
			pmmd[i]--;
			dfs(res / arr[index], index + 1);
			pmmd[i]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	for (int i = 0; i < 4; i++) {
		int num;
		cin >> num;
		pmmd.push_back(num);
	}
	dfs(arr[0], 1);
	cout << maxVal<<"\n";
	cout << minVal;
	return 0;
}