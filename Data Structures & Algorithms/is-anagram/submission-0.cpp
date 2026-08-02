class Solution {
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> letters;

        for (auto c : s)
        {
            letters[c]++;
        }

        for (auto c : t)
        {
            auto it = letters.find(c);
            if (it == letters.end())
            {
                return false;
            }
            else
            {
                it->second--;
                if (it->second == 0) letters.erase(it);
            }
        }

        return letters.empty();
    }
};
