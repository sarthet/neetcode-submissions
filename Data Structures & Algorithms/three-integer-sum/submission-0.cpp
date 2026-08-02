class Solution {
private:
    vector<vector<int>> twoSum(vector<int>& nums, int index)
    {
        int target = -nums[index];
        int left = index + 1;
        int right = nums.size() - 1;
        vector<vector<int>> result;

        while (left < right)
        {
            auto sum = nums[left] + nums[right];
            if (sum == target)
            {
                result.emplace_back(vector<int>{nums[index], nums[left], nums[right]});
                left++;
            }
            else if (sum < target) left++;
            else if (sum > target) right--;
        }

        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        set<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            auto current = twoSum(nums, i);
            if (current.empty()) continue;
            result.insert(current.begin(), current.end());
        }

        return vector<vector<int>>(result.begin(), result.end());
    }
};
