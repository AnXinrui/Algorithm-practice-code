#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <functional>

using namespace std;

const int N = 1e6+ 10;

int n;

int f(int x) {
	int ans = 1;
	for (int i = 2; i <= x; i ++)
		ans *= i;
	return ans;
}

void solve() {
	cin >> n;
	long long c1=0, c2=0, c3=0, c4=0,ans = 0;
	for (int i = 0; i < n; i ++){
		int x;
		cin >> x;
		if (x < 0)	++ c1;
		else if (x == 0)	++ c2;
		if (x == 1) 	++ c3;
		if (x > 0)	++ c4;
	}
	ans = c1 * c4 + c2 * c4 + c3 * (c4 - c3);
	long long c = 1;
	if (c3 > 2) {
		for (int i = c3 - 2 + 1; i <= c3; i ++)
			c *= i;
		c /= 2;
		ans += f(c3) / f(2) / f(c3 - 2);
	}
	
	
	cout << ans << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(nullptr);  
	int t;
	cin >> t; 
	while (t --)
		solve();
		
	return 0;
}

