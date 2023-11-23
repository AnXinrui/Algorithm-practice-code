#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;

int n;
int h[N], ne[N], e[N], idx;
int st[N];

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

vector<int> v1, v2;

void dfs(int k) {
    for (int i = h[k]; i != -1; i = ne[i]) {
        int j = e[i];
        if (!st[j]) {
            st[j] = 1;
            v1.push_back(j);
            dfs(j);
        }
    }
}

void bfs() {
    queue<int> q;
    memset(st, 0, sizeof st);
    q.push(1);
    v2.push_back(1);
    st[1] = 1;

    while(!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (!st[j]) {
                st[j] = 1;
                v2.push_back(j);
                q.push(j);
            }
        }
     }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    int m;
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int a, b;
        cin >> a >> b;
        add(a, b);
    }

    v1.push_back(1);
    st[1] = 1;
    dfs(1);
    bfs();
    for (int i = 0; i < v1.size(); i ++)
        cout << v1[i] << ' ';
    cout<<endl;
    for (int i = 0; i < v2.size(); i ++)
        cout << v2[i] << ' ';

    return 0;
}


