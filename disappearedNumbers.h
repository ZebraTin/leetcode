class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        unordered_set<int> s;
        for(int num:nums)
            if(!s.count(num))
                s.emplace(num);
        for(int i = 1; i<=nums.size(); i++)
        {
            if (!s.count(i)) 
                result.push_back(i);
        }
        return result;

    }
};

/*利用数组本身作为hashmap
由于nums的数字范围均在[1,n]中，我们可以利用这一范围之外的数字，来表达「是否存在」的含义。

具体来说，遍历nums，每遇到一个数x，就让nums[x−1]置为负数
注意，当我们遍历到某个位置时，其中的数可能已经被变为负数，因此需要取绝对值来还原出它本来的值。
最后我们遍历nums，若nums[i]大于0，就说明没有遇到过数i+1。这样我们就找到了缺失的数字。
*/
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size();
        for (int x:nums)
        {
            if (nums[abs(x)-1] > 0)
                nums[abs(x)-1] = -nums[abs(x)-1];
        }
        for (int i=0;i<n; ++i)
        {
            if (nums[i] > 0)
                result.push_back(i+1);
        }
        return result;
    }
};