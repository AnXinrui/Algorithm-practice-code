#include <iostream>

using namespace std;
int st[101];
int a[108], idx = 0;

// 我写的不太优雅
int main() {
    int n, m;
    cin >> n >> m;
    int i = 1, cnt = 0;
    while (idx < n) {
        if (st[i]) {
            i ++ ;
            if (i == n + 1)
                i = 1;
            continue;
        }
        ++ cnt;
        if (cnt == m) {
            cnt = 0;
            st[i] = 1;
            a[++ idx] = i;
        }
        i ++ ;
        if (i == n + 1)
            i = 1;


    }
    for (int i = 1; i <= n; i ++)
        cout << a[i] << ' ';
    return 0;
}