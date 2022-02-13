class Solution {
public:
    int countOnes(int x) {
        int ones = 0;
        while (x > 0) {
            x &= (x - 1);
            ones++;
        }
        return ones;
    }

    vector<int> countBits(int n) {
        vector<int> bits(n + 1);
        for (int i = 0; i <= n; i++) {
            bits[i] = countOnes(i);
        }
        return bits;
    }
};

/*每个2的幂次都只有1个1，而(i&(i-1)) == 0可以用于判断2的幂次
每个数减去2的幂次都可以后，1的个数就减少1个
因此可以用动态规划的方法。
*/
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        int highBit = 0;
        for (int i = 1; i <= n; i++) {
            if( (i&(i-1)) == 0)
                highBit = i;
            bits[i] = bits[i-highBit] + 1;
        }
        return bits;
    }
};

/*如果x是奇数，那么x>>1后的数的1的个数比x少1个
  如果x是偶数，那么x>>1后的数的1的个数和x是一样的
  因此bits[i] = bits[i>>1] + (i&1);
 */
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> bits(n+1);
        for (int i = 1; i <= n; i++) {
            bits[i] = bits[i>>1] + (i&1);
        }
        return bits;
    }
};