#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i ++)
        cin >> p[i].second >> p[i].first;
    sort(p.begin(), p.end(), greater<pair<int, int>>());
    priority_queue<int, vector<int>, greater<int>> q;
    long long len = 0, ans = 0;
    for (int i = 0; i < n; i ++) {
        len += p[i].second;
        q.push(p[i].second);
        if (q.size() > k) {
            len -= q.top();
            q.pop();
        }
        ans = max(ans, p[i].first * len);
    }
    cout << ans << endl;
    return 0;
}