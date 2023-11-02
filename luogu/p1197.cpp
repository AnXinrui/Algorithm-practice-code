#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

// ͼ
int h[N], e[N], ne[N], idx;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int n, m;
vector<int> broken;
stack<int> ans;
// st[i] = 1 ???? 1 û?? ??? 
bool st[N];
int p[N];

int find(int x) {
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        p[i] = i;
        st[i] = 1;
        h[i] = -1;
    }
    while (m --) {
        int x, y;
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
	
    int k;
    cin >> k;
    for (int i = 0; i < k; i ++) {
        int x;
        cin >> x;
        broken.push_back(x);
        st[x] = 0;
    }
	
    int sum = n - k;
    for (int i = 0; i < n; i ++) {
        if (!st[i])     continue;
        for (int j = h[i]; j != -1; j = ne[j]) {
            int a = e[j];
            if (!st[a])     continue;
            int u = find(i), v = find(a);
            if (u != v) {
                sum --;
                p[u] = v;
            }
        }
    }
    ans.emplace(sum);
//	cout << ' ' << sum << endl;
    for (int i = k-1; i >= 0; i --) {
        ++ sum;
        int a = broken[i];
        for (int j = h[a]; j != -1; j = ne[j]) {
            int w = e[j];
            if (!st[w])     continue;
            int u = find(a), v = find(w);
            if (u != v) {
                -- sum;
                p[u] = v;
            }           
        }
        st[a] = 1;
        ans.emplace(sum);
//        cout << ' ' << sum << endl;
    }
    while (!ans.empty()) {
        cout << ans.top() << endl;
        ans.pop();
    }

    return 0;
}


