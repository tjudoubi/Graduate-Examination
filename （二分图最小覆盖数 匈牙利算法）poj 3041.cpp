/*
题意:

       有一个N*N的网格,该网格有K个障碍物.你有一把武器,每次你使用武器可以清楚该网格特定行或列的所有障碍.问你最少需要使用多少次武器能清除网格的所有障碍物?

分析:

       把网格的行1到N看出左边点集的点,网格的列号看成右边点集的点. 如果(i,j)格有障碍,那么就在左边i点到右边j点之间连接一条边.

       现在的问题是 我们要在新图中选择最少的点使得所有边都至少有一个端点被选中了.(想想是不是就等价于原问题使用武器次数最少?)

       那么以上就是一个最小覆盖集的问题. 最小覆盖数 = 最大匹配数.
*/

#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
int N,K;
using namespace std;
int link[1000],vis[1000];
vector<int> vec[1000];
bool dfs(int x){
    int len = vec[x].size();
    for(int i = 0;i < len;i++){
        int v = vec[x][i];
        if(!vis[v]){
            vis[v] = 1;
            if(link[v]==-1||dfs(link[v])){
                link[v] = x;
                return true;
            }
        }
    }
    return false;
}

int main(){
    while(scanf("%d%d",&N,&K)!=EOF){
        memset(link,-1,sizeof(link));
        for(int i = 0;i <= N+10;i++){
            vec[i].clear();
        }
        for(int i = 0;i < K;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            vec[a].push_back(N+b);
        }
        int ans = 0;
        for(int i = 1;i <= N;i++){
            memset(vis,0,sizeof(vis));
            if(dfs(i)){
                ans += 1;
            }
        }
        printf("%d",ans);
    }
}
