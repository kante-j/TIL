#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
bool arr[246913] = { 0, };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	arr[0] = arr[1] = true;
	for (int i = 2; i <= 123456; i++) {
		if (arr[i] == false) {
			for (int j = i + i; j < 246913; j += i) {
				arr[j] = true;
			}
		}
	}
	while (true) {
		int n;
		cin >> n;
		if (n == 0)break;
		int res = 0;
		for (int i = n+1; i <= n * 2; i++) {
			if (arr[i] == 0)res++;
		}
		cout << res<<"\n";
	}
	return 0;
}