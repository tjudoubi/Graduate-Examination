#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int K,M,N;
const int MAXN = 1000+10;
int mapp[MAXN][MAXN];
int main(){
    scanf("%d",&K);
    while(K--){
        scanf("%d%d",&M,&N);
        memset(mapp,0,sizeof(mapp));
        for(int i = 1;i <= M;i++){
            for(int j = 1;j <= N;j++){
                char temp;
                cin >> temp;///注意这里最好不要用getchar();scanf("%c",&temp);
                if(temp == 'F'){
                    mapp[i][j] = mapp[i-1][j]+1;
                }else{
                    mapp[i][j] = 0;
                }
            }
        }/*cout << endl;
        for(int i = 1;i <= M;i++){
            for(int j = 1;j <= N;j++){
                cout << mapp[i][j]  << " ";
            }cout << endl;
        }*/

        int ans_x = -0x3f3f3f3f;
        for(int i = 1;i <= M;i++){
            int l[MAXN],r[MAXN];
            l[1] = 1;
            r[N] = N;
            for(int j = 2;j <= N;j++){
                int m = j;
                while(m > 1&&mapp[i][j] <= mapp[i][m-1]){
                    m = l[m-1];
                }
                l[j] = m;
            }
            for(int j = N-1;j >= 1;j--){
                int m = j;
                while(m < N && mapp[i][j] <= mapp[i][m+1]){
                    m = r[m+1];
                }
                r[j] = m;
            }
            int ans = 0;
            for(int j = 1;j <= N;j++){
                ans = max(ans,(r[j]-l[j]+1)*mapp[i][j]);
            }
            ans_x = max(ans,ans_x);
        }
        printf("%d\n",ans_x*3);
    }
}
