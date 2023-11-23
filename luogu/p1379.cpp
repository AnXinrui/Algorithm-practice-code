#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int dx[]={1, 0, -1, 0}, dy[]={0, 1, 0, -1};

string ans = "123804765";

void bfs(string in) {
	queue<string> q;
	unordered_map<string, int> d;
	q.push(in);
	d[in] = 0;
	
	while (!q.empty()) {
		string s = q.front();
		int nums = d[s];
		int t = s.find('0');
		int x = t / 3, y = t % 3;
		q.pop();
		if (s == ans) {
			cout << nums << endl;
			return;
		}
		for (int i = 0; i < 4; i ++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				swap(s[t], s[nx * 3 + ny]);
				if (!d.count(s)) {
					q.push(s);
					d[s] = nums + 1;
				}
				swap(s[t], s[nx * 3 + ny]);
			}
		}
	}
}

int main() {
	string in;
	cin >> in;
	
	bfs(in);
	return 0;
}

