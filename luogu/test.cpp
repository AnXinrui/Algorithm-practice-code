#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

struct node
{
    int i, j, k;
}a[N];

int p[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve() {
    for (int i = 0; i < N; i ++)
        p[i] = i;
    vector<int> nums;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i].i >> a[i].j >> a[i].k;
        nums.push_back(a[i].i);
        nums.push_back(a[i].j);
    }
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    for (int i = 1; i <= n; i ++) {
        a[i].i = lower_bound(nums.begin(), nums.end(), a[i].i) - nums.begin();
        a[i].j = lower_bound(nums.begin(), nums.end(), a[i].j) - nums.begin();
    }
    sort(a + 1, a + 1 + n, [](node &x, node & y) -> bool {
        return x.k > y.k;
    });
    for (int i = 1; i <= n; i ++) {
        int u = find(a[i].i), v = find(a[i].j);
        if (a[i].k == 1 && u != v)
            p[u] = v;
        if (a[i].k == 0 && u == v)
        {
            puts("NO");
            return;
        }
    }
    puts("YES");
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    cin >> t;
    while(t --) {
         /* code */
        solve();
     }

    return 0;
}


