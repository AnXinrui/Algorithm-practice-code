#include <iostream>

using namespace std;

const int N = 2e5 + 10;

int parent[N], sz[N];
long long sum[N];

int find(int x) {
	
	if (parent[x] != x) {
		parent[x] = find(parent[x]);
	}
//	cout << parent[x] <<endl;
	return parent[x];
}
// 并查集 + 虚节点 
int main() {
	int n, m;
	while (scanf("%d%d",&n,&m) != EOF) {
	
	for (int i = 1; i <= n; i ++)
		parent[i] = n + i;
	for (int i = 1 + n; i <= n + n; i ++) {
		parent[i] = i;
		sz[i] = 1;
		sum[i] = i - n;
	}
		
	while (m --) {
//		cout << m;
		int k, p, q;
		cin >> k;
		if (k == 1) {
			cin >> p >> q;
			if (find(p) != find(q)) {
				
				sum[find(p)] += sum[find(q)];
				sz[find(p)] += sz[find(q)];
				parent[find(q)] = find(p);
//				cout << find(p) << ' ' << sum[find(p)] << ' ' << size[find(p)] << endl;
			}
		}
		else if (k == 2) {
			cin >> p >> q;
			if (find(p) != find(q)) {
				int a = find(p), b = find(q);
				parent[p] = b;
				sum[b] += p;
				sum[a] -= p;
				sz[b] ++;
				sz[a] --;
			
//				cout << find(q) << ' ' << sum[find(q)] << ' ' << size[find(q)] << endl;
			}
		}
		else {
			cin >> p;
			cout << sz[find(p)] << ' ' << sum[find(p)] << endl;
		}
		
		
	}
}
	return 0;
} 
