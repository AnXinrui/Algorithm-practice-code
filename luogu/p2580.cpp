#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 1e5 + 10;

int son[N][26], cnt[N], st[N], idx;

void insert(string s) {
	int p = 0;
	for (auto &i: s) {
		int u = i - 'a';
		if (!son[p][u]) 
			son[p][u] = ++ idx;
		p = son[p][u];
	}
	cnt[p] ++;
} 

string query(string s) {
	int p = 0;
	for (auto &i: s) {
		int u = i - 'a';
		if (!son[p][u])
			return "WRONG";
		p = son[p][u];
	}
	if (cnt[p] && !st[p]) {
		++ st[p];
		return "OK";
	}
		
	if (cnt[p] && st[p])
		return "REPEAT";
	return "WRONG";
}

int main() {
	int n;
	cin >> n;
	while (n --) {
		string s;
		cin >> s;
		insert(s);
	}
	int m;
	cin >> m;
	while (m --) {
		string s;
		cin >> s;
		cout << query(s) << endl;
	}
	
	return 0;
}

