// Ä£Äâ¶Ñ 

#include <iostream>

using namespace std;

int st[1010];
int q[1010], hh, tt = -1;

int main() {
	int m, n;
	cin >> m >> n;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		
		int x;
		cin >> x;
		
		if (!st[x])
		{
			++ ans;
			q[++ tt] = x;
			++ st[x];
			while (tt - hh + 1 > m) {
				-- st[q[hh]];
				hh ++;
			}
		}
//		cout << ans;
	}
	cout << ans;
	
	return 0;
} 



/* *********************************************** */


// STL
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

unordered_map<int, int> st;
queue<int> q;

int main() {
	int m, n;
	cin >> m >> n;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		
		int x;
		cin >> x;
		
		if (!st[x])
		{
			++ ans;
			q.push(x);
			++ st[x];
			while (q.size() > m) {
				-- st[q.front()];
				q.pop();
			}
		}
//		cout << ans;
	}
	cout << ans;
	
	return 0;
} 
