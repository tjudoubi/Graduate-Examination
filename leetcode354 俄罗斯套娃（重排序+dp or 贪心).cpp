/*给定一些标记了宽度和高度的信封，宽度和高度以整数对形式 (w, h) 出现。当另一个信封的宽度和高度都比这个信封大的时候，这个信封就可以放进另一个信封里，如同俄罗斯套娃一样。

请计算最多能有多少个信封能组成一组“俄罗斯套娃”信封（即可以把一个信封放到另一个信封里面）。

说明:
不允许旋转信封。

示例:

输入: envelopes = [[5,4],[6,4],[6,7],[2,3]]
输出: 3 
解释: 最多信封的个数为 3, 组合为: [2,3] => [5,4] => [6,7]。


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/russian-doll-envelopes
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/
class Solution {
public:
    class Node{
        public:
        int x,y;
    };
    static bool cmp(Node a,Node b){
        if(a.x != b.x){
            return a.x < b.x;
        }else{
            return a.y < b.y;
        }
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if(envelopes.size() == 0){
            return 0;
        }
        vector<Node> v;
        for(int i = 0;i < envelopes.size();i++){
            Node node;
            node.x = envelopes[i][0];
            node.y = envelopes[i][1];
            v.push_back(node);
        }
        sort(v.begin(),v.end(),cmp);
        int ans[v.size()+20];
        memset(ans,0,sizeof(ans));
        int maxx = 0;
        for(int i = 0;i < v.size();i++){
            for(int j = i+1;j < v.size();j++){
                if(v[i].x < v[j].x && v[i].y < v[j].y){
                    ans[j] = max(ans[i]+1,ans[j]);
                }
                maxx = max(ans[j],maxx);
            }
        }
        return maxx + 1;
    }
};
