class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        int sums[len+10],num[len+10],path[len+10][4],dp[len+10][4];
        memset(sums,0,sizeof(sums));
        memset(num,0,sizeof(num));
        memset(path,0,sizeof(path));
        memset(dp,0,sizeof(dp));
        for(int i = 1;i <= len;i++){
            sums[i] = sums[i-1]+nums[i-1];
        }
        for(int i = 1;i+k-1 <= len;i++){
            num[i] = sums[i+k-1]-sums[i-1];
        }
        for(int i = 1;i <= len-k+1;i++){
            for(int j = 1;j <= 3;j++){
                dp[i][j] = dp[i-1][j];
                path[i][j] = path[i-1][j];
                if(i-k >= 1 && dp[i][j] < dp[i-k][j-1]+num[i]){
                    //cout << i << " " << j << " " << dp[i][j] << " " << dp[i-k][j-1] + num[i] << endl;
                    dp[i][j] = dp[i-k][j-1] + num[i];
                    path[i][j] = i;
                }else if(i-k < 1 && dp[i][j] < num[i]){
                    dp[i][j] = num[i];
                    path[i][j] = i;
                }
            }
        }
        //cout << dp[len-k+1][3] << endl;
        vector<int> v;
        int id = len-k+1;
        for(int i = 3;i > 0;i--){
            int target = path[id][i];
            v.push_back(target);
            id = target-k;
        }
        reverse(v.begin(),v.end());
        for(int i = 0;i < v.size();i++){
            v[i] -= 1;
        }
        return v;
    }
};

/*思路
题目是求三个无重叠子数组的最大和
其实可以拓展到N个无重叠子数组的最大和
1，定义如下：
sums[i]代表以nums[i]结尾的前k个数的和
dp[i][j]代表截止到nums[i]形成的第j个无重叠子数组的最大和
path[i][j]代表截止到nums[i]形成的第j个无重叠子数组以哪个下标为结尾，用来回溯路径
2，状态转移方程为
dp[i][j] = max{dp[i - 1][j], sums[i] + dp[i - k][j - 1]};
对应的path[i][j] = path[i - 1][j]或i

作者：da-li-wang
链接：https://leetcode-cn.com/problems/maximum-sum-of-3-non-overlapping-subarrays/solution/c-dong-tai-gui-hua-zhi-nge-wu-zhong-die-zi-shu-zu-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
class Solution {
public:
    vector<int> maxSumOfNSubarrays(vector<int>& nums, int k, int n) {
        if (k < 1 || n * k > nums.size()) return {};
        int N = nums.size();
        int s = 0;
        for (int i = 0; i < k; ++i) {
            s += nums[i];
        }
        // 计算每个数的前k个数的前缀和
        vector<int> sums(N, 0);
        sums[k - 1] = s;
        for (int i = k; i < N; ++i) {
            s += nums[i] - nums[i - k];
            sums[i] = s;
        }
        // 动态规划
        vector<vector<int> > dp(N, vector<int>(n + 1, 0));
        vector<vector<int> > path(N, vector<int>(n + 1, 0));
        dp[k - 1][1] = sums[k - 1];
        path[k - 1][1] = k - 1;
        for (int i = k; i < N; ++i) {
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = path[i - 1][j];
                if (sums[i] + dp[i - k][j - 1] > dp[i][j]) {
                    dp[i][j] = sums[i] + dp[i - k][j - 1];
                    path[i][j] = i;
                }
            }
        }
        // 路径回溯
        vector<int> res;
        int ind = path[N - 1][n];
        res.push_back(ind - k + 1);
        for (int i = n - 1; i > 0; --i) {
            ind = path[ind - k][i];
            res.push_back(ind - k + 1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        // 本题就是n=3的特殊情况，因此调用以下函数即可
        return maxSumOfNSubarrays(nums, k, 3);
    }
};

*/
