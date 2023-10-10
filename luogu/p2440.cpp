#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];

int main() {
    int n, k;
    cin >> n >> k;
    int r = 0, l = 0;
    for (int i = 1; i <= n; i ++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
    while (l < r) {
        // 令当前长度为 mid
        int mid = (l + r + 1) >> 1;
        // 长度mid时可以分为多少根
        int cnt = 0;
        for (int i = 1; i <= n; i ++) {
            cnt += a[i] / mid;
        }
        if (cnt < k)    r = mid - 1;
        else    l = mid;
    }
    cout << l;

    return 0;
}