## dynamic programing
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

## divide and conquer algorithms
class Solution {
public:
    struct status {
        int lSum, rSum, maxSum, iSum;
    };

    status pushUp(status lStatus, status rStatus)
    {
        status s;
        s.lSum = max(lStatus.lSum, lStatus.iSum+rStatus.lSum);
        s.rSum = max(rStatus.rSum, lStatus.rSum+rStatus.iSum);
        s.maxSum = max(max(lStatus.maxSum, rStatus.maxSum), lStatus.rSum+rStatus.lSum);
        s.iSum = lStatus.iSum + rStatus.iSum;
        return s;
    }
    status getStatus(vector<int>& nums, int l, int r)
    {
        if (l == r)
            return (status) {nums[l], nums[l], nums[l], nums[l]}; 
        
        int m = (l+r) >> 1;
        status lStatus = getStatus(nums, l, m);
        status rStatus = getStatus(nums, m+1, r);
        return pushUp(lStatus, rStatus);
    }
    int maxSubArray(vector<int>& nums) {
        return getStatus(nums, 0, nums.size()-1).maxSum;
    }
};