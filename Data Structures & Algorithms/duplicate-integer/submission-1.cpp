class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        unordered_set<int> myset(nums.begin(), nums.end());

        return myset.size() != nums.size();
    }
};