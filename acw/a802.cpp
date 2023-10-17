#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 3e5 + 10;

// s[N] 为前缀和数组，从1开始计
int a[N], s[N];

vector<int> alls;
vector<PII> add, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int m = l + r >> 1;
        if (alls[m] >= x)
            r = m;
        else
            l = m + 1;
    }
    return l;
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        int x, c;
        cin >> x >> c;
        add.push_back({x, c});
        alls.push_back(x);
    }
    for (int i = 0; i < m; i ++) {
        int l, r;
        cin >> l >> r;
        query.push_back({l, r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 0; i < n; i ++) {
        int x = find(add[i].first);
        a[x + 1] += add[i].second;
    }
    for (int i = 1; i <= alls.size(); i ++) {
        s[i] = s[i-1] + a[i];
    }
    for (int i = 0; i < m; i ++) {
        int l = find(query[i].first) + 1, r = find(query[i].second) + 1;
        cout << s[r] - s[l - 1] << endl;

    }
    return 0;
}