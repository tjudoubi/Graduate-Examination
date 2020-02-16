/*题目意思：   把一个正整数序列划分成m个连续的子序列（每一个整数恰好属于每一个序列），设第i个序列的和为s(i),现在我们的任务就是让所有的S(i)的最大值尽量小。



解题思路：     1:最大值最小化问题：把一个正整数序列划分成m个连续的子序列（每一个整数恰好属于每一个序列），设第i个序列的和为s(i),现在我们的任务就是让所有的S(i)的最大值尽量小。
                       2：最大值最小化问题是一种很常见的优化目标。我么考虑一下新的问题就是，能否把输入的序列划分成m个连续的子序列，使得每一个子序列的S(i)都不超过x，那么只要找到这个最小的x就是S(i)的最大值，然后再去处理这个序列即可
                       3：怎么找到这个x，我么知道x肯定大于等于这个序列的最大值m，并且小于等于sum，那么我们可以利用二分查找，假设mid = X0，那么如果这个时候不满足那么这个x肯定比mid大，所以left = mid。如果这个时候满足，那么x可能等于这个mid或小于mid，所以right = mid。所有数之和为sum，那么二分的时间为O(LogSum)。
                       4：划分原序列，由于题目规定了，在多个满足的情况下尽量让第一个小，第二个小.......。那么要满足这个情况，只能是从后面往前分，并且由于分成几部分已经被限制住还有每一个人至少有一本书，那么我们还要控制当前分的时候，是否有剩下的书本大于等于人数。
                       5：注意使用long long保险*/

#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
#define LL long long
const int MAXN = 10000;
int N,m,k,flag[10000];
LL num[MAXN];
bool judge(LL x){///判断能否把输入序列划分成k个连续子序列。。
    LL sum_temp;
    int index_num = m-1;
    for(int i = 0;i < k;i++){
        sum_temp = 0;
        while(sum_temp+num[index_num] <= x){
            sum_temp += num[index_num];
            if(index_num == -1){
                return true;
            }
            index_num -= 1;
        }
    }
    return false;
}

int main(){
    scanf("%d",&N);
    while(N--){
        memset(num,0,sizeof(num));
        memset(flag,0,sizeof(flag));
        scanf("%d%d",&m,&k);
        LL sum = 0;
        for(int i = 0;i < m;i++){
            scanf("%lld",&num[i]);
            sum += num[i];
        }
        ///二分查找到最适合做切分的序列和
        LL L = 0,R = sum;
        while(L < R){
            LL MID = (R+L)/2;
            if(judge(MID)){
                R = MID;
            }else{
                L = MID+1;
            }
        }

        ///倒着划分序列
        LL xx = 0;
        for(int i = m-1;i >= 0;i--){
            xx += num[i];
            if(xx > L){
                flag[i] = 1;
                xx = num[i];
                k--;
            }
        }
        for(int i = 0;i < m;i++){///如果按照最小序列和没有划分完，就从首位一个一个划分补齐
            if(k == 1)
                break;
            if(flag[i] == 0){
                flag[i] = 1;
                k--;
            }
        }

        for(int i = 0;i < m-1;i++){
            printf("%d ",num[i]);
            if(flag[i]){
                printf("/ ");
            }
        }
        printf("%d\n",num[m-1]);
    }
}
