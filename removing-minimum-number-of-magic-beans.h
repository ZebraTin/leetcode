////recursion
class Solution {
public:
    long long get(vector<int>& beans, vector<long long>& accum, int index, int n){
        if (index == n-1)
            return 0;
        long long cnt = min(accum[index+1]-(long long)beans[index]*(n-index-1), get(beans, accum, index+1, n)+beans[index]);
        return cnt;
        
    }
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        vector<long long> accum(n);
        accum[n-1] = beans[n-1];
        for(int i=n-2; i>=0; --i)
            accum[i] = accum[i+1]+beans[i];
        
        long long res = get(beans, accum, 0, n);
        return res;

    }
};


////iteration
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        vector<long long> accum(n);
        accum[n-1] = beans[n-1];
        long long res = 0;
        for(int i=n-2; i>=0; --i){
            accum[i] = accum[i+1]+beans[i];
            res = min(accum[i+1]-(long long)beans[i]*(n-i-1), res+beans[i]);
        }
        return res;

    }
};

////只保留1个后缀和
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long accum = beans[n-1];
        long long res = 0;
        for(int i=n-2; i>=0; --i){
            res = min(accum-(long long)beans[i]*(n-i-1), res+beans[i]);
            accum += beans[i];
        }
        return res;
    }
};

/*首先把数组进行排序，从低到高，总共有n个包
那么以b[i]为基准，那么总共需要减少的豆子数为
 sum(b[0]:b[i-1]) + (sum(b[i+1]:b[n-1]) - b[i]*(n-i-1))
=sum(b[0]:b[n-1]) - b[i]*(n-i)
*/
class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        sort(beans.begin(), beans.end());
        int n = beans.size();
        long long accum = accumulate(beans.begin(), beans.end(), 0LL);
        long long res = LONG_LONG_MAX;
        for(int i=0; i<n; ++i){
            res = min(res, accum - (long long)(n-i)*beans[i]);
        }
        return res;
    }
};