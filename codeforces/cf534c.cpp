#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#include <algorithm>

const int N = 2e5 + 10;

using namespace std;

int w[N];

int main() {
	int n;
	long long a, sum = 0;
	cin >> n >> a;
	for (int i = 1; i <= n; i ++) {
		cin >> w[i];
		sum += w[i];
	}
	for (int i = 1; i <= n; i ++) {
		int mx = min((long long)w[i], a - (n - 1));
		int mn = max((long long)1, a - (sum - w[i]));
		int res = w[i] - (mx - mn + 1);
		cout << res << ' '<<" \n"[i == n];
	}	
	return 0; 
}

