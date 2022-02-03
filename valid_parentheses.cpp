class Solution {
public:
    bool isValid(string s) {
        int slen = s.size();
        if (slen % 2)
            return false;

        map<char, char> pairs = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };

        stack<char> stk;
        for (char ch:s)
        {
            if (pairs.count(ch))
            {
                if (stk.empty() || stk.top() != pairs[ch])
                    return false;
                else
                    stk.pop();                    
            }
            else
                stk.push(ch);
        }
        return stk.empty();

    }
};