/*分析1：对于每个单位矩阵，我们先求出连续比它高的最左边的下标假设为l,然后求出比它高的最右边的下标假设为r，然后矩阵的面积就是(r-l+1)*1；我们从左到

右扫一遍，求出每个点的l保存在l[]数组里，然后从右到左扫一遍，求出每个点的r保存在r[]数组里，最后可以求出最大的矩阵了。


分析2：我们要求最大矩形面积，那么我们应该求每个矩形向两边延伸的最大长度，最坏情况为0（n），必然TLE，那么我们可以应该DP的思想，用一个数组来保存一些结果。

例如,dpl【i】表示从左边过来的最长，那么我们计算dpl【i】的时候，如果左边的比自己高，那么dpl【i】=dpl【i-1】，但是可能在前面还有更多符合情况的(比i-1低但是比i高），所以我们要用i-1-dp【i-1】，继续寻找，详情看代码*/
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
