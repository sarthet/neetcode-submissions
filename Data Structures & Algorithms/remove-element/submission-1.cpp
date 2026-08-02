class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int lp = 0;
        int rp = nums.size() - 1;
        // [1]
        while (lp <= rp)
        {
            if (nums[lp] == val)
            { 
                if (nums[rp] != val)
                {
                    nums[lp] = nums[rp];
                    rp--;
                    lp++;
                }
                else
                {
                    rp--;
                }
            }
            else
            {
                lp++;
            }
        }
        return lp;
    }
};