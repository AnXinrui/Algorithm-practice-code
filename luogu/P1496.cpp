#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

// 差分数组
int a[N], b[N];

vector<int> alls;
vector<pair<int, int>> add, query;

int find(int x) {
    int l = 0, r = alls.size() - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int a, b;
        cin >> a >> b;
        add.push_back({a, b});
        alls.push_back(a);
        alls.push_back(b);
    }
    sort(alls.begin(), alls.end());
    alls.erase(unique(alls.begin(), alls.end()), alls.end());
    for (int i = 0; i < n; i ++) {
        int l = find(add[i].first) + 1, r = find(add[i].second) + 1;
        a[l] += 1;
        a[r] -= 1;
    }
    int l, r, t = 0, ans = 0;
    for (int i = 1; i <= alls.size(); i ++) {
        b[i] = b[i-1] + a[i];
        if (t==0 && b[i] > 0) {
            l = alls[i-1];
            t = 1;
        }
        else if (t == 1 && b[i] <= 0) {
            t = 0;
            r = alls[i-1];
            ans += (r - l);
        }

    }
    cout << ans;

    return 0;

}


/*
     -1     2  5  10  12
b     1     1  2  1    0
idx   1     2  3  4   5
a     1     0  1  -1     -1

*/