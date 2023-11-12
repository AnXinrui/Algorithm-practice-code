#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int tr[N], n, m;

int lowbit(int x) {
    return x & -x;
}

void add(int x, int v) {
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += v;
}

int query(int x) {
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        add(i, x);
        add(i + 1, -x);
    }

    while (m --) {
        int c, x, y, k;
        cin >> c;
        if (c == 1) {
            cin >> x >> y >> k;
            add(x, k);
            add(y + 1, -k);
        }
        else {
            cin >> x;
            cout << query(x) << endl;
        }
    }
    return 0;
}