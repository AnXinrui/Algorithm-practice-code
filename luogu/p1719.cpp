#include <iostream>

using namespace std;

const int N = 130;

int a[N][N], s[N][N];

int main() {
    int n;
    cin >> n;
    int ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++) {
            cin >> a[i][j];
            s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1] + a[i][j];
        }
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= n; j ++)
            for (int i1 = i + 1; i1 <= n; i1 ++)
                for (int j1 = j + 1; j1 <= n; j1 ++) {
                    int sq = s[i1][j1] - s[i-1][j1]-s[i1][j-1] + s[i-1][j-1];
                    ans = max(ans, sq);
                }
    cout << ans;

    return 0;
}