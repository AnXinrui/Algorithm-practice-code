#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int e[N], ne[N], h[N], idx, d[N];

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx ++;
}

int q[N], hh, tt = -1;

int n;

bool topsort() {
	for (int i = 1; i <= n; i ++)
		if (!d[i])
			q[++tt] = i;
	while (hh <= tt) {
		int tmp = q[hh ++];
		for (int i = h[tmp]; i != -1; i = ne[i]) {
			int j = e[i];
			-- d[j];
			
			if (!d[j])
				q[++ tt] = j;
		}
	}
	if (tt == n - 1)
		return true;
	return false;
}

int main() {
	memset(h, -1, sizeof h);
	int m;
	cin >> n >> m;
	while (m --) {
		int a, b;
		cin >> a >> b;
		add(a, b);
		++ d[b];
	}
	topsort();
	cout << tt + 1 << endl;
	for (int i = 0; i <= tt; i ++)
			cout << q[i] << ' ';

	
		
	return 0;
}

