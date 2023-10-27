#include<bits/stdc++.h>
#define ri register int
#define I __inline__ __attribute((always_inline)) 
using namespace std;
I char nc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
I int read1( ){
    static char c=nc();ri x,f=1;
    for(;c>'9'||c<'0';c=nc()) if(c=='-') f=-1;
    for(x=0;c<='9'&&c>='0';c=nc()) x=(x<<3)+(x<<1)+c-48;
    return x*f;
}
#define N 100005
#define read(a) a=read1()
int n,d,h1,h2,t1,t2,ans=1e9;
int q1[N],q2[N];
struct node{int x, y;}a[N];
I bool cmp(node a,node b)
{return a.x < b.x;}
int main() {
    ri l = 1, i, r;h1 = h2 = 1;
    read(n);read(d);
    for(i=1; i<=n; ++i) read(a[i].x),read(a[i].y);
    sort(a+1,a+n+1,cmp);
    cout <<"--------------------"<<endl;
    for(l=1,r=0;l<=n;++l) {
        while(h1<=t1&&q1[h1]<l) ++h1;                                 // 维护滑动窗口
        while(h2<=t2&&q2[h2]<l) ++h2;
        while(a[q1[h1]].y-a[q2[h2]].y < d && r < n) {
            ++r;
            while(a[q1[t1]].y < a[r].y && h1<=t1) --t1;q1[++t1]=r;          //维护单调队列
            while(a[q2[t2]].y > a[r].y && h2<=t2) --t2;q2[++t2]=r; 
        }
        if(a[q1[h1]].y-a[q2[h2]].y >= d) ans = min(ans,a[r].x-a[l].x);       //更新答案
        cout << a[q1[h1]].x << ' ' << a[q1[h1]].y << endl;
        cout << a[q2[h2]].x << ' ' << a[q2[h2]].y << endl;
        cout << ans << endl;
        cout << endl;
    }
    printf("%d",ans>=1e9?-1:ans);
    return 0;
}
