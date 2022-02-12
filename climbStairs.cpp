class Solution {
public:
    int climbStairs(int n) {
        int pre1 = 1;
        int pre2 = 0;
        int res;
        for (int i = 1; i<=n; i++)
        {
            res = pre1 + pre2;
            pre2 = pre1;
            pre1 = res;
        }

        return res;
    }
};