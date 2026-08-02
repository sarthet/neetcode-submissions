class Solution {
public:
    vector<int> replaceElements(vector<int>& arr)
    {
        for (int i = 0; i < arr.size(); i++)
        {
            int max = -1;
            for (int k = i + 1; k < arr.size(); k++)
            {
                if (max < arr[k])
                {
                    max = arr[k];
                }
            }
            arr[i] = max;
        }

        arr[arr.size() - 1] = -1;

        return arr;
    }
};