class Solution {
    int calculateArea(vector<int>& heights, int left, int right)
    {
        return min(heights[left], heights[right]) * (right - left);
    }
public:
    int maxArea(vector<int>& heights)
    {
        int left = 0;
        int right = heights.size() - 1;
        int maximum = -1;

        while (left < right)
        {
            maximum = std::max(maximum, calculateArea(heights, left, right));
            if (heights[left] <= heights[right]) left++;
            else if (heights[left] > heights[right]) right--;
        }

        return maximum;
    }
};
