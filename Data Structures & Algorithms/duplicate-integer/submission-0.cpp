class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        if (nums.size() == 0 || nums.size() == 1) return false;
        unordered_set<int> s(nums.begin(), nums.end());

        return s.size() != nums.size();
    }
};