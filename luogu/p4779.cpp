#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;

int e[N], ne[N], h[N], w[N], idx, n, s;
int dist[N];
bool st[N];

void add(int a, int b, int c) {
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    //cout << a << ' ' << b << ' ' << c << endl;
    h[a] = idx ++;
}

void dijkstra() {
    priority_queue<PII, vector<PII>, greater<PII>> q;
    memset(dist, 0x3f, sizeof dist);
    dist[s] = 0;
    q.push({0, s});
    
    while (!q.empty()) {
        int v = q.top().second, distance = q.top().first;
        q.pop();
        
        
		if (st[v])  continue;
        st[v] = 1;
        
        for (int i = h[v]; i != -1; i = ne[i]) {
            int j = e[i];
            if (dist[j] > dist[v] + w[i]) {
                dist[j] = dist[v] + w[i];
                q.push({dist[j], j});

            }
            
        }
    }
    for (int i = 1; i <= n; i ++)
        cout << dist[i] << ' ';
}

int main() {
    memset(h, -1, sizeof h);
    int m;
    cin >> n >> m >> s;
    while (m --) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    dijkstra();
    return 0;
}
