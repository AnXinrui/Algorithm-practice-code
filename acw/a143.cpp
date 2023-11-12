#include <iostream>

using namespace std;

const int N = 1e5 + 10, M = 31 * N;
int a[N], trie[M][2], idx;

void insert(int x) {
    int p = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (!trie[p][u])
            trie[p][u] = ++ idx;
        p = trie[p][u];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i --) {
        int u = x >> i & 1;
        if (trie[p][!u]) {
            p = trie[p][!u];
            res = res * 2 + !u;
        }
        else {
            p = trie[p][u];
            res = res * 2 + u;
        }
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    int ans = 0;
    while (n --)
    {
        int a;

        cin >> a;
        insert(a);
        int x = query(a);
        ans = max(ans, a ^ x);
    }
    cout << ans;

    return 0;
}