class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (!nums.size()) return 0;

        unordered_set<int> s(nums.begin(), nums.end());

        int maxLength = 1;
        for (auto num : nums)
        {
            if (s.find(num - 1) != s.end()) continue;

            int length = 1;
            while (s.count(++num)) length++;

            maxLength = std::max(length, maxLength);
        }

        return maxLength;
    }
};
