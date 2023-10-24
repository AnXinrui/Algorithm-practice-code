#include <iostream>

using namespace std;

const int N = 3e6 + 10;

int a[N];
int stk[N], tt;
int f[N];

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (int i = n; i > 0; i --) {
        while (tt && a[stk[tt]] <= a[i])
            tt --;
        f[i] = stk[tt];
        stk[++ tt] = i;
    }
    for (int i = 1; i <= n; i ++)
        cout << f[i] << ' ';

    return 0;
}