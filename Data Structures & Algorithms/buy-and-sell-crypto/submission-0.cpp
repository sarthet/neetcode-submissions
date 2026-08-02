class Solution {
public:
    int maxProfit(vector<int>& prices)
    {
        int max = 0;
        int left = 0;
        int right = 1;
        while (right < prices.size())
        {
            auto profit = prices[right] - prices[left];
            if (profit <= 0)
            {
                left = right;
            }
            else
            {
                max = std::max(max, profit);
            }
            right++;
        }

        return max;
    }
};

// V. V
// 10 1 5 6 7 1

