#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 1e6+20;
int arr[MAXN];
int dp[MAXN];
int n,h;
int dfs(int x,int step){
    if(x > h){
        return 0;
    }
    //cout <<x << endl;
    if(dp[x+step] == 0){
        dp[x+step] = dfs(x+step,step+1);
    }
    if(dp[x+step+1] == 0){
        dp[x+step+1] = dfs(x+step+1,step+1);
    }
    return arr[x] + max(dp[x+step],dp[x+step+1]);
}
int main(){
    scanf("%d",&n);
    while(n--){
        memset(dp,0,sizeof(dp));
        scanf("%d",&h);
        h = (1+h)*h/2;
        for(int i = 1;i <= h;i++){
            scanf("%d",&arr[i]);
        }
        printf("%d\n",dfs(1,1))
    }
}
