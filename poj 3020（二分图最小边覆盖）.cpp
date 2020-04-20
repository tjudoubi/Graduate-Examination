/*二分图最小点覆盖
最小点覆盖：实质是个点集，点集里面的点能覆盖所有的边，最小点覆盖就是满足这个要求的点集中点数最小的那个

证明：所有的边分为匹配的（A）边和不是匹配的边（B），最小点覆盖的点集就是要每条匹配的边两端顶点中的一个，

比如现在有x1-y1属于A，x1-y2属于B，对于x1-y1这条匹配边取x1而不取y1，这样就能覆盖到x1-y2，即B也能覆盖到

二分图中最小边覆盖=顶点数-最小点覆盖（最大匹配）

最小边覆盖：实质是个边集，这个集合里的边能覆盖所有的点，最小边覆盖是满足这个要求的所有边集中边数最少的一个

这里顶点数等于总的顶点数，是二分图两边的顶点数，不是一边

证明：设最大匹配数为m，总顶点数为n。为了使边数最少，又因为一条边最多能干掉两个点，所以尽量用边干掉两个点

也就是取有匹配的那些边，当然这些边是越多越好，那就是最大匹配了，所以先用最大匹配数目的边干掉大多数点

剩下的解决没有被匹配的点，就只能一条边干掉一个点了，设这些数目为a

显然，2m+a=n，而最小边覆盖=m+a，

所以最小边覆盖=（2m+a）-m=n-m



*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef struct Node{
    char s;
    int id;
}Node;
Node mapp[50][50];
vector<int> vec[10000];
int n,w,h,vis[10000],link[10000];
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
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&h,&w);
        memset(mapp,0,sizeof(mapp));
        memset(link,-1,sizeof(link));
        int cnt = 0;
        //cout << h << " " << w << endl;
        for(int i = 1;i <= h;i++){
                getchar();
            for(int j = 1;j <= w;j++){
                    //cout << n << " " <<  i << " " << j << endl;
                scanf("%c",&mapp[i][j].s);
                if(mapp[i][j].s == '*'){
                    mapp[i][j].id = cnt;
                    cnt += 1;
                }else{
                    mapp[i][j].id = -1;
                }
            }
        }

        for(int i = 0;i < cnt+10;i++){
            vec[i].clear();
        }
        for(int i = 1;i <= h;i++){
            //cout << i << " " ;
            for(int j = 1;j <= w;j++){
                //cout << mapp[i][j].s ;
                if(mapp[i][j].s == '*'){
                    int t = mapp[i][j].id;
                    if(mapp[i-1][j].s == '*'){
                        int t_1 = mapp[i-1][j].id;
                        vec[t].push_back(cnt+t_1);
                        vec[t_1].push_back(cnt+t);
                    }
                    if(mapp[i][j-1].s == '*'){
                        int t_1 = mapp[i][j-1].id;
                        vec[t].push_back(cnt+t_1);
                        vec[t_1].push_back(cnt+t);
                    }
                }
            }
        //cout << endl;
        }
        int ans = 0;
        for(int i = 0;i < cnt;i++){
            memset(vis,0,sizeof(vis));
            if(dfs(i)){
                ans += 1;
            }
        }
        //cout << cnt << endl;
        printf("%d\n",cnt-ans/2);
    }
}
