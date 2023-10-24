#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], f[N][2];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (a[i] % 2) {
			f[i][1] = max(f[i-1][0] + a[i],f[i-1][1]);
			f[i][0] = f[i-1][0];
			if (f[i-1][1])
				f[i][0] = max(f[i-1][1] + a[i], f[i][0]);
		}
		else {
			f[i][0] = max(f[i-1][0], f[i-1][0] + a[i]);
			f[i][1] = f[i-1][1];
			if (f[i-1][1])
				f[i][1] = max(f[i-1][1] + a[i],f[i][1]);
		}
//		cout << f[i][0] << ' ' << f[i][1]<<endl;
	}
	cout << f[n][0];
	
	return 0;
}
