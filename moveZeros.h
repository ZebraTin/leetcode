class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        int n = nums.size();
        while(i<n){
            if (nums[i] == 0){
                nums.erase(nums.begin()+i);
                nums.push_back(0);
                --n;
            }
            else
                ++i;
        }
    }
};

/*双指针法
左指针指向已经整理好的序列的末尾的下一个，第1个0所在位置
右指针指向还未整理的序列的开头
如果右指针当前位置非0，那么交换左指针和右指针的值，同时左指针右移1个数据
右指针遍历所有数据。
*/
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = -1;
        int right = 0;
        for(right=0; right<nums.size(); ++right){
            if(nums[right]){
                nums[++left] = nums[right];
                if(left != right)
                    nums[right] = 0;
            }
        }
    }
};

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int temp;
        for(right=0; right<nums.size(); ++right){
            if(nums[right]){
                temp = nums[right];
                nums[right] = nums[left];
                nums[left] = temp;
                ++left;
            }
        }
    }
};