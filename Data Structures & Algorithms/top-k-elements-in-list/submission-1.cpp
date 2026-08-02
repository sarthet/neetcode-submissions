class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        unordered_map<int, int> counts;
        for (auto num : nums)
        {
            counts[num]++;
        }

        vector<vector<int>> hz(nums.size() + 1);
        for (auto& [num, freq] : counts)
        {
            hz[freq].push_back(num);
        }

        vector<int> result;
        for (int i = hz.size() - 1; i > 0; i--)
        {
            for (int n : hz[i])
            {
                result.push_back(n);
                if (result.size() == k)
                {
                    return result;
                }
            }
        }
        return result;
    }
};
