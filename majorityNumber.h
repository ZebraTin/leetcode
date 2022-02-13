////hashmap
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int max_cnt=0;
        int major_num=nums[0];
        unordered_map<int,int> set;
        for (int num:nums)
        {
            ++set[num];
            if(set[num] > max_cnt)
            {
                max_cnt = set[num];
                major_num = num;
            }
        }
        return major_num;
    }
};

/////sort, nums.size()/2一定是众数所在的位置
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size()/2];
    }
};

////随机化方法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int cnt=0;
        while(cnt<=nums.size()/2)
        {
            cnt = 0;
            candidate = nums[rand() % nums.size()];
            for (int num:nums)
                if (num == candidate)
                    ++cnt;
        }
        return candidate;
    }
};

//// 分治法
class Solution {
public:
    int majorCount(vector<int>&nums, int major, int begin, int end){
        int cnt=0;
        for(int i=begin; i<=end; i++)
            if(nums[i]==major)
                ++cnt;
        return cnt;
    }
    int majorityRange(vector<int>&nums, int begin, int end){
        if (begin == end)
            return nums[begin];
        int mid = (begin+end)/2;
        int leftmajor = majorityRange(nums, begin, mid);
        int rightmajor = majorityRange(nums, mid+1, end);
        if (majorCount(nums, leftmajor, begin, end)>(end-begin+1)/2)
            return leftmajor;
        else
            return rightmajor;
    }
    int majorityElement(vector<int>& nums) {
        return majorityRange(nums, 0, nums.size()-1);
    }
};



////投票法
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 0;
        for (int num:nums)
        {
            if (count == 0)
                candidate = num;
            if (num == candidate)
                ++count;
            else 
                --count;
        }
        return candidate;
    }
};