class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        int maxValue = -1;
        int tmp;

        for (int i = arr.size() - 1; i >= 0; i--)
        {
            tmp = arr[i];
            arr[i] = maxValue;
            maxValue = std::max(maxValue, tmp);
        }

        return arr;
    }
};