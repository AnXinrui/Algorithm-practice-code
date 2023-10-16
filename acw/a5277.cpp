#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int f(int m) {
	int ans = 1;
	for (int i = 1; i <= m; i ++)
		ans *= i;
	return ans;
}

int main() {
	int cnt = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	sort(a + 1, a + n + 1);
	if (a[1] == a[2] && a[2] == a[3]) {
		int t = a[1], cnt = 0;
		for (int i = 1; i <= n; i ++) {
			if (a[i] != t)
				break;
			else
				++ cnt;
		}
//		cout << cnt;
		cout << f(cnt) / f(3) / f(cnt - 3);
	}
	else if (a[1] != a[2] && a[2] == a[3]) {
		int t = a[2], cnt = 0;
		for (int i = 2; i <= n; i ++) {
			if (a[i] != t)
				break;
			else
				++ cnt;
		}
		cout << cnt;
		cout << f(cnt) / f(2) / f(cnt - 1);
	} 
	else if (a[2] != a[3]) {
		int t = a[3], cnt = 0;
		for (int i = 3; i <= n; i ++) {
			if (a[i] != t)
				break;
			else
				++ cnt;
		}
		cout << cnt;
	} 
	else
		cout << 1;
	
	return 0;
}


//  1 1 1 1
//  
//  1 2 2 2 2 2
//  1 2 3 3 3 3
// 123
