///该状态压缩主要使用6进制进行压缩，因为最多只有5种物品，每个物品数量不超过5；类比为10进制时，例如种类一为10,种类二为 10^2 = 100
///计算物品总量时，利用位权，若种类一物品为8种，种类二为9种，即 W = 8×10 + 9×100 ;
///如此 使用6进制时，若种类一物品为5种，种类二物品为3种，即 W = 5×6 + 3×(6^2);
///以下
///不仅将单个物体用6进制位权表示，将优惠方案也用6进制位权计算为单个物品
///而后此题便转化为完全背包
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<cstring>

using namespace std;
typedef struct Node{
    int value,num;  //因为最多有五种物品，因此将每种物品和套餐用六进制进行状态压缩
}Node;
Node node[110];
int dp[1000000],match[1000];
int SIX[100] = {0,6,36,216,1296,7776,46656};
int b,c,k,p,s;
int main(){
    while(scanf("%d",&b)!=EOF){
        memset(node,0,sizeof(node));
        memset(dp,0x3f3f3f3f,sizeof(dp));
        int maxx = 0;
        for(int i =1;i <= b;i++){///单个种类物品记为6进制
            scanf("%d%d%d",&c,&k,&p);
            match[c] = i;
            node[i].num = SIX[i];
            node[i].value = p;
            maxx += k*SIX[i]; ///将六进制总数作为背包容量
        }
        int s;
        scanf("%d",&s);
        for(int i = 1;i <= s;i++){
            int m;
            scanf("%d",&m);
            for(int j = 0;j < m;j++){///将优惠方案变为六进制数
                scanf("%d%d",&c,&k);
                int index = match[c];
                node[b+i].num += SIX[index]*k;
            }
            scanf("%d",&p);
            node[b+i].value = p;
        }
        dp[0] = 0;//cout << maxx << endl;
        for(int i = 1;i <= b+s;i++){
                //cout << node[i].num << " xxx " << node[i].value << endl;
            for(int j = node[i].num;j <= maxx;j++){
                dp[j] = min(dp[j],dp[j-node[i].num]+node[i].value);
        //cout << j << " " << dp[j] << endl;
            }
        }
        printf("%d\n",dp[maxx]);
    }
}

