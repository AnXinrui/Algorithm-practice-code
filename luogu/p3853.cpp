#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#define ll long long
#define PII pair<int, int>

using namespace std;

const int N = 1e5 + 10;

int a[N];

// 公路的起点和终点保证已设有路标 

int main()
{
    ios::sync_with_stdio(false);
    int d, n, k;
    cin >> d >> n >> k;

    int r = 0, l = 1;
    cin >> a[0];
    int p = a[0];
    for (int i = 1; i < n; i ++) {
        cin >> a[i];
        r = max(r, a[i] - p);
    }
    while (l < r) {
        int m = (l + r) / 2;
        p = a[0];
        ll cnt = 0;
        for (int i = 1; i < n; i ++) {
            if (a[i] - p > m) {
                cnt += (a[i] - p) / m;
                // %%% 注意 
                if ((a[i] - p) % m == 0)    -- cnt;   
            }
            p = a[i];
        }
        if (cnt > k)    l = m + 1;
        else    r = m;
    }
    cout << l << endl;
  
    return 0;
}
