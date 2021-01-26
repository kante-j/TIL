#include <iostream>
using namespace std;
int main(){
	int s;
	cin >> s;
	if(s<100){
		cout<<s;
	}else{
		int res = 99;
		for(int i=100; i<=s; i++){
			int temp = i;
			int a = temp%10;
			temp /= 10;
			int b = temp%10;
			temp /= 10;
			int c = temp;
			if(a-b == b-c){
				res ++;
			}
		}
		cout<<res;
	}
	return 0;
}