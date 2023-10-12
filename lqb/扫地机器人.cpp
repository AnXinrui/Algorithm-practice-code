#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N];
int n, k;

bool check(int len) {
	int p = 0;
	for (int i = 1; i <= k; i ++) {
		if (a[i] - len > p)
			return false;
		if (p >= a[i]) 
			p = a[i] + len - 1;	
		else 
			p += len;	
	}
	return p >= n;
}

// time = (len - 1) / 2;

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i ++)
		cin >> a[i];
	sort(a + 1, a + k + 1);
	int l = 0, r = n;
	// 扫的距离越长， 时间越长， 大概率都可以通过。 
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid)) 
			r = mid; 
		else
			l = mid + 1;
	}
	cout << (l - 1) * 2 << endl;
	
	return 0;
} 



