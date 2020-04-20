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


拆点思想   ：匈牙利拆了点才好写  不然十分麻烦  简单地说就是点复制一遍  从一边开始匹配   

建图：X如果需要覆盖  和它上下左右需要覆盖的点连边  当然这里是和拆完点的另外一个部分的点连边  amp[x][y]两维 分别表示两个集合  

答案   最小路径覆盖 = 顶点数 – 最大二分匹配数/2  为什么要除以2呢，因为拆点复制了一遍 需要除回去  比如 

1 2 有变 变成

1 和2‘  

2 和 1‘形成了匹配   这样匹配就加倍了 所以除以2就好


关于为什么最后匹配数要除以2我是这样认为的，二分图匹配算法本来是作用与一个二分图上面的，现如今要运用到一个二维的图上，我们只有将二维图复制出一个出来，这个在Map函数上也可以看出来，复制出来以后，我们就需要构边了，由于我们所有的边都是重复的，所以最后计算出来的结果就是真是匹配数的两倍了。你可能会说，能不能建立单向的边，来使得所有的计算次数减少，并且不用去除以那个2，其实这是不可行的，因为严格的二分图是图的某一部分内部是没有边的存在，所有的边都是从这一步分指向另外一部分。这里没有办法划分出哪些点只出边不入边。

自己也糊涂了。

 

再次理解：

其实该题求了一个最大匹配的结果（就是一个贪心的思想），即求一个最小的点集使得所有的边的至少有一个端点都落在这个点集之内。由于该题采用拆点的方式来进行构图，之所以可以拆点有一点非常重要，那就是从一个点引出的边之间是不存在边的，这样保证了该点不会与相邻点出现两条以上的边。因此最终的匹配数会乘上2倍，其实该题也可以采用奇偶染色来构图，最后的结果就不需要除以2了。


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
