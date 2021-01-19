#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
int map[101][101] = { 0, };

long long sumsq(int x1, int y1, int x2, int y2) {
	long long res = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
			res += map[i][j];
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	int N, M;
	cin >> N >> M;
	long long result = 0;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.size(); j++) {
			map[i][j] = s[j]-'0';
		}
	}
	// |=
	for (int i = 0; i < M-1; i++) {
		for (int j = 0; j < N-1; j++) {
			long long temp1 = sumsq(0, 0, N-1, i);
			long long temp2 = sumsq(0, i+1, j, M - 1);
			long long temp3 = sumsq(j + 1, i+1, N - 1, M - 1);
			result = max(result, temp1 * temp2 * temp3);

		}
	}

	// ㅠ
	for (int i = 0; i < N -1; i++) {
		for (int j = 0; j <M-1; j++) {
			long long temp1 = sumsq(0, 0, i, M - 1);
			long long temp2 = sumsq(i + 1, 0, N-1, j);
			long long temp3 = sumsq(i+1, j+1, N - 1, M - 1);
			result = max(result, temp1 * temp2 * temp3);

		}
	}
	// ㅛ
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M-1; j++) {
			long long temp1 = sumsq(i, 0, N-1, M - 1);
			long long temp2 = sumsq(0, 0, i-1, j);
			long long temp3 = sumsq(0, j+1, i-1, M - 1);
			result = max(result, temp1 * temp2 * temp3);

		}
	}
	// =|
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N-1; j++) {
			long long temp1 = sumsq(0, i, N-1, M - 1);
			long long temp2 = sumsq(0, 0, j, i - 1);
			long long temp3 = sumsq(j + 1, 0, N - 1, i - 1);
			result = max(result, temp1 * temp2 * temp3);

		}
	}
	// |||
	for (int i = 0; i < M - 2; i++) {
		for (int j = i + 1; j < M; j++) {
			long long temp1 = sumsq(0, 0, N-1, i);
			long long temp2 = sumsq(0, i+1, N-1, j);
			long long temp3 = sumsq(0, j+1, N - 1, M - 1);
			result = max(result, temp1 * temp2 * temp3);
		}
	}
	// 三
	for (int i = 0; i < N-2; i++) {
		for (int j = i+1; j < N; j++) {
			long long temp1 = sumsq(0, 0, i, M - 1);
			long long temp2 = sumsq(i + 1, 0, j, M - 1);
			long long temp3 = sumsq(j + 1, 0, N - 1, M - 1);
			result = max(result, temp1 * temp2 * temp3);

		}
	}

	cout << result;


	return 0;
}