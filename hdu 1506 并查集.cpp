#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
 
const int maxn=1e5+1000;
ll a[maxn],Left[maxn],Right[maxn];
 
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        if (n==0) break;
        for (int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        Left[1]=1;Right[n]=n;
        for (int i=2;i<=n;i++) {//求出每个矩形左端非递减连续的下标
            int t=i;
            while (t>1&&a[i]<=a[t-1])
                t=Left[t-1];
            Left[i]=t;
        }
        for (int i=n-1;i>=1;i--) {//求出每个矩形右端非递减连续的下标
            int t=i;
            while (t<n&&a[i]<=a[t+1])
                t=Right[t+1];
            Right[i]=t;
        }
        ll ans=0;
        for (int i=1;i<=n;i++)
            ans=max(ans,(Right[i]-Left[i]+1)*a[i]);
        printf("%lld\n",ans);
    }
    return 0;
}
