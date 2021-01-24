#include <iostream>
using namespace std;
int main() {
	int E, S, M;
	cin >> E >> S >> M;

	int a, b, c;
	a = b = c = 1;

	for (int i = 1; i < 7981; i++) {
		if (a == E && b == S && c == M) {
			cout << i;
			break;
		}
		else {
			a++; b++; c++;
		}
		if (a == 16)a = 1;
		if (b == 29)b = 1;
		if (c == 20)c = 1;
	}

	return 0;

}
// 나머지 구하는 방법으로도 풀 수 있다던데.. 한 번 찾아봐야지.