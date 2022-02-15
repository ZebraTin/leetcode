class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unoredered map<int,int> count;
        int max_odd_cnt1=0, max_odd_cnt2 = 0;
        int max_odd_num1 = 0;
        int max_even_cnt1 = 0, max_even_cnt2 = 0;
        int max_even_num1 = 0;
        int n = nums.size();
        int ops = 0;
        for(int i=0; i<n; i=i+2){
            ++count[nums[i]];
            if(count[nums[i]] > max_odd_cnt1){
                max_odd_cnt1 = count[nums[i]];
                max_odd_num1 = nums[i];
            }
            else if(count[nums[i]] > max_odd_cnt2){
                max_odd_cnt2 = count[nums[i]];
            }
        }
        count.clear();
        for(int i=1; i<n; i=i+2){
            ++count[nums[i]];
            if(count[nums[i]] > max_even_cnt1){
                max_even_cnt1 = count[nums[i]];
                max_even_num1 = nums[i];
            }
            else if(count[nums[i]] > max_even_cnt2){
                max_even_cnt2 = count[nums[i]];
            }
        }
        if (max_odd_num1 == max_even_num1)
            ops = n - max(max_odd_cnt1+max_even_cnt2, max_odd_cnt2+max_even_cnt1);
        else
            ops = n - max_odd_cnt1 - max_even_cnt1;
        
        return ops;
    }
};