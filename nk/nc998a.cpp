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

using namespace std;

int n;
vector<int> v;

void dfs(int i) {
	if (i == n + 1) {
		for (auto k: v)
			cout << k << ' ';
		cout << "\n";
		return;	
	}
	v.push_back(i);
	dfs(i + 1);
	v.pop_back();
	dfs(i + 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	dfs(1);
	return 0;
	// var
}

