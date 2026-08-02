class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (!nums.size()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int length = 1;
        int maxLength = 1;

        for (auto num : nums)
        {
            while (s.count(++num)) length++;

            maxLength = std::max(length, maxLength);
            length = 1;
        }

        return maxLength;
    }
};
