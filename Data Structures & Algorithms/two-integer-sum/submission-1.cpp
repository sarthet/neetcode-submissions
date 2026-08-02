class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> values;

        for (int i = 0; i < nums.size(); i++)
        {
            values[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int diff = target - nums[i];
            if (values.count(diff) && values[diff] != i) return {i, values[diff]};
        }

        return {};
    }
};
