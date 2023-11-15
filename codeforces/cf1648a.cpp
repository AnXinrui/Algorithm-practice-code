#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 1e6 + 10;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    map<int, vector<int>> lx, ly;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            int c;
            cin >> c;
            lx[c].push_back(i);
            ly[c].push_back(j);
        }

    auto solve = [&](map<int, vector<int>> mp) -> long long{
        long long ans = 0;
        for (auto it: mp) {
        	auto v = it.second;
            sort(v.begin(), v.end());
            long long sum = 0, cnt = 0;
            for (int j: v) {
                ans += j * cnt - sum;
                sum += j;
                ++ cnt;
            }
        }
        return ans;
    };
	
	long long ans = solve(lx) + solve(ly);
    cout << ans << endl;

    return 0;
}


