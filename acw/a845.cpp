#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
string ans = "12345678x";

int bfs(string start) {
	queue<string> q;
	unordered_map<string, int> d;
	
	q.push(start);
	d[start] = 0;
	
	while (!q.empty()) {
		string s = q.front();
		int distance = d[s];
		int t = s.find('x');
		int x = t / 3, y = t % 3;
		q.pop();
		
		if (s == ans)	return distance;
		
		for (int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				swap(s[nx * 3 + ny], s[t]);
				if (!d.count(s))
				{
					q.push(s);
					d[s] = distance + 1; 
				}
				swap(s[nx * 3 + ny], s[t]);
			}
		}
	}
	return -1;
}

int main() {
	string start = "";
	for (int i = 0; i < 9; i ++) {
		char c;
		cin >> c;
		start += c;
	}
	
	cout << bfs(start) << endl;
	
	return 0;
}

