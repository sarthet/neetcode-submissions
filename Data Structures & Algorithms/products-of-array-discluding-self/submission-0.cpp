class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        int size = nums.size();
        vector<int> product(size, 1);
        vector<int> result(size);

        for (int i = 1; i < size; i++)
        {
            product[i] = product[i - 1] * nums[i - 1];
        }

        int reverseProduct = 1;
        for (int i = size - 1; i >= 0; i--)
        {
            result[i] = product[i] * reverseProduct;
            reverseProduct = reverseProduct * nums[i];
        }

        return result;
    }
};


// ->>
// 1 1 2 8
// <<-
// 48 24 6 1


// ->>
// 1 -1 0 0 0
// <--
// 0 6 6 3 1
