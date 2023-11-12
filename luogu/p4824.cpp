#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

char s[N], t[N];
int ne[N];
int stk[N], tt = -1;
int f[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s + 1 >> t + 1;
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 2, j = 0; i <= m; i ++)
    {
        while (j && t[i] != t[j + 1])
            j = ne[j];
        if (t[i] == t[j + 1])
            j ++;
        ne[i] = j;
    }

    for (int i = 1, j = 0; i <= n; i ++) {
        while (j && s[i] != t[j + 1])
            j = ne[j];
        if (s[i] == t[j + 1])
            j ++;
        stk[++ tt] = i;
        f[i] = j;
        if (j == m) {
            tt -= m;
            j = f[stk[tt]];
        }
    }

    for (int i = 0; i <= tt; i ++)
        cout << s[stk[i]];

    return 0;
}


