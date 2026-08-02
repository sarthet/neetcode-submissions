class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> myMap;
        myMap.reserve(nums.size());

        for (int i = 0; i < nums.size(); i++)
        {
            myMap[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            int lookup = target - nums[i];
            auto it = myMap.find(lookup);
            if (it != myMap.end() && it->second != i)
            {
                if (i > it->second) return {it->second, i};

                return {i, it->second};
            }
        }

        return {};
    }
};