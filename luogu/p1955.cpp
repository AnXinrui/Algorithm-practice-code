#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

const int N = 2e6 + 10;

vector<int> alls;
vector<PII> unequal;
int p[N];
int x[N], y[N], op[N];
int n;

void create() {
    for (int i = 1; i < N; i ++)
        p[i] = i;
    for (int i = 1; i <= n; i ++) {
        x[i] = lower_bound(alls.begin(), alls.end(), x[i]) - alls.begin() + 1;
        y[i] = lower_bound(alls.begin(), alls.end(), y[i]) - alls.begin() + 1;
    }
}

int find(int k) {
    if (p[k] != k)
        p[k] = find(p[k]);
    return p[k];
}

bool check() {
    for (auto u: unequal) {
        int i = u.first, j = u.second;
        if (find(i) == find(j))
            return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t --) {
        cin >> n;
        for (int i = 1; i <= n; i ++) {
            cin >> x[i] >> y[i] >> op[i];
            alls.push_back(x[i]);
            alls.push_back(y[i]);
        }
        sort(alls.begin(), alls.end());
        alls.erase(unique(alls.begin(), alls.end()), alls.end());
        create();
        for (int i = 1; i <= n; i ++) {
            if (op[i] == 1) {
                if (find(x[i]) != find(y[i]))
                    p[find(x[i])] = find(y[i]);
            }
            else {
                unequal.push_back({x[i], y[i]});
            }
        }
        if (check())    cout << "YES\n";
        else    cout << "NO\n";
        alls.clear();
        unequal.clear();
    }
    return 0;
}


