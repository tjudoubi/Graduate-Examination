/*题意
一颗树，n个点（1-n），n-1条边，每个点上有一个权值，求从1出发，走V步，最多能遍历到的权值

思路
0代表s出发回到s, 1代表s出发不回来
初始化每个rt的每个步长都是当前节点的权值
dp[root][j][0] = MAX (dp[root][j][0] , dp[root][j-k][0] + dp[son][k-2][0]);//从s出发，要回到s，需要多走两步s-t,t-s,分配给t子树k步，其他子树j-k步，都返回
dp[root][j]][1] = MAX( dp[root][j][1] , dp[root][j-k][0] + dp[son][k-1][1]) ;//先遍历s的其他子树，回到s，遍历t子树，在当前子树t不返回，多走一步
dp[root][j][1] = MAX (dp[root][j][1] , dp[root][j-k][1] + dp[son][k-2][0]);//不回到s（去s的其他子树），在t子树返回，同样有多出两步
————————————————
版权声明：本文为CSDN博主「Aria461863631」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/Aria461863631/article/details/82356420*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> vec[1000];
int w[1000];
int dp[400][400][2];////0 return , 1 no return
int vis[1000];
int n,k;

void dfs(int u){
    if(vis[u]){
        return ;
    }
    vis[u] = 1;
    int len = vec[u].size();
    for(int i = 0;i <= k;i++){
        dp[u][i][0] = dp[u][i][1] = w[u];
    }

    for(int i = 0;i < len;i++){
        int v = vec[u][i];
        if(!vis[v]){
            dfs(v);
            for(int j = k;j >= 1;j--){
                for(int t = 0;t <= j;t++){
                    if(t-2 >= 0){
                        dp[u][j][0] = max(dp[u][j][0],dp[u][j-t][0]+dp[v][t-2][0]);
                    }
                    if(t-1 >= 0){
                        dp[u][j][1] = max(dp[u][j][1],dp[u][j-t][0]+dp[v][t-1][1]);
                    }
                    if(t-2 >= 0){
                        dp[u][j][1] = max(dp[u][j][1],dp[u][j-t][1]+dp[v][t-2][0]);
                    }
                }
            }
        }
    }
}

int main(){
    while(scanf("%i%i",&n,&k)!=EOF){
        memset(dp,0,sizeof(dp));
        memset(vis,0,sizeof(vis));
        memset(w,-1,sizeof(w));
        for(int i = 0;i < 1000;i++){
            vec[i].clear();
        }
        for(int i = 1;i <= n;i++){
            scanf("%i",&w[i]);
        }
        for(int i = 0;i < n-1;i++){
            int a,b;
            scanf("%i%i",&a,&b);
            vec[a].push_back(b);
            vec[b].push_back(a);
        }
        dfs(1);
        printf("%i\n",max(dp[1][k][1],dp[1][k][0]));
    }
}
