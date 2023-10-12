#include <iostream>
#include <cstdio>
using namespace std;
int n;
double p;
double a[100001],b[100001];
double l,r,mid;
int check(double m)
{
    double c=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]*m>b[i])
        c+=(a[i]*m-b[i]);
    }
    c-=p*m;
    if(c>0.0)return 0;
    return 1;
  
}
int main()
{
    cin >> n >> p;
    for(int i=1;i<=n;i++)scanf("%lf%lf",&a[i],&b[i]);
    double c=0;
    for(int i=1;i<=n;i++) c+=a[i];
    if(c-p<=0.0){
        printf("-1");
        return 0;
    }
    l=0.0;
    r=3000000001.0;
    while(l<=r-1e-6)
    {
        mid=(l+r)/2;
        if(check(mid))
        
        {
            l=mid;
        }
        else {
            r=mid;
        }
    }
    printf("%lf",r);
    return 0;
}
