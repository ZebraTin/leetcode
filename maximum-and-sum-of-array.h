/*状态压缩+动态规划问题
*/

/*
给你一个长度为 n 的整数数组 nums 和一个整数 numSlots ，满足2 * numSlots >= n 。
总共有 numSlots 个篮子，编号为 1 到 numSlots 。
你需要把所有 n 个整数分到这些篮子中，且每个篮子至多有2个整数。
一种分配方案的 与和 定义为每个数与它所在篮子编号的 按位与运算 结果之和。
*/

class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int count = 1<<numSlots*2;
        int len = nums.size();
        int res = 0;
        vector<int> state(count);
        for(int i=0; i<count; ++i){
            int bits = __builtin_popcount(i);
            if (bits >= len) continue;
            for (int j=0; j<numSlots*2; ++j){
                if((i & (1<<j)) == 0){
                    int s = i | (1<<j);
                    state[s] = max(state[s], state[i]+((j/2+1) & nums[bits]));
                    res = max(res, state[s]);
                }
            }
        }
        return res;
    }
};

/*每个篮子有三种状态：0,1,2
篮子个数为m，则可能的状态数一共有3^m个
定义 s(i, mask)为考虑 nums 的前 i 个整数，且篮子的可用状态为 mask时的数组的最大与和。
mask 是一个三进制数，每一位上的数字代表还可以这个位置的篮子还有几个空位，可能的值为0,1,2
我们考虑把nums[i]放到一个空篮子里
假设要放到第k个篮子里,在放置之前第k个篮子里必须还有空位，放入之后最大与和会增加k&nums[i]
那么状态转移就是：
s(i, mask) = max(s(i, mask), s(i-1, mask-3^(k-1)) + (k & nums[i]));
计算复杂度为O(nm*3^m)
*/
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int count = pow(3, numSlots);
        int n = nums.size();
        int state[n+1][count];
        memset(state, 0, sizeof(state));

        for(int i=1; i<=n; ++i){
            for(int j=0; j<count; ++j){
                int jnow = j;
                int value = 1;
                for(int k = 1; k <= numSlots; ++k) {
                    if(jnow % 3) {
                        state[i][j] = max(state[i][j], state[i-1][j-value] + (k & nums[i]));
                    }
                    jnow /= 3;
                    value *= 3;
                }
            }
        }
        return state[n][count-1];
        
    }
};


/*
对于每一个mask，可以得到已经放入篮子的nums的数量cnt
那么接下来要放的就是第cnt+1个数nums[cnt]
因此可以省略对nums的遍历
计算复杂度降为O(m*3^m)
*/
class Solution {
public:
    int maximumANDSum(vector<int>& nums, int numSlots) {
        int n = nums.size(); 
        int snum = 1;
        for(int i = 0; i < numSlots; ++i) snum *= 3;
        
        int state[snum];
        memset(state, 0, sizeof(state));
        
        for(int mask=0; mask<snum; ++mask){
            int mask_temp = mask;
            int cnt = 0;
            for(int k=1; k<=numSlots; ++k){
                cnt += 2 - (mask_temp % 3);
                mask_temp /= 3;
            }
            if(cnt <= n-1){
                mask_temp = mask;
                int val = 1;
                for (int k=1; k<=numSlots; ++k){
                    if(mask_temp % 3){
                        state[mask] = max(state[mask], state[mask-val] +(nums[cnt]& k));
                    }
                    mask_temp /= 3;
                    val *= 3; 
                }
            }
        }
        return state[snum-1];
    }
};