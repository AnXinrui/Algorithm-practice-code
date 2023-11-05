#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

struct node {
    int h, a;
} a[N];

bool cmp(node &a, node &b)
{
    return
}

int n, m, k, p;

bool check(int mid) {
    for (int i = 0; i < m; i ++) {

    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> k >> p;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].h >> a[i].a;
        r = max(r, a[i].h);
        r = max(r, a[i].a);
    }
    while (l < r) {
        int mid = l + r >> 1;

    }

    return 0;
}


