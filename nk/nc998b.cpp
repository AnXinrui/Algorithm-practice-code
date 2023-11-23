#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

int n, m; 
vector<int> v;
// i 表示当前枚举到第i个数， cnt表示数组中的
// 元素个数 
void dfs(int i, int cnt) {
	// dfs(6,3)	
	if (cnt == m) {
		for (int i = 0; i < v.size(); i ++)
			cout << v[i] << " \n"[i==v.size() - 1];
		return; 
	}
	if (i == n + 1) 
		return;
	// 选择 i 
	v.push_back(i);
	dfs(i + 1, cnt + 1);
	// 不选 i
	v.pop_back();
	dfs(i + 1, cnt); 
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
	
	return 0;
}

