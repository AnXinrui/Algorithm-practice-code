#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int son[N][26], idx, cnt[N];
int ans;

void add(string s) {
    int p = 0;
    for (char &c: s) {
        int u = c - 'a';
        if (!son[p][u]) {
            son[p][u] = ++ idx;
            cnt[idx] = cnt[p];
        }
        p = son[p][u];
    }
    ++ cnt[p];
    ans = max(ans, cnt[p]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while (n --) {
        string s;
        cin >> s;
        add(s);
    }
    cout << ans;

    return 0;
}


