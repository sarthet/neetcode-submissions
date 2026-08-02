class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.size()) return 0;

        int left = 0;
        int right = 0;

        int maxValue = 0;
        unordered_set<char> letters;
        while (right < s.size())
        {
            while (right < s.size() && !letters.count(s[right]))
            {
                letters.insert(s[right]);
                right++;
            }

            maxValue = std::max(right - left, maxValue);

            letters.erase(s[left]);
            left++;
        }

        return maxValue;
    }
};


// zxyzxyz

// 