#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <cmath>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    long long res = 0;
    //221 이면 1의자리수는 221개, 10의자리수는 221-10 해서 211개, 100의자리수는 221-100 해서 121개 나옴
    //여기서 221-10 하면 10이 카운트 안되니까 1개씩 ++;
    for(int i=1; i<= N ; i *= 10){
        res += (N-i+1);
    }
    cout<<res;
    return 0;
}
