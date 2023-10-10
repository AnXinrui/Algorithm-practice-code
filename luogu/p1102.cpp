#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int N = 1e6 + 10;

unordered_map<ll, ll> mp;

int a[N];

int main() {
    ios::sync_with_stdio(false);
    ll n, c, ans = 0;
	cin >> n >> c;
	for (int i = 0; i < n; i ++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i ++) {
		ans += mp[a[i]];	
		++ mp[(ll)a[i] + c];
	}
	cout << ans;

    return 0;
}

