#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 10;
const int mod = 1e9 + 7;

typedef long long LL;

char s[N];
/*
f[i][0] 表示 s[i] 处不是炸弹， s[i+1]处也不是炸弹
f[i][1] 表示 s[i] 处不是炸弹， s[i+1]处是炸弹
f[i][2] 表示 s[i] 处是炸弹， s[i+1]处不是炸弹
f[i][3] 表示 s[i] 处是炸弹， s[i+1]处也是炸弹
*/
LL f[N][4];

int main() {
    cin >> s + 1;
    int n = strlen(s + 1);
    // 初始化
    f[0][0] = 1, f[0][1] = 1;

    for (int i = 1; i < n; i ++) {
        if (s[i] == '0')
            f[i][0] = f[i-1][0];
        else if (s[i] == '1')
        {
            f[i][0] = f[i-1][2];
            f[i][1] = f[i-1][0];
        }
        else if (s[i] == '2')
            f[i][1] = f[i-1][2];
        else if (s[i] == '*')
        {
            f[i][2] = (f[i-1][1] + f[i-1][3]) % mod;
            f[i][3] = (f[i-1][1] + f[i-1][3]) % mod;
        }
        else
        {
            f[i][0] = (f[i-1][0] + f[i-1][2]) % mod ;
            f[i][1] = (f[i-1][0] + f[i-1][2]) % mod ;
            f[i][2] = (f[i-1][3] + f[i-1][1]) % mod ;
            f[i][3] = (f[i-1][1] + f[i-1][3]) % mod ;
        }
    }
    int ans;
    if (s[n] == '0')
        ans = f[n-1][0];
    else if (s[n] == '1')
        ans = f[n-1][2];
    else if (s[n] == '2')
        ans = 0;
    else if (s[n] == '*')
        ans = (f[n-1][1] + f[n-1][3]) % mod;
    else
        ans = (f[n-1][0] + f[n-1][1] + f[n-1][2] + f[n-1][3]) % mod;
    cout << ans << endl;

    return 0;
}