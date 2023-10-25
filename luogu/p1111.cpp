#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

bool cmp(vector<int> &a, vector<int> &b) {
    return a[2] < b[2];
}

int p[N], cnt[N];
int n, m;

int find (int k) {
    if (p[k] != k)
        p[k] = find(p[k]);
    return p[k];
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
        cnt[i] = 1;
    }
    vector<vector<int>> v(m, vector<int>(3));
    for (int i = 0; i < m; i ++) {
        cin >> v[i][0] >> v[i][1] >> v[i][2];
    }
    sort(v.begin(), v.end(), cmp);
    for (int i = 0; i < m; i ++) {
    	int a = v[i][0], b = v[i][1];
    	int t = v[i][2];
        int u = find(a), v = find(b);
        if (u != v) {
            p[u] = v;
            cnt[v] += cnt[u];
            if (cnt[v] == n) {
                cout << t << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
    return 0;
}
