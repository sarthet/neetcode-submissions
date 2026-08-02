class Solution {
    static constexpr char space = '#';
public:

    string encode(vector<string>& strs)
    {
        string result;
        for (auto& str : strs)
        {
            result += to_string(str.length()) + space;
            for (auto ch : str)
            {
                result += ch;
            }
        }

        return result;
    }

    vector<string> decode(string s)
    {
        vector<string> result;
        cout << s << endl;

        for (int i = 0; i < s.length();)
        {
            // std::stoi( str )
            // 10#aaaaaaaaaa
            int begin = i;
            while (s[++i] != space);
            int currLength = std::stoi( s.substr(begin, i - begin) );
            string current = s.substr(i + 1, currLength);
            result.push_back(current);
            i += currLength + 1;
        }

        return result;
    }
};
