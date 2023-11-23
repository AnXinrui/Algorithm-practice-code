#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 1e6+ 10;

int e[N], ne[N], h[N], idx, cnt[N], v[N];
int n;
void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int dfs(int i, int fa) {
	int c = 1;
	for (int j = h[i]; j != -1; j = ne[j]) {
		int k = e[j];
		if (k == fa)	continue;
		v[k] = v[i] + 1;
		if (cnt[k])
			c += cnt[k];
		else {
			cnt[k] = dfs(k, i);
			c += cnt[k];
		}
	}
	return c;
}

void solve() {
	cin >> n;
	idx = 0;
	memset(h, -1, sizeof h);
	v[1] = 1;
	memset(cnt, 0, sizeof cnt);
	for (int i = 1; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	cnt[1] = dfs(1, 0);
	for (int i = 1; i <= n; i ++) {
		cout << v[i] << ' ' << n - (cnt[i] - 1) << endl;
	}	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr); 
	cout.tie(nullptr); 
	int t;
	cin >> t; 
	while (t --)
		solve();
		
	return 0;
}

