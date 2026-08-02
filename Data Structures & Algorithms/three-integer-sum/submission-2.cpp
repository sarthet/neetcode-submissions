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
                right--;
                while (left < right && nums[left] == nums[left - 1]) left++;
                while (left < right && nums[right] == nums[right + 1]) right--;
            }
            else if (sum < target) left++;
            else if (sum > target) right--;
        }

        return result;
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            auto current = twoSum(nums, i);
            if (current.empty()) continue;
            result.insert(result.end(), current.begin(), current.end());
        }

        return result;
    }
};
