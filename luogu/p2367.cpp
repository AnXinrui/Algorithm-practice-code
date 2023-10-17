// 直接版
#include <iostream>

using namespace std;
const int N = 5e6 + 10;
int a[N];
/*
 a1 = p1
 a2 = p2 - p1
 a3 = p3 - p2

*/
int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    // 差分矩阵
    for (int i = n; i > 0; i --)
        a[i] -= a[i-1];
    while (p --) {
        int x, y, z;
        cin >> x >> y >> z;
        a[x] += z;
        a[y+1] -= z;
    }
    int ans = 100;
    for (int i = 1; i <= n; i ++) {
        a[i] += a[i-1];
        ans = min(ans, a[i]);
    }

    cout << ans;

    return 0;
}


//**************************************************************

// 优雅版
#include <iostream>

using namespace std;
const int N = 5e6 + 10;
int a[N],  b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r+1] -= c;
}

int main() {
    int n, p;
    cin >> n >> p;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        insert(i, i, a[i]);
    }
    while (p --) {
        int x, y, z;
        cin >> x >> y >> z;
        insert(x, y, z);
    }
    int ans = 100;
    for (int i = 1; i <= n; i ++) {
        a[i] = a[i-1] + b[i];
        ans = min(ans, a[i]);
    }

    cout << ans;

    return 0;
}