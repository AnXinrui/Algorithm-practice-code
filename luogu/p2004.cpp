#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], s[N][N];
int ans = -0x3f3f3f3f;

int main() {
    int n, m, c;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            cin >> a[i][j];
            s[i][j] = s[i-1][j] + s[i][j-1] + a[i][j] - s[i-1][j-1];
        }
    int x, y;
    for (int i = 1; i <= n - c + 1; i ++)
        for (int j = 1; j <= m - c + 1; j ++)
        {
            int x2 = i + c - 1, y2 = j + c - 1;
            int res = s[x2][y2]-s[x2][j-1]-s[i-1][y2]+s[i-1][j-1];
            if (res > ans)  x = i, y = j, ans = res;
        }
    cout << x << ' ' << y;

    return 0;

}