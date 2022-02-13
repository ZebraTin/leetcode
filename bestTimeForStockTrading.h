/*保存每一段的最大值，最小值，最大利润
  如果当前值小于前一段的最小值，那么更新最小值，同时把最大值重置，因为前面的最大值已经无效了。
  否则，最小值不变，更新最大值。
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max_pre = prices[0];
        int min_pre = prices[0];
        int max_diff = 0;
        for (int price : prices)
        {
            if(price < min_pre)
            {
                min_pre = price;
                max_pre = min_pre;
            }
            else
            {
                max_pre = max(max_pre, price);
            }
            max_diff = max(max_diff, max_pre-min_pre);
        }
        return max_diff;
    }
};

//// 用每一天的价格减去之前的最小值得到每一天的最大利润，比较所有天的最大利润
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_pre = prices[0];
        int max_diff = 0;
        for (int price:prices)
        {
            max_diff = max(max_diff, price-min_pre);
            min_pre = min(min_pre, price);
        }
        return max_diff;
    }
};