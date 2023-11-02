#include <bits/stdc++.h>
// #include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct node
{
    int x, y, v;
}a[N];

int p[N];
// 保留与他不和的人
int b[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= k; i ++)
        cin >> a[i].x >> a[i].y >> a[i].v;
    for (int i = 1; i <= n; i ++)
        p[i] = i;
    sort(a + 1, a + 1 + k, [](node &a, node &b) -> bool{
        return a.v > b.v;
    });
    for (int i = 1; i <= k; i ++) {
        int x = a[i].x, y = a[i].y, v = a[i].v;
        if (find(x) == find(y)) {
            cout << v;
            return 0;
        }
        else {
            if (!b[x])
                b[x] = y;
            else
                p[find(y)] = p[find(b[x])];
            if (!b[y])
                b[y] = x;
            else
                p[find(x)] = find(b[y]);
        }
    }
    cout << 0;
    return 0;
}