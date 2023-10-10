#include <iostream>
#include <cstring>


using namespace std;

const int N = 10010;

int e[N], h[N], ne[N], w[N], idx;

int d[N];

int q[N], hh, tt = -1;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx ++;
}

int main() {
    ios::sync_with_stdio(0);
    memset(h, -1, sizeof h);
    int n;
    cin >> n;
    while (n --) {
        int a, c;
        cin >> a >> c;
        w[a] = c;
        while (1) {
            int b;
            cin >> b;
            if (!b) break;
          
            add(b, a);
            ++ d[a];
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i ++) 
        if (!d[i]) {
            cout << i;
            q[++ tt] = i;
            ans = max(ans, w[i]);
        }  
   
    // cout << 's'<<tt<<endl;
    while (hh <= tt) {
        int t = q[hh ++];
        cout << t;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int k = e[i];
            w[k] += w[t];
            -- d[k];
            if (!d[k]) {
                q[++ tt] = k;
                cout << k <<' '<<w[k]<< endl;
                ans = max(ans, w[k]);
            }
        }
    }
    cout << ans;
    return 0;
}