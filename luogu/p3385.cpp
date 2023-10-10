#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
 
using namespace std;

const int N = 1e5 + 10;
int n, m;
int idx, h[N], ne[N], w[N], e[N];
bool st[N];
int dist[N];

void add(int a, int b, int c) {
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx ++;
}

void spfa() {
	memset(dist, 0x3f, sizeof dist);
	queue<int> q;
	dist[1] = 0;
	q.push(1);
	st[1] = 1;
	
	while (!q.empty()) {
		int t = q.front();
		q.pop();
		st[t] = 0;
		
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				if (!st[j])
					q.push(j);
			}
		}
	}	
}

int main() {
	cin >> n >> m;
	memset(h, -1, sizeof h);
	
	while (m --) {
		int a, b, c;
		cin >> a >> b >> c;
		add(a, b, c);
	}
	
	spfa();
	if (dist[n] == 0x3f3f3f3f)
		puts("impossible");
	else
		cout << dist[n];
		
	return 0;
	
} 
