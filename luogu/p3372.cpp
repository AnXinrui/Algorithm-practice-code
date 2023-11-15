#include <iostream>

using namespace std;

const int N = 1e5 + 10;

long long w[N];
int n, m;

struct tree {
    int l, r;
    long long sum, add;
} tr[N * 4];

void build(int p, int l, int r) {
    tr[p].l = l;
    tr[p].r = r;
    if (l == r) {
        tr[p].sum = w[l];
        return;
    }
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tr[p].sum = tr[p * 2].sum + tr[p * 2 + 1].sum;
}

void add(int p, int x, int y, int k) {
    if (tr[p].l == x && tr[p].r == y)
    {
        tr[p].add += k;
        return;
    }
    if (tr[p].add) {
        tr[p * 2].add += tr[p].add;
        tr[p * 2 + 1].add += tr[p].add;
        tr[p].add = 0;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    if (y <= mid)
        add(p * 2, x, y, k);
    else if (x > mid)
        add(p * 2 + 1, x, y, k);
    else
        add(p * 2, x, mid, k),
        add(p * 2 + 1, mid + 1, y, k);
    tr[p].sum = tr[p * 2].sum + tr[p * 2].add * (tr[p * 2].r -
        tr[p * 2].l + 1) + tr[p * 2 + 1].sum + tr[p * 2 + 1].add * (tr[p * 2 + 1].r - tr[p * 2 + 1].l + 1);
}

long long query(int p, int x, int y) {
    if (tr[p].l == x && tr[p].r == y)
        return tr[p].sum + tr[p].add * (tr[p].r - tr[p].l + 1);
    if (tr[p].add) {
        tr[p * 2].add += tr[p].add;
        tr[p * 2 + 1].add += tr[p].add;
        tr[p].add = 0;
    }
    int mid = (tr[p].l + tr[p].r) >> 1;
    long long res = 0;
    if (y <= mid)
        res = query(2 * p, x, y);
    else if (x > mid)
        res = query(2 * p + 1, x, y);
    else
        res = query(2 * p, x, mid) + query(2 * p + 1, mid + 1, y);
    tr[p].sum = tr[p * 2].sum + tr[p * 2].add * (tr[p * 2].r -
        tr[p * 2].l + 1) + tr[p * 2 + 1].sum + tr[p * 2 + 1].add * (tr[p * 2 + 1].r - tr[p * 2 + 1].l + 1);
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    build(1, 1, n);
    while (m --) {
        int o, x, y, k;
        cin >> o;
        if (o % 2) {
            cin >> x >> y >> k;
            add(1, x, y, k);
        }
        else {
            cin >> x >> y;
            cout << query(1, x, y) << "\n";
        }
    }
    return 0;
}