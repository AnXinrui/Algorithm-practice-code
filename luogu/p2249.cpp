#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    while (m --) {
        int k;
        cin >> k;
        // int l = 1, r = n;
        // while (l < r) {
        //     int m = (l + r) >> 1;
        //     if (a[m] < k)   l = m + 1;
        //     else    r = m;
        // }
        int l = lower_bound(a + 1, a + n, k) - a;
        if (a[l] == k)  cout << l << ' ';
        else cout << -1 << ' ';
    }

    return 0;
}
