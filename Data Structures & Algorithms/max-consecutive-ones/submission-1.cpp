class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int result = 0;
        int max = 0;
        for (auto num : nums)
        {
            if (num) result++;
            else
            {
                max = result > max ? result : max;
                result = 0;
            }
        }
        max = result > max ? result : max;
        return max;    
    }
};