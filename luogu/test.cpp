#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iomanip>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
#define N (int)(2e5+15)

int n,m,s,l,r,mid;
int w[N],v[N],le[N],ri[N],res=INF,p[N],q[N];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    // freopen("check.in","r",stdin);
    // freopen("check.out","w",stdout);
    cin >> n >> m >> s;
    for(int i=1; i<=n; i++)
    {
        cin >> w[i] >> v[i];
        r=max(r,w[i]);
    }
    for(int i=1; i<=m; i++)
        cin >> le[i] >> ri[i];
    while(l<r)
    {
        int mid=(l+r+1)>>1;
        for(int i=1; i<=n; i++)
        {
            if(w[i]>mid)
                q[i]=q[i-1]+1,p[i]=p[i-1]+v[i];
            else 
                q[i]=q[i-1],p[i]=p[i-1];
        }
        int x=0;
        for(int i=1; i<=m; i++)
            x+=(q[ri[i]]-q[le[i]-1])*(p[ri[i]]-p[le[i]-1]);
        int t=s-x;
        if(t<0)l=mid;
        else if(!t)return cout << 0,0;
        else r=mid-1;
        cout << mid << ' ' << abs(t) << endl;
        res=min(res,abs(t));
    }
    cout << res << '\n';
    return 0;
}

