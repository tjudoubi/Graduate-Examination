/*用dp[i][j]表示第i分钟，疲劳值为j的最大距离。

首先考虑第i分钟休息问题：

①上次已经疲劳为0，这次又休息。dp[i][0]=dp[i-1][0].

②上次疲劳为k。dp[i][0]=max(dp[i][0],dp[i-k][k])，其中i-k>0

然后考虑第i分钟跑步问题

dp[i][j]=dp[i-1][j-1]+d[i]。

这样所有状态就推完了。

最后ans=dp[n][0]。
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAXN = 10010;
int N,M;
int dp[MAXN][510],arr[MAXN];
int main(){
    while(scanf("%d%d",&N,&M)!=EOF){
        memset(arr,0,sizeof(arr));
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= N;i++){
            scanf("%d",&arr[i]);
        }
        for(int i = 1;i <= N;i++){
            for(int j = 0;j <= M;j++){
                if(i-j >= 0){
                    dp[i][0] = max(dp[i][0],max(dp[i-j][j],dp[i-1][0]));
                }
                if(j > 0){
                    dp[i][j] = max(dp[i][j],dp[i-1][j-1]+arr[i]);
                }
            }
        }
        printf("%d\n",dp[N][0]);
    }
}
