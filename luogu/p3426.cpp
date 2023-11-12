#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;
int ne[N];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    char s[N];
    cin >> s + 1;
    int n = strlen(s+1);
    for (int i = 2, j = 0; i <= n; i ++) {
        while (j && s[i] != s[j + 1])
            j = ne[j];
        if (s[i] == s[j + 1])
            j ++;
        ne[i] = j;
        // cout << ne[i] << ' ';
    }

    cout << n - ne[n];

    return 0;
}


