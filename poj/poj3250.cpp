#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int stk[N], tt;
long long a[N], ans[N];

int main() {
    int n;
    cin >> n;
    long long res = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        while (tt && a[stk[tt]] <= a[i])
            tt --;
        if (tt)
            ans[i] = 1 + ans[stk[tt]];
            res += ans[i];

        stk[++ tt] = i;
    }
    cout << res;

    return 0;

}