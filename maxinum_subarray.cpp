class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_pre = 0;
        int result = nums[0];
        for (int i=0; i<nums.size(); i++)
        {
            max_pre = max(max_pre + nums[i], nums[i]);
            result = max(result, max_pre);     
        }
        return result;
    }
};