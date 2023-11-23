#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	unordered_map<int, int> mp;
	set<int, greater<int>> st; 
	cin >> n >> k;
	
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		int j = a[i];
		++ mp[j];
		if (mp[j] == 1)	st.insert(j);
		if (mp[j] == 2)	st.erase(j);
		
		if (i < k)	continue;
		if (st.empty())
//			cout << "Nothing" << endl;
			puts("Nothing");
		else
			cout << *st.begin() << endl;
		
		int x = a[i - k + 1];
		-- mp[x];
		if (mp[x] == 1)
			st.insert(x);
		else if (mp[x] == 0)
			st.erase(x);			
	}
	
	return 0;
}

