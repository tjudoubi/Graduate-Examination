class Solution {
public:
    void build(vector<int>& nums,int len){
        for(int i = (len-1)/2;i >= 0;i--){
            adjustDown(nums,i,len);
        }
    }
    void adjustDown(vector<int>& nums,int index,int len){
        int i = index;
        while(index <= len){
            int a = 2*index+1,b = 2*index+2;
            int temp_index;
            if(a <= len&&b <= len){
                if(nums[a] > nums[b]){
                    temp_index = a;
                }else{
                    temp_index = b;
                }
                if(nums[index] < nums[temp_index]){
                    int temp = nums[index];
                    nums[index] = nums[temp_index];
                    nums[temp_index] = temp;
                    index = temp_index;
                }else{
                    break;
                }
            }else if(a <= len){
                int temp_index = a;
                if(nums[index] < nums[temp_index]){
                    int temp = nums[index];
                    nums[index] = nums[temp_index];
                    nums[temp_index] = temp;
                    index = temp_index;
                }else{
                    break;
                }
            }else{
                break;
            }
        }
    }
    
    int delete_first(vector<int>& nums,int len){
        int temp = nums[0];
        nums[0] = nums[len];
        nums[len] = temp;
        adjustDown(nums,0,len-1);
        return temp;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size()-1;
        build(nums,len);
        int temp = 0;
        for(int i = 0;i < k;i++){
            temp = delete_first(nums,len-i);
        }
        return temp;
    }
};
