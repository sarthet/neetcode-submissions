class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums)
    {
        int current = 0;
        int max = 0;
        for (auto num : nums)
        {
            current = num ? current + 1 : 0;
            max = std::max(max, current);
        }

        return max;
    }
};