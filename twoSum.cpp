class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        vector<int> result;
        for (int i = 0; i<nums.size(); ++i)
        {
            if (hashmap.count(target-nums[i]))
            {
                result[0] = hashmap[target-nums[i]];
                result[1] = i;
                return result;
            }
            hashmap[nums[i]] = i;
        }
        return result;
    }
};