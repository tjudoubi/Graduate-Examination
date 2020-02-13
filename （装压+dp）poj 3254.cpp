#include <cstdio>
#include <cstring>
using namespace std;
 
#define mod 100000000
int M,N,top = 0;
//top表示每行最多的状态数
 
int state[600],num[110];  
//state存放每行所有的可行状态（即没有相邻的状态
//
 
int dp[20][600];
//dp[i][j]:对于前i行数据，每行有前j种可能状态时的解
int cur[20];
//cur[i]表示的是第i行整行的情况
 
inline bool ok(int x){	//判断状态x是否可行
   if(x&x<<1)	return false;//若存在相邻两个格子都为1，则该状态不可行
   return true;
}
void init(){			//遍历所有可能的状态
   top = 0;
   int total = 1 << N; //遍历状态的上界
   for(int i = 0; i < total; ++i){
       if(ok(i))state[++top] = i;	
   }
}
inline bool fit(int x,int k){ //判断状态x 与第k行的实际状态的逆是否有‘重合’
   if(x&cur[k])return false; //若有重合，（即x不符合要求）
   return true;  //若没有，则可行
}
 
int main(){
    while(scanf("%d%d",&M,&N)!= EOF){
       init();
       memset(dp,0,sizeof(dp));
       for(int i = 1; i <= M; ++i){
           cur[i] = 0;
           int num;
           for(int j = 1; j <= N; ++j){  //输入时就要按位来存储，cur[i]表示的是第i行整行的情况，每次改变该数字的二进制表示的一位
                scanf("%d",&num);  //表示第i行第j列的情况（0或1）
               if(num == 0) //若该格为0	
				   cur[i] +=(1<<(N-j)); //则将该位置为1（注意要以相反方式存储，即1表示不可放牧
           }
       }
       for(int i = 1;i <= top;i++){
           if(fit(state[i],1)){  //判断所有可能状态与第一行的实际状态的逆是否有重合
                dp[1][i] = 1;  //若第1行的状态与第i种可行状态吻合，则dp[1][i]记为1
           }
       
	   }
 
	   /*
	   状态转移过程中，dp[i][k] =Sigma dp[i-1][j] （j为符合条件的所有状态）
		*/
       for(int i = 2; i <= M; ++i){  //i索引第2行到第M行
           for(int k = 1; k <= top; ++k){ //该循环针对所有可能的状态，找出一组与第i行相符的state[k]
                if(!fit(state[k],i))continue; //判断是否符合第i行实际情况
                for(int j = 1; j <= top ;++j){ //找到state[k]后，再找一组与第i-1行符合，且与第i行（state[])不冲突的状态state[j]
                   if(!fit(state[j],i-1))continue;  //判断是否符合第i-1行实际情况
                   if(state[k]&state[j])continue;  //判断是否与第i行冲突
                   dp[i][k] = (dp[i][k] +dp[i-1][j])%mod;  //若以上皆可通过，则将'j'累加到‘k'上
                }
           }
       }
       int ans = 0;
       for(int i = 1; i <= top; ++i){ //累加最后一行所有可能状态的值，即得最终结果！！！泥马写注释累死我了终于写完了！
           ans = (ans + dp[M][i])%mod;
       }
       printf("%d\n",ans);
   }
}
