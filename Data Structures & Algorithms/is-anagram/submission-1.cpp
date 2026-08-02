class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;

        vector<int> letters(26, 0);

        for (auto c : s)
        {
            letters[c - 'a']++;
        }

        for (auto c : t)
        {
            letters[c - 'a']--;
            if (letters[c - 'a'] < 0) return false;
        }

        bool valid = true;
        for_each(letters.begin(), letters.end(), [&valid](int count) {
            if (count != 0) valid = false;
        });

        return valid;
    }
};
