#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <functional>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n;
bool st[11];
vector<int> v;

int main() {
	cin >> n;
	auto dfs = [&](int num) -> void {
		if (num == n) {
		for (int i = 0; i < n; i ++) 
			cout << v[i] << " \n"[i == n - 1];
		}
		for (int i = 1; i <= n; i ++) 
			if (!st[i]) {
				st[i] = true;
				v.push_back(i);
				dfs(num + 1);
				v.pop_back(); 
				st[i] = false;
			}
	};	
	
	dfs(0);
	return 0;
}

