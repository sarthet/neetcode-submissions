class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        for (int lp = 0; lp < nums.size(); lp++)
        {
            for (int rp = lp + 1; rp < nums.size(); rp++)
            {
                if (nums[lp] + nums[rp] == target)
                {
                    return {lp, rp};
                }
            }
        }

        return {};
    }
};