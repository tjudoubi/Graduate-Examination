/*递推公式dp[x|y] = min(dp[x|y],dp[x] + dp[y])*/
/*作为项目经理，你规划了一份需求的技能清单 req_skills，并打算从备选人员名单 people 中选出些人组成一个「必要团队」（ 编号为 i 的备选人员 people[i] 含有一份该备选人员掌握的技能列表）。

所谓「必要团队」，就是在这个团队中，对于所需求的技能列表 req_skills 中列出的每项技能，团队中至少有一名成员已经掌握。

我们可以用每个人的编号来表示团队中的成员：例如，团队 team = [0, 1, 3] 表示掌握技能分别为 people[0]，people[1]，和 people[3] 的备选人员。

请你返回 任一 规模最小的必要团队，团队成员用人员编号表示。你可以按任意顺序返回答案，本题保证答案存在。

 

示例 1：

输入：req_skills = ["java","nodejs","reactjs"], people = [["java"],["nodejs"],["nodejs","reactjs"]]
输出：[0,2]
示例 2：

输入：req_skills = ["algorithms","math","java","reactjs","csharp","aws"], people = [["algorithms","math","java"],["algorithms","math","reactjs"],["java","csharp","aws"],["reactjs","csharp"],["csharp","math"],["aws","java"]]
输出：[1,2]
 

提示：

1 <= req_skills.length <= 16
1 <= people.length <= 60
1 <= people[i].length, req_skills[i].length, people[i][j].length <= 16
req_skills 和 people[i] 中的元素分别各不相同
req_skills[i][j], people[i][j][k] 都由小写英文字母组成
本题保证「必要团队」一定存在

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/smallest-sufficient-team
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        map<string,int> mapp;
        vector<int> nums;
        int top = 1 << req_skills.size();
        int dp[top+10],pre[top+10],preState[top+10];
        memset(dp,-1,sizeof(dp));
        memset(pre,-1,sizeof(pre));
        memset(preState,-1,sizeof(preState));

        for(int i = 0;i < req_skills.size();i++){
            mapp[req_skills[i]] = i;
        }
        for(int i = 0;i < people.size();i++){
            int temp = 0;
            for(int j = 0;j < people[i].size();j++){
                map<string,int>::iterator iter = mapp.find(people[i][j]);
                if(iter!=mapp.end()){
                    temp += pow(2,mapp[people[i][j]]);
                }
            }
            dp[temp] = 1;
            pre[temp] = i;
            nums.push_back(temp);
        }
        // for(int i = 0;i < nums.size();i++){
        //     cout << nums[i] << endl;
        // }
        for(int i = 0;i < nums.size();i++){
            for(int j = top-1; j >= 0;j--){
                if(dp[j] == -1){
                    continue;
                }
                if(dp[j|nums[i]] == -1 || dp[j|nums[i]] > dp[j]+dp[nums[i]]){
                    dp[j|nums[i]]=dp[j]+1;
                    pre[j|nums[i]] = i;
                    preState[j|nums[i]] = j;
                }

            }
        }
        int temp = top-1;
        vector<int> v;
        while(temp!=-1&&dp[temp] != -1){
            v.push_back(pre[temp]);
            temp = preState[temp];
        }
        return v;
    }
};
