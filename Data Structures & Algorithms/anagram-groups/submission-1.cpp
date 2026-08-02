class Solution
{
    bool isAnagrams(string& str1, string& str2)
    {
        if (str1.size() != str2.size()) return false;

        unordered_map<char, int> letters;

        for (auto ch : str1)
        {
            letters[ch]++;
        }

        for (auto ch : str2)
        {
            auto it = letters.find(ch);
            if (it != letters.end())
            {
                if (--it->second == 0) letters.erase(it);
            }
            else
            {
                return false;
            }
        }

        return letters.empty();
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        if (strs.size() == 1) return {strs};

        vector<vector<string>> result;
        vector<bool> visited(strs.size(), false);

        for (int i = 0; i < strs.size(); i++)
        {
            if (visited[i]) continue;
            vector<string> round;
            round.push_back(strs[i]);

            visited[i] = true;

            for (int j = i + 1; j < strs.size(); j++)
            {
                if (isAnagrams(strs[i], strs[j]))
                {
                    visited[j] = true;
                    round.push_back(strs[j]);
                }
            }

            result.push_back(round);
        }

        return result;
    }
};
