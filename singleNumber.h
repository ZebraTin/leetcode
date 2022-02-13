
////异或操作 a^a=0; a^0=a
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(int num:nums)
            result ^= num;
        return result;
    }
};