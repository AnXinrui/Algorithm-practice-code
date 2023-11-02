#include <stdio.h>
#include <stdlib.h>

const int N = 1e5 + 10;

// sz[i] ��ʾ��iΪ�����ʱ�����Ϲ������ڵ㣬 d[i]��ʾiǰ��ڵ���Ŀ 
int p[N], sz[N], d[N];

int max(int a, int b) {
	if (a > b)	return a;
	return b;
}

int find(int x) {
	if (p[x] != x) {
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= 30000; i ++) {
		p[i] = i;
		sz[i] = 1;
	}
	while (n --) {
		char op[2];
		int a, b;
		scanf("%s%d%d", op, &a, &b);
		int u = find(a), v = find(b);
		if (op[0] == 'M') {
			p[u] = v;
			d[u] = sz[v];
			sz[v] += sz[u];
		}
		else {
			if (u != v)	puts("-1");
			else 	printf("%d\n", max(0, abs(d[a]-d[b])-1));
		}
	}
	
	return 0;
} 
