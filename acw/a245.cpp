#include <iostream>

using namespace std;

const int N = 5e5 + 10;

int w[N];
int n, m;

struct tree
{
    int l, r, sum, dat, lmax, rmax;
}tr[N * 4];

void build(int p, int l, int r) {
    if (l == r) {
        tr[p] = {l, l, w[l], w[l], w[l], w[l]};
        return;
    }
    tr[p].l = l, tr[p].r = r;
    int mid = (l + r) / 2;
    build(p * 2, l, mid);
    build(p * 2 + 1, mid + 1, r);
    tr[p].sum = tr[p * 2].sum + tr[p * 2 + 1].sum;
    tr[p].lmax = max(tr[p * 2].lmax, tr[p * 2].sum + tr[p * 2 + 1].lmax);
    tr[p].rmax = max(tr[p * 2 + 1].rmax, tr[p * 2].rmax + tr[p * 2 + 1].sum);
    tr[p].dat = max(max(tr[p * 2].dat, tr[p * 2 + 1].dat), tr[p * 2].rmax + tr[p * 2 + 1].lmax);
}

tree query(int p, int l, int r) {
    if (l <= tr[p].l && r >= tr[p].r)   return tr[p];
    int mid = (tr[p].l + tr[p].r) / 2;
    if (r <= mid) return query(p * 2, l, r);
    else if (l > mid)   return query(p * 2 + 1, l, r);
    else {
        tree a = query(p * 2, l, r), b = query(p * 2 + 1, l, r);
        tree c;
        c.sum = a.sum + b.sum;
        c.lmax = max(a.lmax, a.sum + b.lmax);
        c.rmax = max(b.rmax, a.rmax + b.sum);
        c.dat = max(max(a.dat, b.dat), a.rmax + b.lmax);
        return c;
    }

}

void modify(int p, int x, int y) {
    if (tr[p].l == x && tr[p].r == x) {
        tr[p] = {x, x, y, y, y, y};
        return;
    }
    int mid = (tr[p].l + tr[p].r) / 2;
    if (x <= mid)
        modify(p * 2, x, y);
    else
        modify(p * 2 + 1, x, y);
    tr[p].sum = tr[p * 2].sum + tr[p * 2 + 1].sum;
    tr[p].lmax = max(tr[p * 2].lmax, tr[p * 2].sum + tr[p * 2 + 1].lmax);
    tr[p].rmax = max(tr[p * 2 + 1].rmax, tr[p * 2].rmax + tr[p * 2 + 1].sum);
    tr[p].dat = max(max(tr[p * 2].dat, tr[p * 2 + 1].dat), tr[p * 2].rmax + tr[p * 2 + 1].lmax);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> w[i];
    build(1, 1, n);
    while (m --) {
        int k, x, y;
        cin >> k >> x >> y;
        if (k == 1) {
            if (x > y)  swap(x, y);
            cout << query(1, x, y).dat << endl;
        }
        else
            modify(1, x, y);
    }
}