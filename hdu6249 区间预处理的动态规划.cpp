/*t[i] 为起点为i的最远端终点
因为覆盖是连续的，那么覆盖得肯定越远越好，我们用t[j]表示所有覆盖过j位置的邮集y最远的地方是哪里，
那么直接由f[i-1][j-1]转移到f[i][t[j]]就行了，然后f[i][j]=max(f[i][j],f[i-1][j],f[i][j-1])
*/
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int T,N,M,K;
const int MAXN = 4000;
int dp[MAXN][MAXN];
int range[MAXN];
int main(){
    scanf("%d",&T);
    int ce = 1;
    while(T--){
        memset(range,0,sizeof(range));
        memset(dp,0,sizeof(dp));
        scanf("%d%d%d",&N,&M,&K);
        for(int i = 0;i < M;i++){
            int L,R;
            scanf("%d%d",&L,&R);
            for(int j = L;j <= R;j++){
                range[j] = max(range[j],R);
            }
        }
        int ans = 0;
        for(int i = 1;i <= K;i++){
            for(int j = 1;j <= N;j++){
                dp[i][j] = max(dp[i][j],max(dp[i][j-1],dp[i-1][j]));
                ans = max(dp[i][j],ans);
                if(range[j]){
                    dp[i][range[j]] = max(dp[i][range[j]],dp[i-1][j-1] + range[j]-j+1);
                    ans = max(ans,dp[i][range[j]]);
                }
            }
        }
        printf("Case #%d: %d\n",ce,ans);
        ce += 1;
    }
}
