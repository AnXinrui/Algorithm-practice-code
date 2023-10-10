#include <iostream>

using namespace std;

const int N = 5e4 + 5;

int a[N];

int main() {
    int d, n, m;
    cin >> d >> n >> m;
    for (int i = 0; i < n; i ++)
        cin >> a[i];
    // 二分 跳跃的最短距离
    int l = 0, r = d;
    while(l < r) {
        int mid = (l + r + 1) >> 1;
        // 移走石头数量
        int cnt = 0;
        // 前一块石头 与 起点的距离
        int p = 0;
        for (int i = 0; i < n; i ++) {
            if (d - a[i] < mid) {
                cnt += n - i;
                break;
            }
            if (a[i] - p < mid) {
                ++ cnt;
            }
            else    p = a[i];
        }

        if (cnt > m)      r = mid - 1;
        else    l = mid;
    }
    cout << l;

    return 0;
}

