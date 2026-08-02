class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> res(nums);

        res.resize(size * 2);

        for (int i = size; i < size * 2; i++)
        {
            res[i] = res[i - size];
        }

        return res;
    }
};