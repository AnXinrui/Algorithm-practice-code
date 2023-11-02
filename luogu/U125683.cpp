#include <iostream>
#include <cstdio>


using namespace std;

int p[100010];

int find(int x) {
	if (p[x] != x)
		p[x] = find(p[x]);
	return p[x];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	// f[i][j] -> f[i * n + j]
	for (int i = 1; i <= n * n + n; i ++)
		p[i] = i;
	for (int i = 1; i <= m; i ++) {
		int a, b;
		char c;
		scanf("%d%d %c", &a, &b, &c);
//		char op[2];
//		scanf("%d%d%s", &a, &b, op);

		int x = a * n + b; 
		
		if (c == 'D')
		{
			int y = (a + 1) * n + b;
			int u = find(x), v = find(y);
			if (u == v) {
				cout << i;
				return 0;
			}
			p[u] = v;
		}
		else if (c == 'R') {
			int y = (a) * n + b + 1;
			int u = find(x), v = find(y);
			if (u == v) {
				cout << i;
				return 0;
			}
			p[u] = v;
		}

	}
	puts("draw");
	
	return 0;
}
