class Solution {
public:
    bool isPalindrome(int x)
    {
        /// 1233443321
        /// 121
        /// 1221
        if (x < 0) return false;

        long long reversed = 0;
        int original = x;
        while (x)
        {
            int let = x % 10;
            reversed = reversed * 10 + let;
            x = x / 10;
        }

        return original == reversed;
    }
};