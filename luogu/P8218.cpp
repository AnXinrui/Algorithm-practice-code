#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N];
int p[N];

int main() {
	int n, m;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	
	cin >> m;
	while (m --) {
		int l, r;
		cin >> l >> r;
		cout << p[r] - p[l - 1] << endl;
	}
	return 0;
}
